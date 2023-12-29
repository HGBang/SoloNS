// Copyright Project NS


#include "NSAbility_Kraken_Tentacle.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Kraken_Tentacle)

UNSAbility_Kraken_Tentacle::UNSAbility_Kraken_Tentacle() :
	Super()
{
}

void UNSAbility_Kraken_Tentacle::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);
}

void UNSAbility_Kraken_Tentacle::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Kraken_Tentacle::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Kraken_Tentacle::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Kraken_Tentacle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
