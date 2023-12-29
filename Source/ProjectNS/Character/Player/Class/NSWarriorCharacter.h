// Copyright Project NS

#pragma once

#include "../NSPlayerCharacter.h"
#include "NSWarriorCharacter.generated.h"

class UNSGameAbility;

UCLASS()
class PROJECTNS_API ANSWarriorCharacter : public ANSPlayerCharacter
{
	GENERATED_BODY()
	
public:
	ANSWarriorCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility>	MeleeAttackAbility;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void CalculateAccuracy(ANSCharacter* Target) override;

public:
	virtual void SetupPlayerInputComponent(UInputComponent* Component) override;

public:
	virtual void PlayTurn(const float& DiceValue) override;
	virtual void CharacterTurnEnd() override;


public:
	void TestAttack();
};
