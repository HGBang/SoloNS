// Copyright Project NS

#pragma once

#include "../NSAIAnimInstance.h"
#include "NSLichAnimInst.generated.h"

UENUM(BlueprintType)
enum class ELichAnimType : uint8 {
	IdleAndWalk,
	Attack_Hand,
	Attack_Spell_Cantrip,
	Attack_Spell_Spell,
	Attack_Spell_SummonUndead,
	Hit_Front,
	Die
};

UCLASS()
class PROJECTNS_API UNSLichAnimInst : public UNSAIAnimInstance
{
	GENERATED_BODY()
	
public:
	UNSLichAnimInst();

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Character", meta = (AllowPrivateAccess = true))
	ELichAnimType AnimType;

public:
	void SetAnimType(const ELichAnimType& Type) { AnimType = Type; }

public:
	virtual void ChangeAnimType_Hit() override;
};
