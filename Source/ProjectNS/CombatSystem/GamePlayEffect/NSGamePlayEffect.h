// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../NSInfo.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NSGamePlayEffect.generated.h"




UENUM(BlueprintType)
enum class EEffectValueType : uint8
{
	Static,
	OtherAttributeBase,
};

UENUM(BlueprintType)
enum class EEffectPeriod :uint8
{
	Instant,
	Duration
};

UENUM(BlueprintType)
enum class EEffectCaculation : uint8
{
	Add,
	Multiply,
	Override
};

USTRUCT(BlueprintType)
struct FGamePlayEffect
{
	GENERATED_BODY()

protected:
	/* 영향을 줄 AttributeType */
	UPROPERTY(Category = "NS|Effect", EditAnywhere, BlueprintReadOnly)
		ECharacterAttributeType TargetAttributeType;

	/*
	* Effect Value Type
	* Static = 절대값
	* OtherAttributeBase = Other Attribute를 참조,
	**/
	UPROPERTY(Category = "NS|Effect", EditAnywhere, BlueprintReadOnly)
		EEffectValueType EffectValueType;

	/*
	* ValueType = OtherAttributeBase 일때만 사용.
	* 어떤 Attribute를 참조할건지 ?
	**/
	UPROPERTY(Category = "NS|Effect", EditAnywhere, BlueprintReadOnly)
		ECharacterAttributeType BaseAttributeType;

	/*
	* EffectValueType Static 일 경우 EffectValue가 적용시킬 수치
	* OtherAttributeBase 일 경우 배율로 적용 (OtherAttribute * EffectValue)
	* ex ) 그냥 절대값 50으로 적용한다 -> ValueType = Static , Value = 50.f;
	* ex ) 내공격력을 Base로 1.2배수의 값을 적용한다 -> ValueType = Base , Value = 1.2f
	*/
	UPROPERTY(Category = "NS|Effect", EditAnywhere, BlueprintReadOnly)
		float EffectValue;

	/*
	* period
	* Instant = 즉시 적용
	* Duration = 일정시간 적용 후, 원복
	*/
	UPROPERTY(Category = "NS|Effect", EditAnywhere, BlueprintReadOnly)
		EEffectPeriod	EffectPeriod;

	/*
	* 계산방식
	* Add = 더함
	* MultiPly = 곱
	* Override = 덮어쓰기
	*/
	UPROPERTY(Category = "NS|Effect", EditAnywhere, BlueprintReadOnly)
		EEffectCaculation EffectCaculation;

	/*
	* Duration일경우에만 사용
	*/
	UPROPERTY(Category = "NS|Effect", EditAnywhere, BlueprintReadOnly)
		float DurationTime;

	UPROPERTY(Category = "NS|Effect", EditAnywhere, BlueprintReadOnly)
		bool	bDiceUse;

public:
	ECharacterAttributeType GetEffectType() const { return TargetAttributeType; }
	ECharacterAttributeType GetBaseAttributeType() const { return BaseAttributeType; }
	const float& GetEffectValue() const { return EffectValue; }
	EEffectValueType GetEffectValueType() const { return EffectValueType; }
	EEffectPeriod GetEffectPeriod() const { return EffectPeriod; }
	EEffectCaculation GetEffectCaculation() const { return EffectCaculation; }
	const float& GetDurationTime() const { return DurationTime; }
	bool GetDiceUse() const { return bDiceUse; }

};



/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, config = Engine)
class PROJECTNS_API UNSGamePlayEffect : public UObject
{
	GENERATED_BODY()

public:
	UNSGamePlayEffect();

protected:
	UPROPERTY(Category = "NS|DiceCount", EditAnywhere, BlueprintReadOnly, Replicated)
	int32 DiceCount;

	UPROPERTY(Category = "NS|DiceCount", EditAnywhere, BlueprintReadOnly, Replicated)
	int32 DiceValue;

	UPROPERTY(Replicated)
	TArray<int32> DiceValues;

protected:
	UPROPERTY(Category = "EffectSet", EditAnywhere, BlueprintReadOnly)
	TArray<FGamePlayEffect>		GamePlayEffect;

public:
	TArray<FGamePlayEffect>& GetGamePlayEffect() { return GamePlayEffect; }	

public:
	void CreateDice();
	int32 GetDiceTotalValue();
	TArray<int32> GetDiceValues() { return DiceValues; }

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


};
