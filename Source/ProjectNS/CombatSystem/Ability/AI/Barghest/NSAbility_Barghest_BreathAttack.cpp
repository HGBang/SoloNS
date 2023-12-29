// Copyright Project NS


#include "NSAbility_Barghest_BreathAttack.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Barghest_BreathAttack)

UNSAbility_Barghest_BreathAttack::UNSAbility_Barghest_BreathAttack() :
	Super()
{
}

void UNSAbility_Barghest_BreathAttack::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);
}

void UNSAbility_Barghest_BreathAttack::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Barghest_BreathAttack::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Barghest_BreathAttack::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Barghest_BreathAttack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
