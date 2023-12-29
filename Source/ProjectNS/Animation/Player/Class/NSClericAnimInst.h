// Copyright Project NS

#pragma once

#include "../NSPlayerAnimInstance.h"
#include "NSClericAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSClericAnimInst : public UNSPlayerAnimInstance
{
	GENERATED_BODY()

public:
	UNSClericAnimInst();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;
	
};
