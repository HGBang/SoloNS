// Copyright Project NS


#include "NSWarriorAnimInst.h"
#include "../../../Character/NSCharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSWarriorAnimInst)

UNSWarriorAnimInst::UNSWarriorAnimInst() :
	Super()
{
	AnimType = EPlayerAnimationType::IdleAndJog;
}

void UNSWarriorAnimInst::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UNSWarriorAnimInst::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UNSWarriorAnimInst::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}

void UNSWarriorAnimInst::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();
}

void UNSWarriorAnimInst::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();
}

void UNSWarriorAnimInst::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UNSWarriorAnimInst::AnimNotify_ActiveAttackCollider()
{
	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(TryGetPawnOwner());
	OwnerCharacter->ActivatedCollision();
}

void UNSWarriorAnimInst::AnimNotify_DeActiveAttackCollider()
{
	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(TryGetPawnOwner());
	OwnerCharacter->DeActivatedCollision();
}

void UNSWarriorAnimInst::AnimNotify_MeleeAttackEnd()
{
	AnimType = EPlayerAnimationType::IdleAndJog;

	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(TryGetPawnOwner());

	if (IsValid(OwnerCharacter))
		OwnerCharacter->CharacterTurnEnd();
}
