// Copyright Project NS

#pragma once

#include "../../NSAbility_Lich_SpellBase.h"
#include "NSAbility_Lich_Invisibility.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAbility_Lich_Invisibility : public UNSAbility_Lich_SpellBase
{
	GENERATED_BODY()

public:
	UNSAbility_Lich_Invisibility();

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;
	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;
	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;
	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
