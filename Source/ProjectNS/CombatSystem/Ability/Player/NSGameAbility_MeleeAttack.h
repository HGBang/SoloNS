// Copyright Project NS

#pragma once

#include "../../../NSInfo.h"
#include "../../System/NSGameAbility.h"
#include "NSGameAbility_MeleeAttack.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSGameAbility_MeleeAttack : public UNSGameAbility
{
	GENERATED_BODY()

public:
	UNSGameAbility_MeleeAttack();

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;

	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;

	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;

	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
