// Copyright Project NS


#include "NSAbility_Dragon_WingAttack.h"
#include "../../../../CombatSystem/System/NSGameAbility.h"
#include "../../../../CombatSystem/System/NSAbilityComponent.h"
#include "../../../../CombatSystem/GamePlayEffect/NSGamePlayEffect.h"
#include "../../../../Animation/AI/Castle/NSDragonAnimInst.h"
#include "../../../../Character/AI/Class/NSDragonAICharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Dragon_WingAttack)

UNSAbility_Dragon_WingAttack::UNSAbility_Dragon_WingAttack() :
	Super()
{
}

void UNSAbility_Dragon_WingAttack::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);

	//if (IsValid(DragonAnim))
	//{
	//	DragonAnim->SetAnimType(EDragonAnimType::Attack_Bite);

	//	ANSDragonAICharacter* OwnerCharacter = Cast<ANSDragonAICharacter>(OwnerComp->GetOwner());

	//	if (IsValid(OwnerCharacter))
	//		OwnerCharacter->Action();
	//}
}

void UNSAbility_Dragon_WingAttack::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Dragon_WingAttack::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Dragon_WingAttack::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Dragon_WingAttack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
