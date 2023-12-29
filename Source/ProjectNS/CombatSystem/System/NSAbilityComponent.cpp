// Fill out your copyright notice in the Description page of Project Settings.


#include "NSAbilityComponent.h"
#include "Components/BoxComponent.h"
#include "NSGameAbility.h"
#include "GameFramework/Character.h"
#include "../AttributeSet/NSAttributeSet.h"
#include "../AttributeSet/NSCharacterAttributeSet.h"
#include "../GamePlayEffect/NSGamePlayEffect.h"
#include "../../Animation/NSAnimInstance.h"
#include "GamePlaySystem.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbilityComponent)


// Sets default values for this component's properties
UNSAbilityComponent::UNSAbilityComponent() :
	Super()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UNSAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(OwnerAttributeSetClass))
	{
		UNSAttributeSet* AttributeSet = NewObject<UNSAttributeSet>(this, OwnerAttributeSetClass);

		if (IsValid(AttributeSet))
		{
			OwnerAttributeSet = AttributeSet;

			if (IsValid(InitEffect))
				ExcuteEffectToAttributeSet(InitEffect);

			OwnerAttributeSet->SetOwnerComp(this);
		}
		else
			UE_LOGFMT(NS_Log, Log, "UNSAbilityComponent - AttributeSet Cast Failed");
	}
	else
		UE_LOGFMT(NS_Log, Log, "UNSAbilityComponent - OwnerAttributeSetClass is not valid");

}

void UNSAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

UNSGameAbility* UNSAbilityComponent::FindAbility(const FName& AbilityName)
{
	for (int32 i = 0; i < Abilitys.Num(); ++i)
	{
		if (Abilitys[i]->GetAbilityName() == AbilityName)
			return Abilitys[i];
	}
	return nullptr;
}

void UNSAbilityComponent::GiveAbility(TSubclassOf<UNSGameAbility> InAbility)
{
	if (IsValid(InAbility))
	{
		UNSGameAbility* NewAbility = NewObject<UNSGameAbility>(this, InAbility);

		if (IsValid(NewAbility))
		{
			Abilitys.Add(NewAbility);

		}
	}
}

void UNSAbilityComponent::ActivatedAbility(FName AbilityName)
{


	for (const auto& Ability : Abilitys) {

		if (Ability->GetAbilityName() == AbilityName)
		{
			ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());

			if (IsValid(OwnerCharacter))
			{
				UNSAnimInstance* CharacterAnim = Cast<UNSAnimInstance>(OwnerCharacter->GetMesh()->GetAnimInstance());

				if (IsValid(CharacterAnim))
				{
					if (IsValid(Ability))
					{
						GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, TEXT("ActivatedAbility Begin"));

						Ability->ActivatedAbility(this, CharacterAnim);

			

						UE_LOGFMT(NS_Log, Log, "Ability->ActivatedAbility Successed");

						if(!IsValid(Ability))
							UE_LOGFMT(NS_Log, Log, "Ability->ActivatedAbility post Cast Faild");

						break;
					}
				}
			}

			else
				UE_LOGFMT(NS_Log, Log, "UNSAbilityComponent - OwnerCharacter Cast Failed");
		}
	}
}

void UNSAbilityComponent::EndAbility(FName AbilityName)
{
	UNSGameAbility* CachedAbility = FindAbility(AbilityName);

	if (IsValid(CachedAbility))
	{
		CachedAbility->EndAbility(this);
	}
}

void UNSAbilityComponent::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	for (int32 i = 0; i < Abilitys.Num(); ++i)
	{
		if (IsValid(Abilitys[i]))
			Abilitys[i]->ActivatedAbilityEvent(EventName, Owner, Target);
	}
}

void UNSAbilityComponent::ExcuteEffectToAttributeSet(TSubclassOf<UNSGamePlayEffect> Effect, bool Negative)
{
	if (IsValid(Effect))
	{
		UNSGamePlayEffect* NewGamePlayEffect = NewObject<UNSGamePlayEffect>(this, Effect);

		if (!IsValid(OwnerAttributeSet))
		{
			UE_LOGFMT(NS_Log, Log, "UNSAbilityComponent - OwnerAttributeSet Cast Failed");
			return;
		}

		else if (!IsValid(NewGamePlayEffect))
		{
			UE_LOGFMT(NS_Log, Log, "UNSAbilityComponent - NewGamePlayEffect Cast Failed");
			return;
		}




		OwnerAttributeSet->GamePlayEffectToAttributeSet(NewGamePlayEffect, Negative);

		NewGamePlayEffect->ConditionalBeginDestroy();
		NewGamePlayEffect->MarkAsGarbage();
		NewGamePlayEffect = nullptr;
	}
}

void UNSAbilityComponent::ExcuteEffectToAttributeSet(TSubclassOf<UNSGamePlayEffect> Effect, UNSAttributeSet* OtherAttributeSet, bool Negative)
{

	if (IsValid(Effect))
	{

		UNSGamePlayEffect* NewGamePlayEffect = NewObject<UNSGamePlayEffect>(this, Effect);
		NewGamePlayEffect->CreateDice();

		if (!IsValid(OwnerAttributeSet))
		{
			UE_LOGFMT(NS_Log, Log, "UNSAbilityComponent - OwnerAttributeSet Cast Failed");
			return;
		}

		else if (!IsValid(NewGamePlayEffect))
		{
			UE_LOGFMT(NS_Log, Log, "UNSAbilityComponent - NewGamePlayEffect Cast Failed");
			return;
		}

		OwnerAttributeSet->GamePlayEffectToAttributeSet(NewGamePlayEffect, OtherAttributeSet, Negative);

		NewGamePlayEffect->ConditionalBeginDestroy();
		NewGamePlayEffect->MarkAsGarbage();
		NewGamePlayEffect = nullptr;
	}
}