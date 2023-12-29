// Copyright Project NS


#include "NSAbility_Skeleton_MeleeAttack.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Skeleton_MeleeAttack)

UNSAbility_Skeleton_MeleeAttack::UNSAbility_Skeleton_MeleeAttack() :
	Super()
{
}

void UNSAbility_Skeleton_MeleeAttack::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);
}

void UNSAbility_Skeleton_MeleeAttack::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Skeleton_MeleeAttack::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Skeleton_MeleeAttack::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Skeleton_MeleeAttack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
