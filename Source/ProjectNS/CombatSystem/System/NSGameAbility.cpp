// Fill out your copyright notice in the Description page of Project Settings.


#include "NSGameAbility.h"
#include "../../Animation/NSAnimInstance.h"
#include "../../Character/NSCharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSGameAbility)

UNSGameAbility::UNSGameAbility() :
	Super()
{
	
}

const FName& UNSGameAbility::GetAbilityName() const
{
	return AbilityName;
}

const bool& UNSGameAbility::GetAbilityTickEnable() const
{
	return bTick;
}

void UNSGameAbility::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
}

void UNSGameAbility::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
}

void UNSGameAbility::EndAbility(UNSAbilityComponent* OwnerComp)
{
}

void UNSGameAbility::TickAbility(float DeltaSeconds)
{
}

void UNSGameAbility::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, AbilityName);
	DOREPLIFETIME(ThisClass, bTick);
	DOREPLIFETIME(ThisClass, GamePlayEffect);
	DOREPLIFETIME(ThisClass, bAbilityEnable);

}
