// Copyright Project NS


#include "NSPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "../Interface/OutLineInterface.h"
#include "../Character/Player/NSPlayerCharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSPlayerController)

ANSPlayerController::ANSPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ANSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// IMC를 등록하지 않으면 crash!
	checkf(NSIMC, TEXT("ANSTestController::BeginPlay : NSIMC is not valid"));

	// EnhancedInput IMC 등록
	if (UEnhancedInputLocalPlayerSubsystem* EISubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		EISubsystem->AddMappingContext(NSIMC, 0);

	// 기본 입력세팅
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ANSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Input Action Binding
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Mouse
		if (IsValid(LeftClickAction))
		{
			EnhancedInputComponent->BindAction(LeftClickAction, ETriggerEvent::Started, this, &ThisClass::OnLeftClickStarted);
			EnhancedInputComponent->BindAction(LeftClickAction, ETriggerEvent::Triggered, this, &ThisClass::OnLeftClickTriggered);
			EnhancedInputComponent->BindAction(LeftClickAction, ETriggerEvent::Completed, this, &ThisClass::OnLeftClickCompleted);
			EnhancedInputComponent->BindAction(LeftClickAction, ETriggerEvent::Canceled, this, &ThisClass::OnLeftClickCompleted);
		}

		if (IsValid(LeftClickAction))
		{
			EnhancedInputComponent->BindAction(RightClickAction, ETriggerEvent::Started, this, &ThisClass::OnMouseRightStarted);
			EnhancedInputComponent->BindAction(RightClickAction, ETriggerEvent::Completed, this, &ThisClass::OnMouseRightReleased);
		}

		if (IsValid(WheelScrollAction))
			EnhancedInputComponent->BindAction(WheelScrollAction, ETriggerEvent::Triggered, this, &ThisClass::OnMouseWheelScroll);

		if (IsValid(WheelClickAction))
			EnhancedInputComponent->BindAction(WheelClickAction, ETriggerEvent::Completed, this, &ThisClass::OnMouseWheelClick);


		// Keyboard
		if (IsValid(QAction))
			EnhancedInputComponent->BindAction(QAction, ETriggerEvent::Triggered, this, &ThisClass::OnQTriggered);

		if (IsValid(EAction))
			EnhancedInputComponent->BindAction(EAction, ETriggerEvent::Triggered, this, &ThisClass::OnETriggered);

		if (IsValid(WAction))
			EnhancedInputComponent->BindAction(WAction, ETriggerEvent::Triggered, this, &ThisClass::OnWTriggered);

		if (IsValid(AAction))
			EnhancedInputComponent->BindAction(AAction, ETriggerEvent::Triggered, this, &ThisClass::OnATriggered);

		if (IsValid(SAction))
			EnhancedInputComponent->BindAction(SAction, ETriggerEvent::Triggered, this, &ThisClass::OnSTriggered);

		if (IsValid(DAction))
			EnhancedInputComponent->BindAction(DAction, ETriggerEvent::Triggered, this, &ThisClass::OnDTriggered);

		if (IsValid(IAction))
			EnhancedInputComponent->BindAction(IAction, ETriggerEvent::Started, this, &ThisClass::OnIStarted);

		if (IsValid(KAction))
			EnhancedInputComponent->BindAction(KAction, ETriggerEvent::Started, this, &ThisClass::OnKStarted);

		if (IsValid(ESCAction))
			EnhancedInputComponent->BindAction(ESCAction, ETriggerEvent::Started, this, &ThisClass::OnESCStarted);

	}
}

void ANSPlayerController::TraceCursor()
{
	// 커서 아래에 trace된 것이 하나도 없다면 return
	if (!GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, CursorHitResult)) return; // TODO: 현재 CollisionChannel을 Visibility로 설정했지만, 맵이나 길만 찍을 수 있다면 채널을 설정해야함.

	// LastHitActor 갱신
	LastHitActor = CurrentHitActor;

	// Trace된 Actor가 OutlineInterface를 상속받고 있다면 캐싱하고, 아니라면 null
	if (IsValid(CursorHitResult.GetActor()) && CursorHitResult.GetActor()->Implements<UOutLineInterface>())
		CurrentHitActor = CursorHitResult.GetActor();
	else
		CurrentHitActor = nullptr;

	// 최근 Trace된 Actor가 다르다면 대상이 변경되었으므로 On/Off
	if (CurrentHitActor != LastHitActor)
	{
		TurnOnOutlineActor(CurrentHitActor);
		TurnOffOutlineActor(LastHitActor);
	}
}

