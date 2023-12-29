// Fill out your copyright notice in the Description page of Project Settings.


#include "NSAnimInstance.h"
#include "../Character/NSCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAnimInstance)

UNSAnimInstance::UNSAnimInstance() :
	Super(),
	bIsAccelarating(false),
	Speed(0.f),
	CharacterRotation(FRotator(0.0f)),
	PrevCharacterRotation(FRotator(0.0f)),
	YawDelta(0.f),
	RandAttackMaxCount(3),
	RandAttack(0)
{
}

void UNSAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	Character = Cast<ANSCharacter>(TryGetPawnOwner());

	if (!IsValid(Character))
		UE_LOGFMT(NS_Log, Log, "UNSAnimInstance - Character Cast Failed");
}

void UNSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	SetAnimVariableSpeed();
	SetAnimVariableYawDelta(DeltaSeconds);
}

void UNSAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

}

void UNSAnimInstance::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();
}

void UNSAnimInstance::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();
}

void UNSAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UNSAnimInstance::ChangeAnimType_Hit()
{
}

void UNSAnimInstance::ChangeAnimType_Die()
{
}

void UNSAnimInstance::SetAnimVariableSpeed()
{
	if (IsValid(Character)) {
		FVector Velocity = Character->GetVelocity();
		Velocity.Z = 0.0;	// Z is ignored
		Speed = Velocity.Size();

		// Acceleration
		UCharacterMovementComponent* Movement = Character->GetComponentByClass<UCharacterMovementComponent>();

		if (IsValid(Movement))
			bIsAccelarating = Movement->GetCurrentAcceleration() != FVector();

		if (Speed == 0.f)
			bIsAccelarating = false;
	}
	else 
		UE_LOGFMT(NS_Log, Log, "UNSAnimInstance - Character Cast Failed / Set Speed Failed");
}

void UNSAnimInstance::SetAnimVariableYawDelta(float DeltaSeconds)
{
	if (IsValid(Character)) {
		PrevCharacterRotation = CharacterRotation;
		CharacterRotation = Character->GetActorRotation();

		const FRotator RotationDelta = UKismetMathLibrary::NormalizedDeltaRotator(CharacterRotation, PrevCharacterRotation);

		const float Target = RotationDelta.Yaw / DeltaSeconds;
		const float Interp = FMath::FInterpTo(YawDelta, Target, DeltaSeconds, 6.0f);
		YawDelta = FMath::Clamp(Interp, -90.0f, 90.0f);
	}
	else
		UE_LOGFMT(NS_Log, Log, "UNSAnimInstance - Character Cast Failed / Set YawDelta Failed");
}
