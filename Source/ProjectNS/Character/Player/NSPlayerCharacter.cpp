// Copyright Project NS


#include "NSPlayerCharacter.h"
#include "Components/SplineComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "Components/SplineMeshComponent.h"
#include "../../Component/CharacterSheetComponent.h"
#include "../../UI/Widget/PlayerMainWidget.h"
#include "../../CombatSystem/AttributeSet/NSCharacterAttributeSet.h"
#include "../../CombatSystem/AttributeSet/NSAttributeSet.h"
#include "../../CombatSystem/System/NSAbilityComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSPlayerCharacter)

ANSPlayerCharacter::ANSPlayerCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, PathMeshLength(100.0f)
	, CachedDestinationPoint(FVector::ZeroVector)
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->TargetArmLength = BASE_CAMERA_ZOOM;
	SpringArm->SetRelativeRotation(FRotator(-50.0, 0.0, 0.0));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	SpringArm->bInheritYaw = false;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
   

	PathSpline = CreateDefaultSubobject<USplineComponent>(TEXT("PathSpline"));

	CharacterSheet = CreateDefaultSubobject<UCharacterSheetComponent>(TEXT("CharacterSheet"));


	UE_LOGFMT(NS_Log, Log, "ANSPlayerCharacter(ObjectInitializer) ������");
}

void ANSPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	const FDetachmentTransformRules DetachmentRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, true);
	PathSpline->DetachFromComponent(DetachmentRules);
	PathSpline->ClearSplinePoints();

	if (IsValid(PathMesh))
		PathMeshLength = PathMesh->GetBoundingBox().GetExtent().Y;
	else
		UE_LOG(NS_Log, Log, TEXT("PathMesh is not valid!"));

	// Player�� MainWidget ����
	if (IsValid(PlayerMainWidgetClass))
	{
		PlayerMainWidget = CreateWidget<UPlayerMainWidget>(GetController<APlayerController>(), PlayerMainWidgetClass);
		PlayerMainWidget->Init();
		PlayerMainWidget->AddToViewport();

		// ������� MainWidget���� CharacterSheet ��Ʈ���� ���� CharacterSheetComponent�� ChracterSheetWidget ����
		CharacterSheet->SetCharacterSheetWidget(PlayerMainWidget->GetCharacterSheetWidget());
	}
	else
		UE_LOG(NS_Log, Log, TEXT("PlayerMainWidgetClass is not valid!"));
}

void ANSPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANSPlayerCharacter::PlayTurn(const float& DiceValue)
{
	Super::PlayTurn(DiceValue);
}

void ANSPlayerCharacter::CharacterTurnEnd()
{
	Super::CharacterTurnEnd();
}

