// Copyright Project NS


#include "NSAbility_Barghest_BiteAttack.h"
#include "../../../../CombatSystem/System/NSGameAbility.h"
#include "../../../../CombatSystem/System/NSAbilityComponent.h"
#include "../../../../CombatSystem/GamePlayEffect/NSGamePlayEffect.h"
#include "../../../../Animation/AI/RandomEncounter/NSBarghestAnimInst.h"
#include "../../../../Character/AI/NSAICharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Barghest_BiteAttack)

UNSAbility_Barghest_BiteAttack::UNSAbility_Barghest_BiteAttack() :
	Super()
{
}

void UNSAbility_Barghest_BiteAttack::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);

	// 바게스트는 무리 전술을 가진다.
	// 무리 전술은 대상 하나를 같이 공격 할 때, 공격 굴림에 유리함을 받는다.

	UNSBarghestAnimInst* BargherstAnim = Cast<UNSBarghestAnimInst>(AnimInstance);

	if (IsValid(BargherstAnim))
	{
		BargherstAnim->SetAnimType(EBarghestAnimType::Attack_Bite);

		ANSAICharacter* OwnerCharacter = Cast<ANSAICharacter>(OwnerComp->GetOwner());

		if (IsValid(OwnerCharacter))
			OwnerCharacter->Action_AttackMelee();

		else
			UE_LOGFMT(NS_Log, Log, "UNSGameAbility_MeleeAttack - OwnerCharacter Cast Failed");


		UE_LOGFMT(NS_Log, Log, "UNSGameAbility_MeleeAttack->ActivatedAbility Successed {name}", OwnerCharacter->GetName());

	}
	else
		UE_LOGFMT(NS_Log, Log, "UNSGameAbility_MeleeAttack - PlayerAnim Cast Failed");

}

void UNSAbility_Barghest_BiteAttack::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Barghest_BiteAttack::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Barghest_BiteAttack::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Barghest_BiteAttack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
