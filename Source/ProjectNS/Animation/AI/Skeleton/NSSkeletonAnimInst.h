// Copyright Project NS

#pragma once

#include "../NSAIAnimInstance.h"
#include "NSSkeletonAnimInst.generated.h"

UENUM(BlueprintType)
enum class ESkeletonAnimType : uint8 {
	IdleAndWalk_Normal,
	IdleAndRun_Battle,
	Attack_Melee,
	Hit_Front,
	Die
};

UCLASS()
class PROJECTNS_API UNSSkeletonAnimInst : public UNSAIAnimInstance
{
	GENERATED_BODY()

public:
	UNSSkeletonAnimInst();

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Character", meta = (AllowPrivateAccess = true))
	ESkeletonAnimType AnimType;

public:
	void SetAnimType(const ESkeletonAnimType& Type) { AnimType = Type; }

public:
	virtual void ChangeAnimType_Hit() override;
};
