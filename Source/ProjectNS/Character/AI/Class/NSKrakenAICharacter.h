// Copyright Project NS

#pragma once

#include "../NSAICharacter.h"
#include "NSKrakenAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSKrakenAICharacter : public ANSAICharacter
{
	GENERATED_BODY()
	
public:
	ANSKrakenAICharacter();

protected:
	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility>		MeleeAttackAbility;

	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility>		TentacleAttackAbility;

	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility>		FlingAttackAbility;

	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility>		LightningStormAttackAbility;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Action_AttackMelee() override;
	virtual void Move_MoveToPoint(const FVector& Pos) override;
	virtual void Free_LegendaryRegistance() override;

	// 대상을 붙잡는 촉수 공격
	void Action_Tentacle();
	// 촉수에 붙잡힌 대상을 던지는 공격
	void Action_Fling();
	// 번개를 쏘아내는 공격
	void Action_LightningStorm();

	// 레전더리 액션
	// 레전더리 액션(Cost 1), 촉수 공격
	void LAction_Attack();
	// 레전더리 액션(Cost 1), 던지기 공격
	void LAction_Fling();
	// 레전더리 액션(Cost 2), 번개 공격
	void LAction_LightningStorm();
};
