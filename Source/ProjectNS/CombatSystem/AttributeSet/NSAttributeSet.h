// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NSAttributeSet.generated.h"


class UNSGamePlayEffect;
class UNSAbilityComponent;
struct FGamePlayEffect;



USTRUCT(BlueprintType)
struct FAttribute
{
	friend class UNSCharacterAttributeSet;
	friend class UNSWarriorAttributeSet;
	friend class UNSThiefAttributeSet;
	friend class UNSMagicianAttributeSet;
	friend class UNSClericAttributeSet;

	GENERATED_BODY()

protected:
	float AttributeValue;

	bool bOverrideState;

protected:
	float GetAttributeValue() const { return AttributeValue; }	

protected:
	void SetValue(float Value) { AttributeValue = Value; }
	void SetOverrideState(bool Override) { bOverrideState = Override; }
	bool GetOverrideState() { return bOverrideState; }
};

/**
 * 해당 클래스로 객체생성 금지, 상속받아서 사용 할것.
 */
UCLASS(Abstract, BlueprintType, Blueprintable, config = Engine)
class PROJECTNS_API UNSAttributeSet : public UObject
{
	GENERATED_BODY()

protected:
	TObjectPtr<UNSAbilityComponent>		OwnerComp;

public:
	void SetOwnerComp(UNSAbilityComponent* Owner) { OwnerComp = Owner; }

public:
	virtual void LevelUp();
	virtual void InitAttributeSet();
	virtual void UpdateAttributeSet();

	// 상대방의 AttributeSet이 필요가 없고, 본인만의 수치로 Effect적용이 필요한 경우
	virtual void GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, bool Negative = false);

	// 상대방의 AttributeSet에 적용하여 Effect를 적용할 경우
	virtual void GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, UNSAttributeSet* OtherAttributeSet, bool Negative = false);

	// Effect 최종 연산
	virtual void GamePlayCaculatedEffect(FGamePlayEffect& Effect, FAttribute& Attribute, float Value , bool Negative = false);

	// Duration 연산
	UFUNCTION()
	virtual void DurationEffect(ECharacterAttributeType Type, float DurationValue);	

	// Replicate
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
