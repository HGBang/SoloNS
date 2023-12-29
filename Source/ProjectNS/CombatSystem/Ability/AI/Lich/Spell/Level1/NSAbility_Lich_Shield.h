// Copyright Project NS

#pragma once

#include "../../NSAbility_Lich_SpellBase.h"
#include "NSAbility_Lich_Shield.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAbility_Lich_Shield : public UNSAbility_Lich_SpellBase
{
	GENERATED_BODY()

public:
	UNSAbility_Lich_Shield();

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;
	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;
	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;
	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
