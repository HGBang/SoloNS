// Copyright Project NS

#pragma once

#include "../../../System/NSGameAbility.h"
#include "NSAbility_Cleric_DiscipleOfLife.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAbility_Cleric_DiscipleOfLife : public UNSGameAbility
{
	GENERATED_BODY()

public:
	UNSAbility_Cleric_DiscipleOfLife();

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;
	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;
	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;
	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
