// Copyright Project NS


#include "NSAbility_Kraken_LightningStorm.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Kraken_LightningStorm)

UNSAbility_Kraken_LightningStorm::UNSAbility_Kraken_LightningStorm() :
	Super()
{
}

void UNSAbility_Kraken_LightningStorm::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);
}

void UNSAbility_Kraken_LightningStorm::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Kraken_LightningStorm::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Kraken_LightningStorm::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Kraken_LightningStorm::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
