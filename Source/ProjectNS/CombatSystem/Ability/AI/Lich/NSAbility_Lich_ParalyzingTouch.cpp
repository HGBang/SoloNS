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
	
	// ��ġ �и� ������ d20 + 9 <- (5(PB) + 4(Int))�� ���߷��� ������.
	// ��ġ �и� ������ �����Ÿ��� 5ft�̰�, ���ش� 2d6�̴�.

	// ���� Ÿ���� DC15�� �ǰ� ���� ������ �Ͽ� ���� ��, 1�а� ����ȴ�.
	// ����� �� ���� ���� ��, �ǰ� ������ �Ͽ� Ǯ �� �ִ�.

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
