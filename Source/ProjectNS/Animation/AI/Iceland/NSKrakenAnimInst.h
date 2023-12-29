// Copyright Project NS

#pragma once

#include "../NSAIAnimInstance.h"
#include "NSKrakenAnimInst.generated.h"

UENUM(BlueprintType)
enum class EKrakenAnimType : uint8 {
	Idle,
	Attack,
	Hit_Front,
	Die
};


/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSKrakenAnimInst : public UNSAIAnimInstance
{
	GENERATED_BODY()

public:
	UNSKrakenAnimInst();


protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Character", meta = (AllowPrivateAccess = true))
	EKrakenAnimType AnimType;

public:
	void SetAnimType(const EKrakenAnimType& Type) { AnimType = Type; }

public:
	virtual void ChangeAnimType_Hit() override;
};
