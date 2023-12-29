// Copyright Project NS


#include "NSWarriorCharacter.h"
#include "../../../CombatSystem/System/NSAbilityComponent.h"
#include "../../../CombatSystem/System/NSGameAbility.h"
#include "../../../CombatSystem/AttributeSet/NSCharacterAttributeSet.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSWarriorCharacter)

ANSWarriorCharacter::ANSWarriorCharacter(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	UE_LOGFMT(NS_Log, Log, "ANSWarriorCharacter() »ý¼ºÀÚ");
}

void ANSWarriorCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilityComponent))
	{
		if (IsValid(MeleeAttackAbility))
			AbilityComponent->GiveAbility(MeleeAttackAbility);
	}

	else
		UE_LOGFMT(NS_Log, Log, "AbilityComponent Cast Failed");



}

void ANSWarriorCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ANSWarriorCharacter::CalculateAccuracy(ANSCharacter* Target)
{
	Super::CalculateAccuracy(Target);
}

void ANSWarriorCharacter::SetupPlayerInputComponent(UInputComponent* Component)
{
	Super::SetupPlayerInputComponent(Component);

	//Component->BindAction(TEXT("MeleeAttack"), EInputEvent::IE_Pressed, this, &ANSWarriorCharacter::TestAttack);
}

void ANSWarriorCharacter::PlayTurn(const float& DiceValue)
{
	Super::PlayTurn(DiceValue);

	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Player Turn")));
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Dice Value : %f "), DiceValue));

	TestAttack();
}

void ANSWarriorCharacter::CharacterTurnEnd()
{
	Super::CharacterTurnEnd();

	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Player Turn End. ")));
}


void ANSWarriorCharacter::TestAttack()
{
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Player Attack")));

	if (IsValid(AbilityComponent))
		AbilityComponent->ActivatedAbility(TEXT("MeleeAttack"));
}
