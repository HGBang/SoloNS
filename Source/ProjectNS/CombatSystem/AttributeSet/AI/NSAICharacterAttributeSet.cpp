// Copyright Project NS


#include "NSAICharacterAttributeSet.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSAICharacterAttributeSet)

UNSAICharacterAttributeSet::UNSAICharacterAttributeSet() : 
	Super()
{
}

void UNSAICharacterAttributeSet::InitAttributeSet()
{
	Super::InitAttributeSet();
}

void UNSAICharacterAttributeSet::UpdateAttributeSet()
{
	Super::UpdateAttributeSet();
}

void UNSAICharacterAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, bool Negative)
{
	Super::GamePlayEffectToAttributeSet(Effect, Negative);
}

void UNSAICharacterAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, UNSAttributeSet* OtherAttributeSet, bool Negative)
{
	Super::GamePlayEffectToAttributeSet(Effect, OtherAttributeSet, Negative);
}

void UNSAICharacterAttributeSet::GamePlayCaculatedEffect(FGamePlayEffect& Effect, FAttribute& Attribute, float Value, bool Negative)
{
	Super::GamePlayCaculatedEffect(Effect, Attribute, Value, Negative);
}

void UNSAICharacterAttributeSet::DurationEffect(ECharacterAttributeType Type, float DurationValue)
{
	Super::DurationEffect(Type, DurationValue);
}

void UNSAICharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UNSAICharacterAttributeSet::ExcuteEffectDuration(ECharacterAttributeType Type, float DurationValue, float DurationTime)
{
	Super::ExcuteEffectDuration(Type, DurationValue, DurationTime);
}

float UNSAICharacterAttributeSet::GetCharacterAttributeValue(ECharacterAttributeType Type)
{
	return 	Super::GetCharacterAttributeValue(Type);
}
