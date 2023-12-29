// Copyright Project NS


#include "NSAbility_Warrior_ChainAction.h"

UNSAbility_Warrior_ChainAction::UNSAbility_Warrior_ChainAction() : 
	Super()
{
}

void UNSAbility_Warrior_ChainAction::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);
}

void UNSAbility_Warrior_ChainAction::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Warrior_ChainAction::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Warrior_ChainAction::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Warrior_ChainAction::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
