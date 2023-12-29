// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../NSInfo.h"
#include "../CombatSystem/System/NSGameAbility.h"
#include "../Interface/OutLineInterface.h"
#include "GameFramework/Character.h"
#include "NSCharacter.generated.h"

class ANSBattleArea;
class UNSAbilityComponent;
class UNSGameAbility;
class UNSBoxCollider;
class UBoxComponent;

UCLASS()
class PROJECTNS_API ANSCharacter : public ACharacter, public IOutLineInterface
{
	GENERATED_BODY()

public:
	ANSCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void OnConstruction(const FTransform& Transform) override;

	/* begin IOutlineInterface */
public:
	virtual void TurnOnOutline_Implementation() override;
	virtual void TurnOffOutline_Implementation() override;
	/* end IOutlineInterface */

protected:
	UPROPERTY(Category = "NS|Component", EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UNSAbilityComponent>	AbilityComponent;

	UPROPERTY(Category = "NS|Component|Box", EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent>	MeleeAttackBox;

	UPROPERTY(Category = "NS|Component|Box", EditAnywhere, BlueprintReadWrite)
	FName	SocketName;

	UPROPERTY(Category = "NS|IsPlayer?", EditAnywhere, BlueprintReadOnly)
	bool	bIsPlayer;

	UPROPERTY(Replicated)
	bool	bTurn;

	UPROPERTY(Replicated)
	bool	bIsDie;

	TMap<EActionType, bool> CharacterActionType;

	UPROPERTY(Replicated)
	TObjectPtr<ANSBattleArea>		BattleArea;

	bool	bIsAccuracy;


public:
	bool IsPlayer() const { return bIsPlayer; }
	bool IsDie() const { return bIsDie; }
	//bool IsAccuracy() const { return bIsAccuracy; }
	bool IsAccuracy();

public:
	void SetBattleArea(ANSBattleArea* Area) { BattleArea = Area; }

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	TObjectPtr<UNSAbilityComponent> GetAbilityComponent() const { return AbilityComponent; }

public:
	virtual void Death();

// Battle Area Option
public:
	virtual void PlayTurn(const float& DiceValue);
	virtual void CharacterTurnEnd();
	
// Collision Activated
public:
	void ActivatedCollision();
	void DeActivatedCollision();

// Action Function
public:
	void MajorAction_DefaultAttack();
	void MajorAction_Evade();
	void MajorAction_Retreat();
	void MajorAction_Dash();
	void MajorAction_UseItem();
	void MinorAction_UseItem();
	void ReAction_Attack();

public:
	virtual void CalculateAccuracy(ANSCharacter* Target);

protected:
	UFUNCTION()
		virtual void MeleeAttackBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);
};
