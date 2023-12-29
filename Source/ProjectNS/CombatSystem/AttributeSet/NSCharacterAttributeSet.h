// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "../../NSInfo.h"
#include "NSAttributeSet.h"
#include "NSCharacterAttributeSet.generated.h"



class UNSGamePlayEffect;

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSCharacterAttributeSet : public UNSAttributeSet
{

	GENERATED_BODY()

public:
	UNSCharacterAttributeSet();

protected:
	UPROPERTY(Replicated)
	bool		bInit;

	UPROPERTY(Replicated)
	float		PrevValue;

protected:
	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Level;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Strength;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Dexterity;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Constitution;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Intelligence;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Wisdom;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Charisma;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Hp;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	MaxHp;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	ArmorCount;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Initialtive;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Accuracy;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	MoveRange;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	Exp;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	MaxExp;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	WeaponDamage;

	UPROPERTY(Category = "NS|Attribute", EditAnywhere, BlueprintReadOnly, Replicated)
	FAttribute	AbArmorCount;

public:
	virtual void LevelUp() override;
	virtual void InitAttributeSet() override;
	virtual void UpdateAttributeSet() override;
	virtual void GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, bool Negative = false) override;
	virtual void GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, UNSAttributeSet* OtherAttributeSet, bool Negative = false) override;
	virtual void GamePlayCaculatedEffect(FGamePlayEffect& Effect, FAttribute& Attribute, float Value, bool Negative = false) override;
	virtual void DurationEffect(ECharacterAttributeType Type, float DurationValue) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	virtual void ExcuteEffectDuration(ECharacterAttributeType Type, float DurationValue, float DurationTime);

public:
	virtual float GetCharacterAttributeValue(ECharacterAttributeType Type);
	
	
};
