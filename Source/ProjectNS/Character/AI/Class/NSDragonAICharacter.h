// Copyright Project NS

#pragma once

#include "../NSAICharacter.h"
#include "NSDragonAICharacter.generated.h"

class UNSGameAbility;
/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSDragonAICharacter : public ANSAICharacter
{
	GENERATED_BODY()

public:
	ANSDragonAICharacter();

protected:
	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility> MeleeAttackAbility;

	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility> FearAbility;

	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility> ScratchingAbility;

	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility> TailAbility;

	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGameAbility> BreathAbility;

protected:
	UPROPERTY(Category = "NS|Component|Box", EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent>	TailAttackBox;

	UPROPERTY(Category = "NS|Component|Box", EditAnywhere, BlueprintReadWrite)
	FName	TailAttackSocketName;

	UPROPERTY(Category = "NS|Component|Box", EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent>	BreathAttackBox;

	UPROPERTY(Category = "NS|Component|Box", EditAnywhere, BlueprintReadWrite)
	FName	BreathSocketName;

	UPROPERTY(Category = "NS|Component|Box", EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent>	ScratchAttackBox;

	UPROPERTY(Category = "NS|Component|Box", EditAnywhere, BlueprintReadWrite)
	FName	ScratchSocketName;
  
	bool	bBreathPossible;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	virtual void PlayTurn(const float& DiceValue) override;
	virtual void CharacterTurnEnd() override;
  
	virtual void Action_AttackMelee() override;
	virtual void Move_MoveToPoint(const FVector& Pos) override;
	virtual void Free_LegendaryRegistance() override;

public:
	void ActiveCollisionTailAttack();
	void DeActiveCollisionTailAttack();

	void ActiveCollisionBreathAttack();
	void DeActiveCollisionBreathAttack();

	void ActiveCollisionScratchAttack();
	void DeActiveCollisionScratchAttack();


public:
	// 주변 대상에게 공포 상태를 부여하는 공격
	void Action_Fear();
	// 가까운 거리의 대상을 할퀴는 공격
	void Action_Scratching();
	// 먼 거리의 대상을 꼬리를 휘두르는 공격
	void Action_Tail();
	// 먼 거리의 대상을 꼬리를 휘두르는 공격
	void Action_Breath();

	// 레전더리 액션
	// 레전더리 액션(Cost 1), 꼬리 공격
	void LAction_Tail();
	// 레전더리 액션(Cost 2), 날개를 휘둘러 주변을 공격
	void LAction_Wing();


protected:
	UFUNCTION()
	void TailAttackBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION()
	void BreathAttackBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void ScratchAttackBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);
};
