// Copyright Project NS

#pragma once

#include "../../../System/NSGameAbility.h"
#include "NSAbility_Barghest_BiteAttack.generated.h"

/**
 * Barghest Base Melee Atack
 */
UCLASS()
class PROJECTNS_API UNSAbility_Barghest_BiteAttack : public UNSGameAbility
{
	GENERATED_BODY()

public:
	UNSAbility_Barghest_BiteAttack();

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;
	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;
	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;
	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
