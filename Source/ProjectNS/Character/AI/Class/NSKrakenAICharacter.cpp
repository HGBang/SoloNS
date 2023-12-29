// Copyright Project NS


#include "NSKrakenAICharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSKrakenAICharacter)

ANSKrakenAICharacter::ANSKrakenAICharacter() :
	Super()
{
	bIsBoss = true;
	LegendaryActionCount = 3;
	LegendaryRegistanceCount = 3;
}

void ANSKrakenAICharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ANSKrakenAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANSKrakenAICharacter::Action_AttackMelee()
{
	Super::Action_AttackMelee();
}

void ANSKrakenAICharacter::Move_MoveToPoint(const FVector& Pos)
{
	Super::Move_MoveToPoint(Pos);
}

void ANSKrakenAICharacter::Free_LegendaryRegistance()
{
	Super::Free_LegendaryRegistance();
}

void ANSKrakenAICharacter::Action_Tentacle()
{
}

void ANSKrakenAICharacter::Action_Fling()
{
}

void ANSKrakenAICharacter::Action_LightningStorm()
{
}

void ANSKrakenAICharacter::LAction_Attack()
{
}

void ANSKrakenAICharacter::LAction_Fling()
{
}

void ANSKrakenAICharacter::LAction_LightningStorm()
{
}
