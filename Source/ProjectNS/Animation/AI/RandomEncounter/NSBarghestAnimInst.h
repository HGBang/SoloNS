// Copyright Project NS

#pragma once

#include "../NSAIAnimInstance.h"
#include "NSBarghestAnimInst.generated.h"


UENUM(BlueprintType)
enum class EBarghestAnimType : uint8 {
	IdleAndWalk_Normal,
	IdleAndRun_Battle,
	Attack_Bite,
	Attack_Critical,
	Attack_Breath,
	Hit_Front,
	Die
};

UCLASS()
class PROJECTNS_API UNSBarghestAnimInst : public UNSAnimInstance
{
	GENERATED_BODY()

public:
	UNSBarghestAnimInst();

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Character", meta = (AllowPrivateAccess = true))
	EBarghestAnimType AnimType;

public:
	void SetAnimType(const EBarghestAnimType& Type) { AnimType = Type; }

public:
	virtual void ChangeAnimType_Hit() override;

public:
	UFUNCTION()
	void AnimNotify_HitAttack();

	UFUNCTION()
	void AnimNotify_HitRecovery();

	UFUNCTION()
	void AnimNotify_MeleeAttackEnd();
	
};
