// Fill out your copyright notice in the Description page of Project Settings.

#include "NSAttributeSet.h"
#include "../GamePlayEffect/NSGamePlayEffect.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAttributeSet)


void UNSAttributeSet::LevelUp()
{
	//구현 금지 자식클래스에서 구현할것 
}

void UNSAttributeSet::InitAttributeSet()
{
	//구현 금지 자식클래스에서 구현할것 
}

void UNSAttributeSet::UpdateAttributeSet()
{
	//구현 금지 자식클래스에서 구현할것 
}

void UNSAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, bool Negative)
{
	//구현 금지 자식클래스에서 구현할것 
}

void UNSAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, UNSAttributeSet* OtherAttributeSet, bool Negative)
{
	//구현 금지 자식클래스에서 구현할것 
}

void UNSAttributeSet::GamePlayCaculatedEffect(FGamePlayEffect& Effect, FAttribute& Attribute, float Value, bool Negative)
{
	//구현 금지 자식클래스에서 구현할것 
}

void UNSAttributeSet::DurationEffect(ECharacterAttributeType Type, float DurationValue)
{
	//구현 금지 자식클래스에서 구현할것 
}

void UNSAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
