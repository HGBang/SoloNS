// Copyright Project NS

#pragma once

#include "../NSAnimInstance.h"
#include "NSPlayerAnimInstance.generated.h"

UENUM(BlueprintType)
enum class EPlayerAnimationType : uint8 {
	IdleAndJog,
	MeleeAttack,
	RangedAttack,
	HitAttack,
	Skill,
	Cast,
	Groggy,
	Die
};

UCLASS()
class PROJECTNS_API UNSPlayerAnimInstance : public UNSAnimInstance
{
	GENERATED_BODY()

public:
	UNSPlayerAnimInstance();

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Anim", meta = (AllowPrivateAccess = true))
	EPlayerAnimationType AnimType;

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;

public:
	void SetPlayerAnimType(const EPlayerAnimationType& Type) { AnimType = Type; }

public:
	virtual void ChangeAnimType_Hit() override;
	virtual void ChangeAnimType_Die() override;



};
