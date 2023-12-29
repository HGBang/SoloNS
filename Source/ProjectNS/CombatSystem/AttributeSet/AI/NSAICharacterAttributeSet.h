// Copyright Project NS

#pragma once

#include "CoreMinimal.h"
#include "../NSCharacterAttributeSet.h"
#include "NSAICharacterAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAICharacterAttributeSet : public UNSCharacterAttributeSet
{
	GENERATED_BODY()

public:
	UNSAICharacterAttributeSet();

public:
	virtual void InitAttributeSet() final;
	virtual void UpdateAttributeSet() final;
	virtual void GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, bool Negative = false) final;
	virtual void GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, UNSAttributeSet* OtherAttributeSet, bool Negative = false) final;
	virtual void GamePlayCaculatedEffect(FGamePlayEffect& Effect, FAttribute& Attribute, float Value, bool Negative = false) final;
	virtual void DurationEffect(ECharacterAttributeType Type, float DurationValue) final;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const final;

public:
	virtual void ExcuteEffectDuration(ECharacterAttributeType Type, float DurationValue, float DurationTime) final;

public:
	virtual float GetCharacterAttributeValue(ECharacterAttributeType Type) final;
	
};
