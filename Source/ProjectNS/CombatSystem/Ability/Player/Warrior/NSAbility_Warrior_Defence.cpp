// Copyright Project NS


#include "NSAbility_Warrior_Defence.h"
#include "../../../../Character/NSCharacter.h"
#include "../../../../Animation/NSAnimInstance.h"
#include "../../../../Animation/Player/NSPlayerAnimInstance.h"
#include "../../../System/NSAbilityComponent.h"

UNSAbility_Warrior_Defence::UNSAbility_Warrior_Defence() : 
	Super()
{
}

void UNSAbility_Warrior_Defence::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);


	if (IsValid(OwnerComp))	
		OwnerComp->ExcuteEffectToAttributeSet(GamePlayEffect);

	else
		UE_LOGFMT(NS_Log, Log, "UNSAbility_Warrior_Defence : ActivatedAbility  - OwnerComp Cast Failed");

}

void UNSAbility_Warrior_Defence::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Warrior_Defence::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Warrior_Defence::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Warrior_Defence::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
