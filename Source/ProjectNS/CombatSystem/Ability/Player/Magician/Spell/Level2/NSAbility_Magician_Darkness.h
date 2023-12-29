// Copyright Project NS

#pragma once

#include "../../NSAbility_Magician_SpellBase.h"
#include "NSAbility_Magician_Darkness.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAbility_Magician_Darkness : public UNSAbility_Magician_SpellBase
{
	GENERATED_BODY()
	
public:
	UNSAbility_Magician_Darkness();

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;
	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;
	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;
	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
