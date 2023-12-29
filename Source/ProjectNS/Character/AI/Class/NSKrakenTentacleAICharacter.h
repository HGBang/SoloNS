// Copyright Project NS

#pragma once

#include "../NSAICharacter.h"
#include "NSKrakenTentacleAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSKrakenTentacleAICharacter : public ANSAICharacter
{
	GENERATED_BODY()

public:
	ANSKrakenTentacleAICharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Action_AttackMelee() override;
	virtual void Move_MoveToPoint(const FVector& Pos) override;
};
