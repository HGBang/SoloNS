// Copyright Project NS


#include "NSAbility_Kraken_BiteAttack.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Kraken_BiteAttack)

UNSAbility_Kraken_BiteAttack::UNSAbility_Kraken_BiteAttack() :
	Super()
{
}

void UNSAbility_Kraken_BiteAttack::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);
}

void UNSAbility_Kraken_BiteAttack::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Kraken_BiteAttack::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Kraken_BiteAttack::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Kraken_BiteAttack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
