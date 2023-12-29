// Copyright Project NS

#pragma once

#include "../NSAICharacter.h"
#include "NSLichAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSLichAICharacter : public ANSAICharacter
{
	GENERATED_BODY()

public:
	ANSLichAICharacter();

public:
	virtual void Action_AttackMelee() override;
	virtual void Move_MoveToPoint(const FVector& Pos) override;
	virtual void Free_LegendaryRegistance() override;
	
};
