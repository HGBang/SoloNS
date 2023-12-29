// Copyright Project NS


#include "NSGameAbility_MeleeAttack.h"
#include "../../../Character/NSCharacter.h"
#include "../../../Animation/NSAnimInstance.h"
#include "../../../Animation/Player/NSPlayerAnimInstance.h"
#include "../../System/NSAbilityComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSGameAbility_MeleeAttack)

UNSGameAbility_MeleeAttack::UNSGameAbility_MeleeAttack() : 
	Super()
{
}

void UNSGameAbility_MeleeAttack::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);


	UNSPlayerAnimInstance* PlayerAnim = Cast<UNSPlayerAnimInstance>(AnimInstance);

	if (IsValid(PlayerAnim))
	{
		PlayerAnim->SetPlayerAnimType(EPlayerAnimationType::MeleeAttack);

		ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(OwnerComp->GetOwner());

		if (IsValid(OwnerCharacter))
			OwnerCharacter->MajorAction_DefaultAttack();

		else
			UE_LOGFMT(NS_Log, Log, "UNSGameAbility_MeleeAttack - OwnerCharacter Cast Failed");


		UE_LOGFMT(NS_Log, Log, "UNSGameAbility_MeleeAttack->ActivatedAbility Successed {name}", OwnerCharacter->GetName());

	}
	else
		UE_LOGFMT(NS_Log, Log, "UNSGameAbility_MeleeAttack - PlayerAnim Cast Failed");
}

void UNSGameAbility_MeleeAttack::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);

	if (EventName == TEXT("BeginOverlapEvent"))	{


		bool Accuracy = Owner->IsAccuracy();

		if (!Accuracy)
		{
			UNSAbilityComponent* TargetComp = Target->GetAbilityComponent();
			UNSAbilityComponent* OwenrComp = Owner->GetAbilityComponent();

			if (IsValid(TargetComp))
			{
				if (IsValid(GamePlayEffect))
				{
					TargetComp->ExcuteEffectToAttributeSet(GamePlayEffect, OwenrComp->GetAttributeSet());
					UNSAnimInstance* TargetAnim = Cast<UNSAnimInstance>(Target->GetMesh()->GetAnimInstance());

					if (IsValid(TargetAnim))
						TargetAnim->ChangeAnimType_Hit();

					else
						UE_LOGFMT(NS_Log, Log, "UNSGameAbility_MeleeAttack - TargetAnim Cast Failed");
				}

				else
					UE_LOGFMT(NS_Log, Log, "UNSGameAbility_MeleeAttack - GamePlayEffect Cast Failed");
			}
			else
				UE_LOGFMT(NS_Log, Log, "UNSGameAbility_MeleeAttack - TargetComp Cast Failed");
		}
	}
}

void UNSGameAbility_MeleeAttack::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSGameAbility_MeleeAttack::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSGameAbility_MeleeAttack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
