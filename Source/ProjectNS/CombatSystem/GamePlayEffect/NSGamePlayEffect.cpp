// Fill out your copyright notice in the Description page of Project Settings.


#include "NSGamePlayEffect.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSGamePlayEffect)

UNSGamePlayEffect::UNSGamePlayEffect()
{
}

void UNSGamePlayEffect::CreateDice()
{
	if (DiceValue == 0 || DiceCount == 0)
		return;

	if (DiceValues.Num())
		DiceValues.Empty();

	for (int32 i = 0; i < DiceCount; ++i)
	{
		int32 Value = FMath::RandRange(DICE_MIN, DiceValue);
		DiceValues.Add(Value);
	}
}

int32 UNSGamePlayEffect::GetDiceTotalValue()
{	
	int32 Size = DiceValues.Num();
	int32 TotalValue = 0;

	for (int32 i = 0; i < Size; ++i)	
		TotalValue += DiceValues[i];
	
	return TotalValue;
}

void UNSGamePlayEffect::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, DiceValues);
	DOREPLIFETIME(ThisClass, DiceValue);
	DOREPLIFETIME(ThisClass, DiceCount);
}
