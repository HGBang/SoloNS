// Copyright Project NS

#pragma once

#include "../NSPlayerAnimInstance.h"
#include "NSMagicianAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSMagicianAnimInst : public UNSPlayerAnimInstance
{
	GENERATED_BODY()

public:
	UNSMagicianAnimInst();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;
};
