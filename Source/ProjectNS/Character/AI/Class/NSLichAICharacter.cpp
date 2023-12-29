// Copyright Project NS


#include "NSLichAICharacter.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSLichAICharacter)

ANSLichAICharacter::ANSLichAICharacter() :
	Super()
{
	bIsBoss = true;
	LegendaryActionCount = 2;
	LegendaryRegistanceCount = 2;
}

void ANSLichAICharacter::Action_AttackMelee()
{
	Super::Action_AttackMelee();
}

void ANSLichAICharacter::Move_MoveToPoint(const FVector& Pos)
{
	Super::Move_MoveToPoint(Pos);
}

void ANSLichAICharacter::Free_LegendaryRegistance()
{
	Super::Free_LegendaryRegistance();
}
