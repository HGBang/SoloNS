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

	// ����� ����� �˼� ����
	void Action_Tentacle();
	// �˼��� ������ ����� ������ ����
	void Action_Fling();
	// ������ ��Ƴ��� ����
	void Action_LightningStorm();

	// �������� �׼�
	// �������� �׼�(Cost 1), �˼� ����
	void LAction_Attack();
	// �������� �׼�(Cost 1), ������ ����
	void LAction_Fling();
	// �������� �׼�(Cost 2), ���� ����
	void LAction_LightningStorm();
};
