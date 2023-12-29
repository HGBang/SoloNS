// Copyright Project NS


#include "NSGameAbility_RangedAttack.h"
#include "../../../Character/NSCharacter.h"
#include "../../../Animation/NSAnimInstance.h"
#include "../../../Animation/Player/NSPlayerAnimInstance.h"
#include "../../System/NSAbilityComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSGameAbility_RangedAttack)

UNSGameAbility_RangedAttack::UNSGameAbility_RangedAttack() : 
	Super()
{
}

void UNSGameAbility_RangedAttack::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);

	UNSPlayerAnimInstance* PlayerAnim = Cast<UNSPlayerAnimInstance>(AnimInstance);

	if (IsValid(PlayerAnim))
	{
		PlayerAnim->SetPlayerAnimType(EPlayerAnimationType::RangedAttack);

		ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(OwnerComp->GetOwner());

		if (IsValid(OwnerCharacter))
			OwnerCharacter->MajorAction_DefaultAttack();

		else
			UE_LOGFMT(NS_Log, Log, "UNSGameAbility_RangedAttack - OwnerCharacter Cast Failed");
	}
	else
		UE_LOGFMT(NS_Log, Log, "UNSGameAbility_RangedAttack - PlayerAnim Cast Failed");

}

void UNSGameAbility_RangedAttack::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);

	if (EventName == TEXT("BeginOverlapEvent"))
	{
		bool Accuracy = Owner->IsAccuracy();

		if (Accuracy)
		{
			UNSAbilityComponent* TargetComp = Target->GetAbilityComponent();

			if (IsValid(TargetComp))
			{
				if(IsValid(GamePlayEffect))
					TargetComp->ExcuteEffectToAttributeSet(GamePlayEffect);

				else
					UE_LOGFMT(NS_Log, Log, "UNSGameAbility_RangedAttack - GamePlayEffect Cast Failed");
			}
			else
				UE_LOGFMT(NS_Log, Log, "UNSGameAbility_RangedAttack - TargetComp Cast Failed");
		}
	}
}

void UNSGameAbility_RangedAttack::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSGameAbility_RangedAttack::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSGameAbility_RangedAttack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
