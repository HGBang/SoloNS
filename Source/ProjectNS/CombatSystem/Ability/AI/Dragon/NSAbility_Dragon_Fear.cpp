// Copyright Project NS


#include "NSAbility_Dragon_Fear.h"
#include "../../../../CombatSystem/System/NSGameAbility.h"
#include "../../../../CombatSystem/System/NSAbilityComponent.h"
#include "../../../../CombatSystem/GamePlayEffect/NSGamePlayEffect.h"
#include "../../../../Animation/AI/Castle/NSDragonAnimInst.h"
#include "../../../../Character/AI/Class/NSDragonAICharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Dragon_Fear)

UNSAbility_Dragon_Fear::UNSAbility_Dragon_Fear() :
	Super()
{
}

void UNSAbility_Dragon_Fear::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);

	UNSDragonAnimInst* DragonAnim = Cast<UNSDragonAnimInst>(AnimInstance);

	if (IsValid(DragonAnim))
	{
		DragonAnim->SetAnimType(EDragonAnimType::Attack_Bite);

		ANSDragonAICharacter* OwnerCharacter = Cast<ANSDragonAICharacter>(OwnerComp->GetOwner());

		if (IsValid(OwnerCharacter))
			OwnerCharacter->Action_Fear();
	}
}

void UNSAbility_Dragon_Fear::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Dragon_Fear::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Dragon_Fear::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Dragon_Fear::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
