// Copyright Project NS



#include "NSGameAbility_Skill.h"
#include "../../../Character/NSCharacter.h"
#include "../../../Animation/NSAnimInstance.h"
#include "../../../Animation/Player/NSPlayerAnimInstance.h"
#include "../../System/NSAbilityComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSGameAbility_Skill)

UNSGameAbility_Skill::UNSGameAbility_Skill() : 
	Super()
{
}

void UNSGameAbility_Skill::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);

	UNSPlayerAnimInstance* PlayerAnim = Cast<UNSPlayerAnimInstance>(AnimInstance);

	if (IsValid(PlayerAnim))
	{
		PlayerAnim->SetPlayerAnimType(EPlayerAnimationType::Skill);

		ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(OwnerComp->GetOwner());

		if (IsValid(OwnerCharacter))
			OwnerCharacter->MajorAction_DefaultAttack();

		else
			UE_LOGFMT(NS_Log, Log, "UNSGameAbility_Skill - OwnerCharacter Cast Failed");
	}
	else
		UE_LOGFMT(NS_Log, Log, "UNSGameAbility_Skill - PlayerAnim Cast Failed");
}

void UNSGameAbility_Skill::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSGameAbility_Skill::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSGameAbility_Skill::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSGameAbility_Skill::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
