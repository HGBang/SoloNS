// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../NSInfo.h"
#include "Animation/AnimInstance.h"
#include "NSAnimInstance.generated.h"

class ANSCharacter;

UCLASS()
class PROJECTNS_API UNSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UNSAnimInstance();

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Character", meta = (AllowPrivateAccess = true))
	TObjectPtr<ANSCharacter>	Character;

protected: // Anim Variables
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Movement", meta = (AllowPrivateAccess = true))
	bool	bIsAccelarating;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Movement", meta = (AllowPrivateAccess = true))
	float	Speed;

	FRotator CharacterRotation;
	FRotator PrevCharacterRotation;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Movement", meta = (AllowPrivateAccess = true))
	float	YawDelta;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Attack", meta = (AllowPrivateAccess = true))
	uint8	RandAttackMaxCount;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "NS|Attack", meta = (AllowPrivateAccess = true))
	uint8	RandAttack;

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;

public:
	virtual void ChangeAnimType_Hit();
	virtual void ChangeAnimType_Die();

private:
	void SetAnimVariableSpeed();
	void SetAnimVariableYawDelta(float DeltaSeconds);
};
