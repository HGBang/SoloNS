// Copyright Project NS

#pragma once

#include "../NSAIAnimInstance.h"
#include "NSDragonAnimInst.generated.h"

UENUM(BlueprintType)
enum class EDragonAnimType : uint8 {
	IdleAndWalk_Normal,
	IdleAndRun_Battle,
	Attack_Bite,
	Attack_Scratch,
	Attack_Breath,
	Attack_Tail,
	Attack_Wing,
	Attack_Fear,
	Landing,
	Hit_Front,
	Die
};

UCLASS()
class PROJECTNS_API UNSDragonAnimInst : public UNSAIAnimInstance
{
	GENERATED_BODY()
	
public:
	UNSDragonAnimInst();

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Character", meta = (AllowPrivateAccess = true))
	EDragonAnimType AnimType;

public:
	void SetAnimType(const EDragonAnimType& Type) { AnimType = Type; }

public:
	virtual void ChangeAnimType_Hit() override;
	virtual void ChangeAnimType_Die() override;

public:
	UFUNCTION()
		void AnimNotify_MeleeAttackEnd();

	UFUNCTION()
		void AnimNotify_BreathEnd();

	UFUNCTION()
		void AnimNotify_FlyingAttack();

	UFUNCTION()
		void AnimNotify_FlyingAttackEnd();

	UFUNCTION()
		void AnimNotify_ScratchAttackEnd();
};
