// Copyright Project NS

#pragma once

#include "../../../System/NSGameAbility.h"
#include "NSAbility_Kraken_LightningStorm.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAbility_Kraken_LightningStorm : public UNSGameAbility
{
	GENERATED_BODY()

public:
	UNSAbility_Kraken_LightningStorm();

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;
	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;
	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;
	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