void ANSPlayerController::TurnOnOutlineActor(AActor* InActor)
{
	if (IsValid(InActor) && InActor->Implements<UOutLineInterface>())
		IOutLineInterface::Execute_TurnOnOutline(InActor);
}

void ANSPlayerController::TurnOffOutlineActor(AActor* InActor)
{
	if (IsValid(InActor) && InActor->Implements<UOutLineInterface>())
		IOutLineInterface::Execute_TurnOffOutline(InActor);
}

void ANSPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// 매 틱마다 화면에서 커서위치에 무엇이 있는지 확인
	TraceCursor();

	// 스플라인 테스트
	if (ANSPlayerCharacter* PlayerCharacter = GetPawn<ANSPlayerCharacter>())
	{
		if (CursorHitResult.bBlockingHit)
			PlayerCharacter->ShowPathSpline(CursorHitResult.Location);
	}
}

void ANSPlayerController::OnLeftClickStarted(const FInputActionValue& Value)
{
	// 일단 클릭되면 새로운 경로 탐색을 위해 멈춤
	StopMovement();
}

void ANSPlayerController::OnLeftClickTriggered(const FInputActionValue& Value)
{
	// 마우스 클릭된 위치로 이동
	if (CursorHitResult.bBlockingHit)
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CursorHitResult.Location);
}

void ANSPlayerController::OnLeftClickCompleted(const FInputActionValue& Value)
{
	// 마우스 클릭된 위치로 이동
	if (CursorHitResult.bBlockingHit)
	{	
		if (IsValid(FXCursor))
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CursorHitResult.Location, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}
}

void ANSPlayerController::OnMouseWheelScroll(const FInputActionValue& Value)
{
	ANSPlayerCharacter* PlayerCharacter = GetPawn<ANSPlayerCharacter>();

	if (IsValid(PlayerCharacter)) 
		PlayerCharacter->ZoomCamera(Value.Get<float>());
}

void ANSPlayerController::OnMouseWheelClick(const FInputActionValue& Value)
{
	ANSPlayerCharacter* PlayerCharacter = GetPawn<ANSPlayerCharacter>();

	if (IsValid(PlayerCharacter))
		PlayerCharacter->SetAlignmentCamera();
}

void ANSPlayerController::OnMouseRightStarted(const FInputActionValue& Value)
{
}

void ANSPlayerController::OnMouseRightReleased(const FInputActionValue& Value)
{
}

void ANSPlayerController::OnQTriggered(const FInputActionValue& Value)
{
	ANSPlayerCharacter* PlayerCharacter = GetPawn<ANSPlayerCharacter>();

	if (IsValid(PlayerCharacter))
		PlayerCharacter->RotationCamera(-1);
}

void ANSPlayerController::OnETriggered(const FInputActionValue& Value)
{
	ANSPlayerCharacter* PlayerCharacter = GetPawn<ANSPlayerCharacter>();

	if (IsValid(PlayerCharacter))
		PlayerCharacter->RotationCamera(1);
}

void ANSPlayerController::OnWTriggered(const FInputActionValue& Value)
{
}

void ANSPlayerController::OnATriggered(const FInputActionValue& Value)
{
}

void ANSPlayerController::OnSTriggered(const FInputActionValue& Value)
{
}

void ANSPlayerController::OnDTriggered(const FInputActionValue& Value)
{
}

void ANSPlayerController::OnIStarted(const FInputActionValue& Value)
{
}

void ANSPlayerController::OnKStarted(const FInputActionValue& Value)
{
}

void ANSPlayerController::OnESCStarted(const FInputActionValue& Value)
{
}

void ANSPlayerController::TurnEnd()
{
	ANSPlayerCharacter* PlayerCharacter = GetPawn<ANSPlayerCharacter>();

	if (IsValid(PlayerCharacter))
		PlayerCharacter->CharacterTurnEnd();
}
