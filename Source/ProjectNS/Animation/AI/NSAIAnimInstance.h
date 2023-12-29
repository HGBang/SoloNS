// Copyright Project NS

#pragma once

#include "../NSAnimInstance.h"
#include "NSAIAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSAIAnimInstance : public UNSAnimInstance
{
	GENERATED_BODY()
	
public:
	UNSAIAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;

public:
	virtual void ChangeAnimType_Hit() override;
	virtual void ChangeAnimType_Die() override;

};
