// Copyright Project NS


#include "NSAbility_Dragon_MeleeAttack.h"
#include "../../../../CombatSystem/System/NSGameAbility.h"
#include "../../../../CombatSystem/System/NSAbilityComponent.h"
#include "../../../../CombatSystem/GamePlayEffect/NSGamePlayEffect.h"
#include "../../../../Animation/AI/Castle/NSDragonAnimInst.h"
#include "../../../../Character/AI/Class/NSDragonAICharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Dragon_MeleeAttack)

UNSAbility_Dragon_MeleeAttack::UNSAbility_Dragon_MeleeAttack() :
	Super()
{
}

void UNSAbility_Dragon_MeleeAttack::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);

	UNSDragonAnimInst* DragonAnim = Cast<UNSDragonAnimInst>(AnimInstance);

	if (IsValid(DragonAnim))
	{
		DragonAnim->SetAnimType(EDragonAnimType::Attack_Bite);

		ANSDragonAICharacter* OwnerCharacter = Cast<ANSDragonAICharacter>(OwnerComp->GetOwner());

		if (IsValid(OwnerCharacter))
			OwnerCharacter->Action_AttackMelee();
	}


}

void UNSAbility_Dragon_MeleeAttack::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);

	if (EventName == TEXT("BeginOverlapEvent")) {


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
						UE_LOGFMT(NS_Log, Log, "UNSAbility_Dragon_MeleeAttack - TargetAnim Cast Failed");
				}

				else
					UE_LOGFMT(NS_Log, Log, "UNSAbility_Dragon_MeleeAttack - GamePlayEffect Cast Failed");
			}
			else
				UE_LOGFMT(NS_Log, Log, "UNSAbility_Dragon_MeleeAttack - TargetComp Cast Failed");
		}
	}
}

void UNSAbility_Dragon_MeleeAttack::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Dragon_MeleeAttack::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Dragon_MeleeAttack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
