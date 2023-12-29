// Copyright Project NS

#pragma once

#include "../../../System/NSGameAbility.h"
#include "NSAbility_Lich_SummonUndead.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAbility_Lich_SummonUndead : public UNSGameAbility
{
	GENERATED_BODY()

public:
	UNSAbility_Lich_SummonUndead();

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;
	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;
	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;
	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
