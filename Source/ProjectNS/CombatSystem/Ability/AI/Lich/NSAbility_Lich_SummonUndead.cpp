// Copyright Project NS


#include "NSAbility_Lich_SummonUndead.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Lich_SummonUndead)

UNSAbility_Lich_SummonUndead::UNSAbility_Lich_SummonUndead() :
	Super()
{
}

void UNSAbility_Lich_SummonUndead::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);
}

void UNSAbility_Lich_SummonUndead::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Lich_SummonUndead::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Lich_SummonUndead::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Lich_SummonUndead::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
