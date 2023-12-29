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


	UE_LOGFMT(NS_Log, Log, "ANSPlayerCharacter(ObjectInitializer) 생성자");
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

	// Player용 MainWidget 생성
	if (IsValid(PlayerMainWidgetClass))
	{
		PlayerMainWidget = CreateWidget<UPlayerMainWidget>(GetController<APlayerController>(), PlayerMainWidgetClass);
		PlayerMainWidget->Init();
		PlayerMainWidget->AddToViewport();

		// 만들어진 MainWidget에서 CharacterSheet 컨트롤을 위해 CharacterSheetComponent에 ChracterSheetWidget 전달
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
	// 자신의 턴이 아니면 업데이트하지 않는다.
	// 캐릭터가 움직일때는 업데이트를 멈춘다.
	if (!bTurn || GetVelocity().Size() > 0.0f)
	{
		// 모든 SplineMeshComponent 제거
		for (const auto& SplineMesh : SplineMeshes)
			SplineMesh->DestroyComponent();

		SplineMeshes.Empty();

		return;
	}

	// 목적지가 거의 비슷하면 PathSpline을 업데이트 하지 않는다.
	if (FVector::Distance(CachedDestinationPoint, DestinationPoint) < 50.0f) return;

	CachedDestinationPoint = DestinationPoint;

	UNavigationPath* NavPath;

	FVector PathStartPoint = GetActorLocation();
	PathStartPoint.Z -= GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

	NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(GetWorld(), PathStartPoint, CachedDestinationPoint);

	// 먼저 모든 포인트를 날려준다.
	PathSpline->ClearSplinePoints();

	// Navigation Path의 Point들을 Spline Point에 추가한다.
	for (const FVector& Point : NavPath->PathPoints)
	{
		PathSpline->AddSplinePoint(Point, ESplineCoordinateSpace::World);
	}

	// 모든 SplineMeshComponent 제거
	for (const auto& SplineMesh : SplineMeshes)
		SplineMesh->DestroyComponent();

	SplineMeshes.Empty();

	int32 CreatingMeshCount = FMath::TruncToInt(PathSpline->GetSplineLength() / PathMeshLength);
	for (int32 i = 0; i < CreatingMeshCount; ++i)
	{
		// 홀수번째는 스킵
		if (i % 2 != 0)	continue;

		USplineMeshComponent* SplineMeshComp = NewObject<USplineMeshComponent>(this, USplineMeshComponent::StaticClass());
		SplineMeshComp->SetMobility(EComponentMobility::Movable);
		// 월드에 등록
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
