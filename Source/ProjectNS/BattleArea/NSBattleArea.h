// Copyright Project NS

#pragma once

#include "../NSInfo.h"
#include "GameFramework/Actor.h"
#include "NSBattleArea.generated.h"

class ANSCharacter;
class UBoxComponent;
class USphereComponent;
class UNSWidget_TEST_TurnFaceChange;

UCLASS()
class PROJECTNS_API ANSBattleArea : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANSBattleArea();

protected:
	// Overlap을 판단할 Area 영역
	UPROPERTY(Category = "NS|AreaBox", EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent>		AreaShape;

	UPROPERTY(Category = "NS|CharacterList", EditAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<ANSCharacter>>	InsideMembers;

	TObjectPtr<UNSWidget_TEST_TurnFaceChange>	BattleUI;


	// 배틀도중 난입하는 플레이어 
	TArray<TObjectPtr<ANSCharacter>>		IntrudingMembers;

	// 주사위 값
	UPROPERTY(Replicated)
	TArray<int32> DiceArray;
	
	UPROPERTY(Replicated)
	int32			TurnIndex;

	UPROPERTY(Replicated)
	bool			bIsActive;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// Collision
	UFUNCTION()
	virtual void AreaBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);
public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	void UpdateArea();
	
public:
	void ChangeTurn();

private:
	void StartBattle();
	void EndBattle();
	void IncludeMember();


private:
	bool CompareMembersByDiceValue(TObjectPtr<ANSCharacter> MemberA, TObjectPtr<ANSCharacter> MemberB, int32 DiceA, int32 DiceB);

};
