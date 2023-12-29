// Copyright Project NS

#pragma once

#include "../../../System/NSGameAbility.h"
#include "NSAbility_Dragon_TailAttack.generated.h"

class ANSEffectActor;

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAbility_Dragon_TailAttack : public UNSGameAbility
{
	GENERATED_BODY()
	
public:
	UNSAbility_Dragon_TailAttack();

protected:
	UPROPERTY(Category = "NS|Particle", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ANSEffectActor>		TailAttackEffect;

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;
	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;
	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;
	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
