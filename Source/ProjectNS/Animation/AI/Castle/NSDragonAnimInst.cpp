// Copyright Project NS

#include "NSDragonAnimInst.h"
#include "../../../Character/NSCharacter.h"
#include "../../../CombatSystem/AttributeSet/NSCharacterAttributeSet.h"
#include "../../../CombatSystem/System/NSAbilityComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSDragonAnimInst)

UNSDragonAnimInst::UNSDragonAnimInst() :
	Super(),
	AnimType(EDragonAnimType::IdleAndWalk_Normal)
{
}

void UNSDragonAnimInst::ChangeAnimType_Hit()
{
	Super::ChangeAnimType_Hit();

	AnimType = EDragonAnimType::Hit_Front;
}

void UNSDragonAnimInst::ChangeAnimType_Die()
{
	Super::ChangeAnimType_Die();

	AnimType = EDragonAnimType::Die;
}

void UNSDragonAnimInst::AnimNotify_MeleeAttackEnd()
{
	AnimType = EDragonAnimType::IdleAndWalk_Normal;

	ANSCharacter* TestCharacter = Cast<ANSCharacter>(TryGetPawnOwner());

	if (IsValid(TestCharacter))
		TestCharacter->CharacterTurnEnd();
}

void UNSDragonAnimInst::AnimNotify_BreathEnd()
{
	AnimType = EDragonAnimType::IdleAndWalk_Normal;

	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(TryGetPawnOwner());

	if (IsValid(OwnerCharacter))
		OwnerCharacter->CharacterTurnEnd();
}

void UNSDragonAnimInst::AnimNotify_FlyingAttack()
{
	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(TryGetPawnOwner());

	if (IsValid(OwnerCharacter))
	{
		UNSAbilityComponent* OwnerComp = OwnerCharacter->GetAbilityComponent();

		if (IsValid(OwnerComp))
			OwnerComp->ActivatedAbilityEvent(TEXT("FlyingAttack"), OwnerCharacter, nullptr);
	}
}

void UNSDragonAnimInst::AnimNotify_FlyingAttackEnd()
{
	AnimType = EDragonAnimType::IdleAndWalk_Normal;

	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(TryGetPawnOwner());

	if (IsValid(OwnerCharacter))
		OwnerCharacter->CharacterTurnEnd();
}

void UNSDragonAnimInst::AnimNotify_ScratchAttackEnd()
{
	AnimType = EDragonAnimType::IdleAndWalk_Normal;

	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(TryGetPawnOwner());

	if (IsValid(OwnerCharacter))
		OwnerCharacter->CharacterTurnEnd();
}
