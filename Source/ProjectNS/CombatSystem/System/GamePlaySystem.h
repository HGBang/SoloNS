// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../AttributeSet/NSAttributeSet.h"
#include "NSAbilityComponent.h"
#include "NSGameAbility.h"

/**
 * 
 */

struct FGamePlayUtills
{
protected:
	static float CurrentValue;

public:
	static bool IsAttackPossible(float SrcValue, float DestValue)
	{
		return SrcValue > DestValue;
	}
	static float GetCurrentValue() { return CurrentValue; }	

public:
	static void SetCurrentValue(float Value) { CurrentValue = Value;}
};


class PROJECTNS_API GamePlaySystem
{
public:
	GamePlaySystem();
	~GamePlaySystem();
};
