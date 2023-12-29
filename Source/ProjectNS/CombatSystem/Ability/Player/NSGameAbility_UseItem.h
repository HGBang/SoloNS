// Copyright Project NS

#pragma once

#include "../../../NSInfo.h"
#include "../../System/NSGameAbility.h"
#include "NSGameAbility_UseItem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSGameAbility_UseItem : public UNSGameAbility
{
	GENERATED_BODY()

public:
	UNSGameAbility_UseItem();

protected:
	UPROPERTY(Category = "NS|MajorAction", EditAnywhere, BlueprintReadOnly, Replicated)
	bool	bMajorType;

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance) final;

	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target) final;

	virtual void EndAbility(UNSAbilityComponent* OwnerComp) final;

	virtual void TickAbility(float DeltaSeconds) final;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
