// Copyright Project NS

#include "NSGameAbility_UseItem.h"
#include "../../../Character/NSCharacter.h"
#include "../../../Animation/NSAnimInstance.h"
#include "../../../Animation/Player/NSPlayerAnimInstance.h"
#include "../../System/NSAbilityComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSGameAbility_UseItem)

UNSGameAbility_UseItem::UNSGameAbility_UseItem() : 
	Super()
{
}

void UNSGameAbility_UseItem::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);

	if (IsValid(GamePlayEffect))
	{
		OwnerComp->ExcuteEffectToAttributeSet(GamePlayEffect);

		ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(OwnerComp->GetOwner());

		if (IsValid(OwnerCharacter))
		{
			if (bMajorType)		
				OwnerCharacter->MajorAction_UseItem();			

			else
				OwnerCharacter->MinorAction_UseItem();			
		}
		else
			UE_LOGFMT(NS_Log, Log, "UNSGameAbility_UseItem - OwnerCharacter Cast Failed");
	}
	else
		UE_LOGFMT(NS_Log, Log, "UNSGameAbility_UseItem - GamePlayEffect Cast Failed");
}

void UNSGameAbility_UseItem::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSGameAbility_UseItem::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSGameAbility_UseItem::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSGameAbility_UseItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, bMajorType);
}
