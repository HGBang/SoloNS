// Copyright Project NS

#pragma once

#include "../NSCharacter.h"
#include "NSAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSAICharacter : public ANSCharacter
{
	GENERATED_BODY()

public:
	ANSAICharacter();

protected:
	UPROPERTY(Category = "NS|BossAction", BlueprintReadWrite, EditAnywhere)
	bool	bIsBoss;
	
	UPROPERTY(Category = "NS|BossAction", BlueprintReadWrite, EditAnywhere)
	uint8	LegendaryActionCount;

	UPROPERTY(Category = "NS|BossAction", BlueprintReadWrite, EditAnywhere)
	uint8	LegendaryRegistanceCount;

	/* begin IOutlineInterface */
public:
	virtual void TurnOnOutline_Implementation() override;
	/* end IOutlineInterface */

public:
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	virtual void Action_AttackMelee();
	virtual void Move_MoveToPoint(const FVector& Pos);
	virtual void Free_LegendaryRegistance();

public:
	virtual void Death() override;

public:
	virtual void PlayTurn(const float& DiceValue) override;
	virtual void CharacterTurnEnd() override;

};
