// Copyright Project NS


#include "NSBarghestAnimInst.h"
#include "../../../Character/NSCharacter.h"
#include "../../../CombatSystem/AttributeSet/NSCharacterAttributeSet.h"
#include "../../../CombatSystem/System/NSAbilityComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSBarghestAnimInst)

UNSBarghestAnimInst::UNSBarghestAnimInst() :
	Super(),
	AnimType(EBarghestAnimType::IdleAndWalk_Normal)
{
}

void UNSBarghestAnimInst::ChangeAnimType_Hit()
{
	AnimType = EBarghestAnimType::Hit_Front;

	ANSCharacter* TestCharacter = Cast<ANSCharacter>(TryGetPawnOwner());

	if (IsValid(TestCharacter))
	{
		UNSCharacterAttributeSet* Attr = Cast<UNSCharacterAttributeSet>(TestCharacter->GetAbilityComponent()->GetAttributeSet());

		float Hp = Attr->GetCharacterAttributeValue(ECharacterAttributeType::Hp);

		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Hp: %f"), Hp));

		if (Hp <= 0.f)
		{
			AnimType = EBarghestAnimType::Die;

			TestCharacter->Death();
		
		}
	}


}

void UNSBarghestAnimInst::AnimNotify_HitAttack()
{

}

void UNSBarghestAnimInst::AnimNotify_HitRecovery()
{
	AnimType = EBarghestAnimType::IdleAndRun_Battle;
}

void UNSBarghestAnimInst::AnimNotify_MeleeAttackEnd()
{
	AnimType = EBarghestAnimType::IdleAndWalk_Normal;

	ANSCharacter* TestCharacter = Cast<ANSCharacter>(TryGetPawnOwner());

	if (IsValid(TestCharacter))
		TestCharacter->CharacterTurnEnd();
}
