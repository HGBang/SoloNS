// Copyright Project NS

#pragma once

#include "../NSAICharacter.h"
#include "NSSkeletonAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSSkeletonAICharacter : public ANSAICharacter
{
	GENERATED_BODY()
	
public:
	ANSSkeletonAICharacter();

protected:
	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility>		MeleeAttackAbility;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Action_AttackMelee() override;
	virtual void Move_MoveToPoint(const FVector& Pos) override;


};
