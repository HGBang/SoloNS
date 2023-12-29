// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../NSInfo.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NSGameAbility.generated.h"

class UNSAbilityComponent;
class UNSGamePlayEffect;
class UNSAnimInstance;
class ANSCharacter;

/**
 * Base Class �̹Ƿ� ���� Ŭ�������� ���� �Ұ� , �ش� Ŭ���� ��ü���� ����
 */
UCLASS(BlueprintType, Blueprintable, config = Engine)
class PROJECTNS_API UNSGameAbility : public UObject
{
	GENERATED_BODY()

public:
	UNSGameAbility();

protected:
	UPROPERTY(Category = "NS|AbilityName", EditAnywhere, BlueprintReadOnly, Replicated);
	FName		AbilityName;

	UPROPERTY(Category = "NS|AbilityTickEnable", EditAnywhere, BlueprintReadOnly, Replicated)
	bool		bTick;

	UPROPERTY(Category = "NS|AbilityEffect", EditAnywhere, BlueprintReadOnly , Replicated)
	TSubclassOf<UNSGamePlayEffect>	GamePlayEffect;

	UPROPERTY(Replicated)
	bool		bAbilityEnable;

public:
	const FName& GetAbilityName() const;
	const bool& GetAbilityTickEnable() const;

public:
	virtual void ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance);

	virtual void ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target);

	virtual void EndAbility(UNSAbilityComponent* OwnerComp);

	virtual void TickAbility(float DeltaSeconds);

public:
	// Replicated
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
