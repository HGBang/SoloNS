	// Copyright Project NS


#include "NSAICharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAICharacter)

ANSAICharacter::ANSAICharacter() :
	Super(),
	bIsBoss(false),
	LegendaryActionCount(0),
	LegendaryRegistanceCount(0)
{
}

void ANSAICharacter::TurnOnOutline_Implementation()
{
	Super::TurnOnOutline_Implementation();

	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void ANSAICharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

void ANSAICharacter::Action_AttackMelee()
{
}

void ANSAICharacter::Move_MoveToPoint(const FVector& Pos)
{
}

void ANSAICharacter::Free_LegendaryRegistance()
{
}

void ANSAICharacter::Death()
{
	Super::Death();
}

void ANSAICharacter::PlayTurn(const float& DiceValue)
{
	Super::PlayTurn(DiceValue);
}

void ANSAICharacter::CharacterTurnEnd()
{
	Super::CharacterTurnEnd();
}
