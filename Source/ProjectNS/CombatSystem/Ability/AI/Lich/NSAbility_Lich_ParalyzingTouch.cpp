// Copyright Project NS


#include "NSAbility_Lich_ParalyzingTouch.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAbility_Lich_ParalyzingTouch)

UNSAbility_Lich_ParalyzingTouch::UNSAbility_Lich_ParalyzingTouch() :
	Super()
{
}

void UNSAbility_Lich_ParalyzingTouch::ActivatedAbility(UNSAbilityComponent* OwnerComp, UNSAnimInstance* AnimInstance)
{
	Super::ActivatedAbility(OwnerComp, AnimInstance);
	
	// 리치 밀리 어택은 d20 + 9 <- (5(PB) + 4(Int))의 명중률을 가진다.
	// 리치 밀리 어택의 사정거리는 5ft이고, 피해는 2d6이다.

	// 공격 타겟은 DC15의 건강 내성 굴림을 하여 실패 시, 1분간 마비된다.
	// 마비는 매 턴의 종료 시, 건강 굴림을 하여 풀 수 있다.

}

void UNSAbility_Lich_ParalyzingTouch::ActivatedAbilityEvent(FName EventName, ANSCharacter* Owner, ANSCharacter* Target)
{
	Super::ActivatedAbilityEvent(EventName, Owner, Target);
}

void UNSAbility_Lich_ParalyzingTouch::EndAbility(UNSAbilityComponent* OwnerComp)
{
	Super::EndAbility(OwnerComp);
}

void UNSAbility_Lich_ParalyzingTouch::TickAbility(float DeltaSeconds)
{
	Super::TickAbility(DeltaSeconds);
}

void UNSAbility_Lich_ParalyzingTouch::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
