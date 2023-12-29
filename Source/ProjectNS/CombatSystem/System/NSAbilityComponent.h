// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NSAbilityComponent.generated.h"

class UNSGameAbility;
class UNSAttributeSet;
class UNSGamePlayEffect;
class ANSCharacter;
class UBoxComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTNS_API UNSAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNSAbilityComponent();

protected:
	UPROPERTY(Category = "NS|Ability", EditAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<UNSGameAbility>> Abilitys;

	UPROPERTY(Category = "NS|CharacterAttributeSet", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSAttributeSet>		OwnerAttributeSetClass;

	UPROPERTY(Category = "NS|CharacterAttributeSet", EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UNSAttributeSet>			OwnerAttributeSet;

	UPROPERTY(Category = "InitEffect", EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UNSGamePlayEffect>		InitEffect;

protected:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UNSGameAbility* FindAbility(const FName& AbilityName);
	TObjectPtr<UNSAttributeSet>& GetAttributeSet() { return OwnerAttributeSet; }

public: // Abiltiy
	void GiveAbility(TSubclassOf<UNSGameAbility> InAbility);

	void ActivatedAbility(FName AbilityName);

	void EndAbility(FName AbilityName);

	void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target);

public: // Attribute
	void ExcuteEffectToAttributeSet(TSubclassOf<UNSGamePlayEffect> Effect , bool Negative = false);
	void ExcuteEffectToAttributeSet(TSubclassOf<UNSGamePlayEffect> Effect, UNSAttributeSet* OtherAttributeSet, bool Negative = false);
};