void ANSPlayerCharacter::ShowPathSpline(const FVector& DestinationPoint)
{
	// �ڽ��� ���� �ƴϸ� ������Ʈ���� �ʴ´�.
	// ĳ���Ͱ� �����϶��� ������Ʈ�� �����.
	if (!bTurn || GetVelocity().Size() > 0.0f)
	{
		// ��� SplineMeshComponent ����
		for (const auto& SplineMesh : SplineMeshes)
			SplineMesh->DestroyComponent();

		SplineMeshes.Empty();

		return;
	}

	// �������� ���� ����ϸ� PathSpline�� ������Ʈ ���� �ʴ´�.
	if (FVector::Distance(CachedDestinationPoint, DestinationPoint) < 50.0f) return;

	CachedDestinationPoint = DestinationPoint;

	UNavigationPath* NavPath;

	FVector PathStartPoint = GetActorLocation();
	PathStartPoint.Z -= GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

	NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(GetWorld(), PathStartPoint, CachedDestinationPoint);

	// ���� ��� ����Ʈ�� �����ش�.
	PathSpline->ClearSplinePoints();

	// Navigation Path�� Point���� Spline Point�� �߰��Ѵ�.
	for (const FVector& Point : NavPath->PathPoints)
	{
		PathSpline->AddSplinePoint(Point, ESplineCoordinateSpace::World);
	}

	// ��� SplineMeshComponent ����
	for (const auto& SplineMesh : SplineMeshes)
		SplineMesh->DestroyComponent();

	SplineMeshes.Empty();

	int32 CreatingMeshCount = FMath::TruncToInt(PathSpline->GetSplineLength() / PathMeshLength);
	for (int32 i = 0; i < CreatingMeshCount; ++i)
	{
		// Ȧ����°�� ��ŵ
		if (i % 2 != 0)	continue;

		USplineMeshComponent* SplineMeshComp = NewObject<USplineMeshComponent>(this, USplineMeshComponent::StaticClass());
		SplineMeshComp->SetMobility(EComponentMobility::Movable);
		// ���忡 ���
		SplineMeshComp->RegisterComponentWithWorld(GetWorld());
		SplineMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SplineMeshComp->SetForwardAxis(ESplineMeshAxis::Y);
		SplineMeshComp->SetStaticMesh(PathMesh);

		const FDetachmentTransformRules DetachmentRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, true);
		SplineMeshComp->DetachFromComponent(DetachmentRules);

		const FVector SplineMeshStartPos = PathSpline->GetLocationAtDistanceAlongSpline(i * PathMeshLength, ESplineCoordinateSpace::World);
		FVector SplinemeshStartTangent = PathSpline->GetTangentAtDistanceAlongSpline(i * PathMeshLength, ESplineCoordinateSpace::World);
		SplinemeshStartTangent = UKismetMathLibrary::ClampVectorSize(SplinemeshStartTangent, 0.0f, PathMeshLength);

		const FVector SplineMeshEndPos = PathSpline->GetLocationAtDistanceAlongSpline((i + 1) * PathMeshLength, ESplineCoordinateSpace::World);
		FVector SplinemeshEndTangent = PathSpline->GetTangentAtDistanceAlongSpline((i + 1) * PathMeshLength, ESplineCoordinateSpace::World);
		SplinemeshEndTangent = UKismetMathLibrary::ClampVectorSize(SplinemeshEndTangent, 0.0f, PathMeshLength);

		SplineMeshComp->SetStartAndEnd(SplineMeshStartPos, SplinemeshStartTangent, SplineMeshEndPos, SplinemeshEndTangent);

		SplineMeshes.Add(SplineMeshComp);
	}
}

void ANSPlayerCharacter::CalculateAccuracy(ANSCharacter* Target)
{
	int32 DiceValue = FMath::RandRange(1, 20);

	UNSCharacterAttributeSet* OwnerAttributeSet = Cast<UNSCharacterAttributeSet>(AbilityComponent->GetAttributeSet());

	float Accuracy = OwnerAttributeSet->GetCharacterAttributeValue(ECharacterAttributeType::Accuracy) + DiceValue;

	UNSAbilityComponent* TargetAbilityComp = Target->GetAbilityComponent();

	UNSCharacterAttributeSet* TargetAttributeSet = Cast<UNSCharacterAttributeSet>(TargetAbilityComp->GetAttributeSet());

	float CompareAC = TargetAttributeSet->GetCharacterAttributeValue(ECharacterAttributeType::ArmorCount);

	if (Accuracy >= CompareAC)
		bIsAccuracy = true;	
}

void ANSPlayerCharacter::ZoomCamera(float Degree)
{
	float ArmLength = SpringArm->TargetArmLength;

	UE_LOGFMT(NS_Log, Log, "{Func} : {Arm} / {Degree}", __FUNCTION__, ArmLength, Degree);

	if(ArmLength >= MIN_CAMERA_ZOOM && ArmLength <= MAX_CAMERA_ZOOM)
		SpringArm->TargetArmLength = ArmLength + ZOOM_DEGREE * Degree;

	if (SpringArm->TargetArmLength < MIN_CAMERA_ZOOM)
		SpringArm->TargetArmLength = MIN_CAMERA_ZOOM;

	if (SpringArm->TargetArmLength > MAX_CAMERA_ZOOM)
		SpringArm->TargetArmLength = MAX_CAMERA_ZOOM;
}

void ANSPlayerCharacter::SetAlignmentCamera()
{
	SpringArm->TargetArmLength = BASE_CAMERA_ZOOM;
	SpringArm->SetWorldRotation(FRotator(-50.0, 0.0, 0.0));
}

void ANSPlayerCharacter::RotationCamera(float Degree)
{
	FRotator Rotaion = SpringArm->GetComponentRotation();

	Rotaion.Yaw += Degree * ROTATION_DEGREE;

	SpringArm->SetWorldRotation(Rotaion);
}
