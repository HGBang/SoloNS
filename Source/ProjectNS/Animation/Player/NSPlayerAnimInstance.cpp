// Copyright Project NS


#include "NSPlayerAnimInstance.h"
#include "../../Character/NSCharacter.h"
#include "../../CombatSystem/System/NSAbilityComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSPlayerAnimInstance)

UNSPlayerAnimInstance::UNSPlayerAnimInstance() : 
	Super(),
	AnimType(EPlayerAnimationType::IdleAndJog)
{
}

void UNSPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UNSPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UNSPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}

void UNSPlayerAnimInstance::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();
}

void UNSPlayerAnimInstance::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();
}

void UNSPlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UNSPlayerAnimInstance::ChangeAnimType_Hit()
{
	AnimType = EPlayerAnimationType::HitAttack;
}

void UNSPlayerAnimInstance::ChangeAnimType_Die()
{
}


