// Copyright Project NS


#include "NSAbility_Warrior_SecondWind.h"
#include "../../../../Character/NSCharacter.h"
#include "../../../../Animation/NSAnimInstance.h"
#include "../../../../Animation/Player/NSPlayerAnimInstance.h"
#include "../../../System/NSAbilityComponent.h"

UNSAbility_Warrior_SecondWind::UNSAbility_Warrior_SecondWind() : 
	Super()
{
}

void UNSAbility_Warrior_SecondWind::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);

	if (IsValid(OwnerComp))
		OwnerComp->ExcuteEffectToAttributeSet(GamePlayEffect);

	else
		UE_LOGFMT(NS_Log, Log, "UNSAbility_Warrior_Defence : ActivatedAbility  - OwnerComp Cast Failed");
}

void UNSAbility_Warrior_SecondWind::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Warrior_SecondWind::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Warrior_SecondWind::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Warrior_SecondWind::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
