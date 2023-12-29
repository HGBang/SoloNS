// Copyright Project NS

#pragma once

#include "../NSPlayerAnimInstance.h"
#include "NSThiefAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSThiefAnimInst : public UNSPlayerAnimInstance
{
	GENERATED_BODY()

public:
	UNSThiefAnimInst();

protected: // Anim Variables
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Movement", meta = (AllowPrivateAccess = true))
	bool	bIsSprint;

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;
	
	
};
