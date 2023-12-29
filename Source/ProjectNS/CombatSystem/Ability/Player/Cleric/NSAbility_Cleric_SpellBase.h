// Copyright Project NS

#pragma once

#include "../../../System/NSGameAbility.h"
#include "NSAbility_Cleric_SpellBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAbility_Cleric_SpellBase : public UNSGameAbility
{
	GENERATED_BODY()

public:
	UNSAbility_Cleric_SpellBase();

protected:
	UPROPERTY(Category = "NS|Variable", EditAnywhere, BlueprintReadOnly, Replicated)
	EConditionType	SpellActionType;

	UPROPERTY(Category = "NS|Variable", EditAnywhere, BlueprintReadOnly, Replicated)
	float	Range;

	UPROPERTY(Category = "NS|Variable", EditAnywhere, BlueprintReadOnly, Replicated)
	float	Area;

	UPROPERTY(Category = "NS|Variable", EditAnywhere, BlueprintReadOnly, Replicated)
	float	Duration;

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) override;
	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) override;
	virtual void EndAbility(UNSAbilityComponent* OwnerComp) override;
	virtual void TickAbility(float DeltaSeconds) override;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
