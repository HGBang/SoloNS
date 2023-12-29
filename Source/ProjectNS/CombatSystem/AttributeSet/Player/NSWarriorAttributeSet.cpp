// Copyright Project NS


#include "NSWarriorAttributeSet.h"
#include "../../GamePlayEffect/NSGamePlayEffect.h"
#include "../../../Character/NSCharacter.h"
#include "../../System/NSAbilityComponent.h"
#include "../../System/GamePlaySystem.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSWarriorAttributeSet)

UNSWarriorAttributeSet::UNSWarriorAttributeSet() : 
	Super()
{
}

void UNSWarriorAttributeSet::LevelUp()
{
	float LevelValue = Level.GetAttributeValue();
	float ConValue = Constitution.GetAttributeValue();

	Level.SetValue(++LevelValue);

	float HpMaxValue = DICE_TEN + ConValue + ((DICE_TEN / 2.f + 1 + ConValue) * (LevelValue - 1));

	MaxHp.SetValue(HpMaxValue);
	Hp.SetValue(HpMaxValue);
}

void UNSWarriorAttributeSet::InitAttributeSet()
{
	Super::InitAttributeSet();

	float ConValue = Constitution.GetAttributeValue();
	float LevelValue = Level.GetAttributeValue();;

	MaxHp.SetValue((DICE_TEN + ConValue) * LevelValue);
	Hp.SetValue(MaxHp.GetAttributeValue());

}

void UNSWarriorAttributeSet::UpdateAttributeSet()
{
	Super::UpdateAttributeSet();

	float LevelValue = Level.GetAttributeValue();
	float ConValue = Constitution.GetAttributeValue();
	float HpMaxValue = DICE_TEN + ConValue + ((DICE_TEN / 2.f + 1 + ConValue) * (LevelValue - 1));
	float HpValue = Hp.GetAttributeValue();

	MaxHp.SetValue(HpMaxValue);

	if (HpValue > HpMaxValue)
		Hp.SetValue(HpMaxValue);

}

void UNSWarriorAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, bool Negative)
{
	Super::GamePlayEffectToAttributeSet(Effect, Negative);
}

void UNSWarriorAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, UNSAttributeSet* OtherAttributeSet, bool Negative)
{
	Super::GamePlayEffectToAttributeSet(Effect, OtherAttributeSet, Negative);
}

void UNSWarriorAttributeSet::GamePlayCaculatedEffect(FGamePlayEffect& Effect, FAttribute& Attribute, float Value, bool Negative)
{
	Super::GamePlayCaculatedEffect(Effect, Attribute, Value, Negative);
}

void UNSWarriorAttributeSet::DurationEffect(ECharacterAttributeType Type, float DurationValue)
{
	Super::DurationEffect(Type, DurationValue);
}

void UNSWarriorAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UNSWarriorAttributeSet::ExcuteEffectDuration(ECharacterAttributeType Type, float DurationValue, float DurationTime)
{
	Super::ExcuteEffectDuration(Type, DurationValue, DurationTime);
}

float UNSWarriorAttributeSet::GetCharacterAttributeValue(ECharacterAttributeType Type)
{	
	return 	Super::GetCharacterAttributeValue(Type);;
}
