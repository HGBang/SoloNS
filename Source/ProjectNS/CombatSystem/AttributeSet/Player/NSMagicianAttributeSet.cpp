// Copyright Project NS


#include "NSMagicianAttributeSet.h"
#include "../../GamePlayEffect/NSGamePlayEffect.h"
#include "../../../Character/NSCharacter.h"
#include "../../System/NSAbilityComponent.h"
#include "../../System/GamePlaySystem.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSMagicianAttributeSet)

UNSMagicianAttributeSet::UNSMagicianAttributeSet() : 
	Super()
{
}

void UNSMagicianAttributeSet::LevelUp()
{
	float LevelValue = Level.GetAttributeValue();
	float ConValue = Constitution.GetAttributeValue();

	Level.SetValue(++LevelValue);

	float HpMaxValue = DICE_SIX + ConValue + ((DICE_SIX / 2.f + 1 + ConValue) * (LevelValue - 1));

	MaxHp.SetValue(HpMaxValue);
	Hp.SetValue(HpMaxValue);
}

void UNSMagicianAttributeSet::InitAttributeSet()
{
	Super::InitAttributeSet();

	float ConValue = GetCharacterAttributeValue(ECharacterAttributeType::Constitution);
	float LevelValue = GetCharacterAttributeValue(ECharacterAttributeType::Level);
	float IntValue = GetCharacterAttributeValue(ECharacterAttributeType::Intelligence);
	float PBValue = 2.f;

	MaxHp.SetValue((DICE_SIX + ConValue) * LevelValue);
	Hp.SetValue(MaxHp.GetAttributeValue());
	SpellKnown.SetValue(IntValue + LevelValue);
	SpellSave.SetValue(SPELL_SAVE_BASE + IntValue + PBValue);
	SpellAccuracy.SetValue(IntValue + PBValue);
	
}

void UNSMagicianAttributeSet::UpdateAttributeSet()
{
	Super::UpdateAttributeSet();

	float ConValue = Constitution.GetAttributeValue();
	float LevelValue = Level.GetAttributeValue();
	float HpMaxValue = DICE_SIX + ConValue + ((DICE_SIX / 2.f + 1 + ConValue) * (LevelValue - 1));
	float HpValue = Hp.GetAttributeValue();
	float IntValue = Intelligence.GetAttributeValue();
	float PBValue = 2.f;

	if (Level.GetAttributeValue() > 4.f)
		PBValue = 3.f;

	SpellKnown.SetValue(IntValue + LevelValue);
	SpellSave.SetValue(SPELL_SAVE_BASE + IntValue + PBValue);
	SpellAccuracy.SetValue(IntValue + PBValue);

	MaxHp.SetValue(HpMaxValue);

	if (HpValue > HpMaxValue)
		Hp.SetValue(HpMaxValue);

}

void UNSMagicianAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, bool Negative)
{	
	int32 EffectSize = Effect->GetGamePlayEffect().Num();

	for (int32 i = 0; i < EffectSize; ++i)
	{
		FGamePlayEffect InEffect = Effect->GetGamePlayEffect()[i];
		ECharacterAttributeType AttributeType = InEffect.GetBaseAttributeType();
		EEffectValueType EffectValueType = InEffect.GetEffectValueType();
		float EffectValue = InEffect.GetEffectValue();

		switch (Effect->GetGamePlayEffect()[i].GetEffectType())
		{
		case ECharacterAttributeType::SpellKnown:
		{
			if (InEffect.GetDiceUse())
				EffectValue += Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, SpellKnown, EffectValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, SpellKnown, GetCharacterAttributeValue(AttributeType) * EffectValue, Negative);
		}
		break;

		case ECharacterAttributeType::SpellSave:
		{
			if (InEffect.GetDiceUse())
				EffectValue += Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, SpellSave, EffectValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, SpellSave, GetCharacterAttributeValue(AttributeType) * EffectValue, Negative);
		}
		break;

		case ECharacterAttributeType::SpellAccuracy:
		{
			if (InEffect.GetDiceUse())
				EffectValue += Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, SpellAccuracy, EffectValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, SpellAccuracy, GetCharacterAttributeValue(AttributeType) * EffectValue, Negative);
		}
		break;
		}
	}
	Super::GamePlayEffectToAttributeSet(Effect, Negative);
}

void UNSMagicianAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, UNSAttributeSet* OtherAttributeSet, bool Negative)
{
	int32 EffectSize = Effect->GetGamePlayEffect().Num();

	for (int32 i = 0; i < EffectSize; ++i)
	{
		FGamePlayEffect InEffect = Effect->GetGamePlayEffect()[i];
		ECharacterAttributeType AttributeType = InEffect.GetBaseAttributeType();
		EEffectValueType EffectValueType = InEffect.GetEffectValueType();
		float EffectValue = InEffect.GetEffectValue();

		UNSCharacterAttributeSet* BaseAttributeSet = Cast<UNSCharacterAttributeSet>(OtherAttributeSet);

		if (!IsValid(BaseAttributeSet))
		{
			UE_LOGFMT(NS_Log, Log, "UNSMagicianAttributeSet - BaseAttributeSet Cast Failed");
			return;
		}
			

		switch (Effect->GetGamePlayEffect()[i].GetEffectType())
		{
		case ECharacterAttributeType::SpellKnown:
		{
			if (InEffect.GetDiceUse())
				EffectValue += Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, SpellKnown, EffectValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, SpellKnown, BaseAttributeSet->GetCharacterAttributeValue(AttributeType) * EffectValue, Negative);
		}
		break;

		case ECharacterAttributeType::SpellSave:
		{
			if (InEffect.GetDiceUse())
				EffectValue += Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, SpellSave, EffectValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, SpellSave, BaseAttributeSet->GetCharacterAttributeValue(AttributeType) * EffectValue, Negative);
		}
		break;

		case ECharacterAttributeType::SpellAccuracy:
		{
			if (InEffect.GetDiceUse())
				EffectValue += Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, SpellAccuracy, EffectValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, SpellAccuracy, BaseAttributeSet->GetCharacterAttributeValue(AttributeType) * EffectValue, Negative);
		}
		break;
		}
	}

	Super::GamePlayEffectToAttributeSet(Effect, OtherAttributeSet, Negative);
}

void UNSMagicianAttributeSet::GamePlayCaculatedEffect(FGamePlayEffect& Effect, FAttribute& Attribute, float Value, bool Negative)
{
	Super::GamePlayCaculatedEffect(Effect, Attribute, Value, Negative);
}

void UNSMagicianAttributeSet::DurationEffect(ECharacterAttributeType Type, float DurationValue)
{
	Super::DurationEffect(Type, DurationValue);

	switch (Type)
	{
	case ECharacterAttributeType::MagicDamage:
	{
		float CurrentValue = MagicDamage.GetAttributeValue();
		MagicDamage.SetValue(CurrentValue - DurationValue);
	}
	case ECharacterAttributeType::SpellKnown:
	{
		float CurrentValue = SpellKnown.GetAttributeValue();
		SpellKnown.SetValue(CurrentValue - DurationValue);
	}
	break;
	case ECharacterAttributeType::SpellSave:
	{
		float CurrentValue = SpellSave.GetAttributeValue();
		SpellSave.SetValue(CurrentValue - DurationValue);
	}
	break;
	case ECharacterAttributeType::SpellAccuracy:
	{
		float CurrentValue = SpellAccuracy.GetAttributeValue();
		SpellAccuracy.SetValue(CurrentValue - DurationValue);
	}
	break;
	}

	if (!bInit)
		InitAttributeSet();

	else
		UpdateAttributeSet();
}

void UNSMagicianAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, MagicDamage);
	DOREPLIFETIME(ThisClass, SpellKnown);
	DOREPLIFETIME(ThisClass, SpellSave);
	DOREPLIFETIME(ThisClass, SpellAccuracy);
}

void UNSMagicianAttributeSet::ExcuteEffectDuration(ECharacterAttributeType Type, float DurationValue, float DurationTime)
{
	Super::ExcuteEffectDuration(Type, DurationValue, DurationTime);
}

float UNSMagicianAttributeSet::GetCharacterAttributeValue(ECharacterAttributeType Type)
{
	switch (Type)
	{
	case ECharacterAttributeType::MagicDamage :
		return MagicDamage.GetAttributeValue();
		break;
	case ECharacterAttributeType::SpellKnown:
		return SpellKnown.GetAttributeValue();
		break;
	case ECharacterAttributeType::SpellSave:
		return SpellSave.GetAttributeValue();
		break;
	case ECharacterAttributeType::SpellAccuracy:
		return SpellAccuracy.GetAttributeValue();
		break;
	}	

	return Super::GetCharacterAttributeValue(Type);
	
}
