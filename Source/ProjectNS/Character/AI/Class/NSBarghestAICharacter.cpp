// Copyright Project NS


#include "NSBarghestAICharacter.h"
#include "../../../CombatSystem/AttributeSet/NSCharacterAttributeSet.h"
#include "../../../CombatSystem/System/NSAbilityComponent.h"
#include "../../../CombatSystem/System/NSGameAbility.h"
#include "Components/CapsuleComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSBarghestAICharacter)

ANSBarghestAICharacter::ANSBarghestAICharacter() :
	Super(),
	bBreathPossible(true),
	BreathReusableValue(5)
{
}

void ANSBarghestAICharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilityComponent)) {
		if (IsValid(MeleeAttackAbility))
			AbilityComponent->GiveAbility(MeleeAttackAbility);

		if(IsValid(BreathAttackAbility))
			AbilityComponent->GiveAbility(BreathAttackAbility);
	}
}

void ANSBarghestAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANSBarghestAICharacter::Death()
{
	Super::Death();

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ANSBarghestAICharacter::Action_AttackMelee()
{
	Super::Action_AttackMelee();

	//if (IsValid(AbilityComponent))
	//	AbilityComponent->ActivatedAbility("MeleeAttack");
}

void ANSBarghestAICharacter::Move_MoveToPoint(const FVector& Pos)
{
	Super::Move_MoveToPoint(Pos);
}

void ANSBarghestAICharacter::Action_BreathAttack()
{
	if (bBreathPossible) {
		if (IsValid(AbilityComponent))
			AbilityComponent->ActivatedAbility("BreathAttack");

		// 사용 직후 1d6을 굴려, 5 이상이면 재사용 가능.
		bBreathPossible = FMath::RandRange(DICE_MIN, DICE_SIX) >= BreathReusableValue;
	}
}

void ANSBarghestAICharacter::PlayTurn(const float& DiceValue)
{
	Super::PlayTurn(DiceValue);

	// Test
	if(IsValid(AbilityComponent))
		AbilityComponent->ActivatedAbility("MeleeAttack");
}

void ANSBarghestAICharacter::CharacterTurnEnd()
{
	Super::CharacterTurnEnd();
}
