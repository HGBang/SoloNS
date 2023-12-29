// Copyright Project NS

#pragma once

#include "../NSAICharacter.h"
#include "NSBarghestAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSBarghestAICharacter : public ANSAICharacter
{
	GENERATED_BODY()

public:
	ANSBarghestAICharacter();

protected:
	bool	bBreathPossible;
	uint8	BreathReusableValue;

protected:
	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility>		MeleeAttackAbility;

	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility>		BreathAttackAbility;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Death();

public:
	virtual void Action_AttackMelee() override;
	virtual void Move_MoveToPoint(const FVector& Pos) override;

	void Action_BreathAttack();

public:
	virtual void PlayTurn(const float& DiceValue) override;
	virtual void CharacterTurnEnd() override;
};
