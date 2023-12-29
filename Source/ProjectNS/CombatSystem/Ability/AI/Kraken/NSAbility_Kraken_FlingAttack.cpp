// Copyright Project NS


#include "NSAbility_Kraken_FlingAttack.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Kraken_FlingAttack)

UNSAbility_Kraken_FlingAttack::UNSAbility_Kraken_FlingAttack() :
	Super()
{
}

void UNSAbility_Kraken_FlingAttack::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);
}

void UNSAbility_Kraken_FlingAttack::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Kraken_FlingAttack::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Kraken_FlingAttack::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Kraken_FlingAttack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
