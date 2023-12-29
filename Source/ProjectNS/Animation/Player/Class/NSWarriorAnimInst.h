// Copyright Project NS

#pragma once

#include "../NSPlayerAnimInstance.h"
#include "NSWarriorAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSWarriorAnimInst : public UNSPlayerAnimInstance
{
	GENERATED_BODY()

public:
	UNSWarriorAnimInst();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;


public:
	UFUNCTION()
		void AnimNotify_ActiveAttackCollider();

	UFUNCTION()
		void AnimNotify_DeActiveAttackCollider();

	UFUNCTION()
		void AnimNotify_MeleeAttackEnd();
};
