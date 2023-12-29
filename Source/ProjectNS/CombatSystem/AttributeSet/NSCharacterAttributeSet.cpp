// Fill out your copyright notice in the Description page of Project Settings.


#include "NSCharacterAttributeSet.h"
#include "../GamePlayEffect/NSGamePlayEffect.h"
#include "../../Character/NSCharacter.h"
#include "../System/NSAbilityComponent.h"
#include "../System/GamePlaySystem.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSCharacterAttributeSet)

UNSCharacterAttributeSet::UNSCharacterAttributeSet() :
	Super(),
	bInit(false),
	PrevValue(0.f)
{

}

void UNSCharacterAttributeSet::LevelUp()
{
}

void UNSCharacterAttributeSet::InitAttributeSet()
{
	bInit = true;

	float LevelValue = Level.GetAttributeValue();
	float StrValue = Strength.GetAttributeValue();
	float DexValue = Dexterity.GetAttributeValue();
	float IntValue = Intelligence.GetAttributeValue();
	float WisValue = Wisdom.GetAttributeValue();
	float ChaValue = Charisma.GetAttributeValue();
	float ConValue = Constitution.GetAttributeValue();
	float MaxHpValue = MaxHp.GetAttributeValue();
	float HpValue = Hp.GetAttributeValue();
	float ExpValue = Exp.GetAttributeValue();
	float MaxExpValue = MaxExp.GetAttributeValue();
	float ACValue = ArmorCount.GetAttributeValue();
	float INIValue = Initialtive.GetAttributeValue();
	float AccuracyValue = Accuracy.GetAttributeValue();
	float WeaponDamageValue = WeaponDamage.GetAttributeValue();
	float MoveRangeValue = MoveRange.GetAttributeValue();

	Accuracy.SetValue((StrValue / 2.f) - 5.f);

	ArmorCount.SetValue(8 + DexValue);
}

void UNSCharacterAttributeSet::UpdateAttributeSet()
{
	float LevelValue = Level.GetAttributeValue();
	float StrValue = Strength.GetAttributeValue();
	float DexValue = Dexterity.GetAttributeValue();
	float IntValue = Intelligence.GetAttributeValue();
	float WisValue = Wisdom.GetAttributeValue();
	float ChaValue = Charisma.GetAttributeValue();
	float ConValue = Constitution.GetAttributeValue();
	float MaxHpValue = MaxHp.GetAttributeValue();
	float HpValue = Hp.GetAttributeValue();
	float ExpValue = Exp.GetAttributeValue();
	float MaxExpValue = MaxExp.GetAttributeValue();
	float ACValue = ArmorCount.GetAttributeValue();
	float INIValue = Initialtive.GetAttributeValue();
	float AccuracyValue = Accuracy.GetAttributeValue();
	float WeaponDamageValue = WeaponDamage.GetAttributeValue();
	float MoveRangeValue = MoveRange.GetAttributeValue();
	float AbACValue = AbArmorCount.GetAttributeValue();

	// 명중률 계산
	Accuracy.SetValue((StrValue / 2.f) - 5.f);	

	// 방어력 계산
	if(!ArmorCount.GetOverrideState())
	ArmorCount.SetValue(8 + DexValue + AbACValue);	

	//if (HpValue <= 0.f)
	//{
	//	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(OwnerComp->GetOwner());

	//	if (IsValid(OwnerCharacter))
	//		OwnerCharacter->Death();
	//}
}

void UNSCharacterAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, bool Negative)
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
		case ECharacterAttributeType::Level:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Level, EffectValue + DiceValue, Negative);

			else		
				GamePlayCaculatedEffect(InEffect, Level, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Strength:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Strength, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Strength, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Dexterity:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Dexterity, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Dexterity, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Constitution:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Constitution, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Constitution, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Intelligence:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Intelligence, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Intelligence, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Wisdom:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Wisdom, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Wisdom, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Charisma:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Charisma, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Charisma, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Hp:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Hp, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Hp, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::MaxHp:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, MaxHp, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, MaxHp, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::ArmorCount:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, ArmorCount, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, ArmorCount, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Initialtive:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Initialtive, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Initialtive, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Accuracy:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Accuracy, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Accuracy, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::MoveRange:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, MoveRange, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, MoveRange, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::Exp:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Exp, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Exp, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::MaxExp:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, MaxExp, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, MaxExp, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::WeaponDamage:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, WeaponDamage, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, WeaponDamage, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::AbArmorCount:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, AbArmorCount, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, AbArmorCount, (GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		}
	}
}

void UNSCharacterAttributeSet::GamePlayEffectToAttributeSet(UNSGamePlayEffect* Effect, UNSAttributeSet* OtherAttributeSet, bool Negative)
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
			UE_LOGFMT(NS_Log, Log, "UNSCharacterAttributeSet - BaseAttributeSet Cast Failed");
			return;
		}

		switch (Effect->GetGamePlayEffect()[i].GetEffectType())
		{
		case ECharacterAttributeType::Level:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Level, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Level,(BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Strength:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Strength, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Strength, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Dexterity:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Dexterity, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Dexterity, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Constitution:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Constitution, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Constitution, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Intelligence:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Intelligence, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Intelligence, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Wisdom:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Wisdom, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Wisdom, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Charisma:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Charisma, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Charisma, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Hp:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Hp, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Hp, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::MaxHp:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, MaxHp, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, MaxHp, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::ArmorCount:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, ArmorCount, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, ArmorCount, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Initialtive:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Initialtive, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Initialtive, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Accuracy:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Accuracy, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Accuracy, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::MoveRange:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, MoveRange, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, MoveRange, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::Exp:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, Exp, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, Exp, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;
		case ECharacterAttributeType::MaxExp:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, MaxExp, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, MaxExp, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
			break;	
		case ECharacterAttributeType::WeaponDamage:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, WeaponDamage, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, WeaponDamage, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		case ECharacterAttributeType::AbArmorCount:
		{
			float DiceValue = 0.f;

			if (InEffect.GetDiceUse())
				DiceValue = Effect->GetDiceTotalValue();

			if (EffectValueType == EEffectValueType::Static)
				GamePlayCaculatedEffect(InEffect, AbArmorCount, EffectValue + DiceValue, Negative);

			else
				GamePlayCaculatedEffect(InEffect, AbArmorCount, (BaseAttributeSet->GetCharacterAttributeValue(AttributeType) + DiceValue) * EffectValue, Negative);
		}
		break;
		}
	}	
}

void UNSCharacterAttributeSet::GamePlayCaculatedEffect(FGamePlayEffect& Effect, FAttribute& Attribute, float Value, bool Negative)
{
	switch (Effect.GetEffectCaculation())
	{
	case EEffectCaculation::Add:
	{
		if (Negative)
		{
			float CurruntValue = Attribute.GetAttributeValue() + (-1.f * Value);
			Attribute.SetValue(CurruntValue);
		}
		else
		{
			float CurruntValue = Attribute.GetAttributeValue() + Value;
			Attribute.SetValue(CurruntValue);

			const float DurationValue = Value;

			if (Effect.GetEffectPeriod() == EEffectPeriod::Duration)
				ExcuteEffectDuration(Effect.GetEffectType(), DurationValue, Effect.GetDurationTime());
		
		}
	}
		break;
	case EEffectCaculation::Multiply:
	{
		if (Negative)
		{
			float CurruntValue = Attribute.GetAttributeValue() *  Value * -1.f;
			Attribute.SetValue(CurruntValue);
		}
		else
		{
			float CurruntValue = Attribute.GetAttributeValue();
			float ChangeValue = Attribute.GetAttributeValue() * Value;
			Attribute.SetValue(ChangeValue);

			const float DurationValue = ChangeValue - CurruntValue;

			if (Effect.GetEffectPeriod() == EEffectPeriod::Duration)
				ExcuteEffectDuration(Effect.GetEffectType(), DurationValue, Effect.GetDurationTime());
		}
	}
		break;
	case EEffectCaculation::Override:
	{

		if (Negative)
		{		
			Attribute.SetValue(PrevValue);
			Attribute.SetOverrideState(false);
			PrevValue = 0.f;
		}

		else
		{
			float CurruntValue = Attribute.GetAttributeValue();	
			PrevValue = Attribute.GetAttributeValue();

			float ChangeValue = Value;
			Attribute.SetValue(ChangeValue);
			Attribute.SetOverrideState(true);

			if (Effect.GetEffectPeriod() == EEffectPeriod::Duration)
			{
				const float DurationValue = ChangeValue - CurruntValue;;
				ExcuteEffectDuration(Effect.GetEffectType(), DurationValue, Effect.GetDurationTime());
			}
		}
	}
		break;
	}

	if (bInit)
		UpdateAttributeSet();
	else
		InitAttributeSet();
}

void UNSCharacterAttributeSet::DurationEffect(ECharacterAttributeType Type, float DurationValue)
{
	switch (Type)
	{
	case ECharacterAttributeType::Level:
	{
		float CurrentValue = Level.GetAttributeValue();
		Level.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Strength:
	{
		float CurrentValue = Strength.GetAttributeValue();
		Strength.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Dexterity:
	{
		float CurrentValue = Dexterity.GetAttributeValue();
		Dexterity.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Constitution:
	{
		float CurrentValue = Constitution.GetAttributeValue();
		Constitution.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Intelligence:
	{
		float CurrentValue = Intelligence.GetAttributeValue();
		Intelligence.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Wisdom:
	{
		float CurrentValue = Wisdom.GetAttributeValue();
		Wisdom.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Charisma:
	{
		float CurrentValue = Charisma.GetAttributeValue();
		Charisma.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Hp:
	{
		float CurrentValue = Hp.GetAttributeValue();
		Hp.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::MaxHp:
	{
		float CurrentValue = MaxHp.GetAttributeValue();
		MaxHp.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::ArmorCount:
	{
		float CurrentValue = ArmorCount.GetAttributeValue();
		ArmorCount.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Initialtive:
	{
		float CurrentValue = Initialtive.GetAttributeValue();
		Initialtive.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Accuracy:
	{
		float CurrentValue = Accuracy.GetAttributeValue();
		Accuracy.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::MoveRange:
	{
		float CurrentValue = MoveRange.GetAttributeValue();
		MoveRange.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::Exp:
	{
		float CurrentValue = Exp.GetAttributeValue();
		Exp.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::MaxExp:
	{
		float CurrentValue = MaxExp.GetAttributeValue();
		MaxExp.SetValue(CurrentValue - DurationValue);
	}
		break;
	case ECharacterAttributeType::WeaponDamage:
	{
		float CurrentValue = WeaponDamage.GetAttributeValue();
		MaxExp.SetValue(CurrentValue - DurationValue);
	}
	break;
	case ECharacterAttributeType::AbArmorCount:
	{
		float CurrentValue = AbArmorCount.GetAttributeValue();
		MaxExp.SetValue(CurrentValue - DurationValue);
	}
	break;
	}

	if (!bInit)
		InitAttributeSet();

	else
		UpdateAttributeSet();
}

void UNSCharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, Level);
	DOREPLIFETIME(ThisClass, Strength);
	DOREPLIFETIME(ThisClass, Dexterity);
	DOREPLIFETIME(ThisClass, Constitution);
	DOREPLIFETIME(ThisClass, Intelligence);
	DOREPLIFETIME(ThisClass, Wisdom);
	DOREPLIFETIME(ThisClass, Charisma);
	DOREPLIFETIME(ThisClass, Hp);
	DOREPLIFETIME(ThisClass, MaxHp);
	DOREPLIFETIME(ThisClass, ArmorCount);
	DOREPLIFETIME(ThisClass, Initialtive);
	DOREPLIFETIME(ThisClass, Accuracy);
	DOREPLIFETIME(ThisClass, MoveRange);
	DOREPLIFETIME(ThisClass, Exp);
	DOREPLIFETIME(ThisClass, MaxExp);
	DOREPLIFETIME(ThisClass, WeaponDamage);
	DOREPLIFETIME(ThisClass, AbArmorCount);
	DOREPLIFETIME(ThisClass, bInit);
	DOREPLIFETIME(ThisClass, PrevValue);
}

void UNSCharacterAttributeSet::ExcuteEffectDuration(ECharacterAttributeType Type, float DurationValue, float DurationTime)
{

	FTimerDelegate DurationDelegate;
	DurationDelegate.BindUFunction(this, FName(TEXT("DurationEffect")), Type, DurationValue);

	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, DurationDelegate, DurationTime, false);

}

float UNSCharacterAttributeSet::GetCharacterAttributeValue(ECharacterAttributeType Type)
{
	switch (Type)
	{
	case ECharacterAttributeType::Level:
		return Level.GetAttributeValue();
		break;
	case ECharacterAttributeType::Strength:
		return Strength.GetAttributeValue();
		break;
	case ECharacterAttributeType::Dexterity:
		return Dexterity.GetAttributeValue();
		break;
	case ECharacterAttributeType::Constitution:
		return Constitution.GetAttributeValue();
		break;
	case ECharacterAttributeType::Intelligence:
		return Intelligence.GetAttributeValue();
		break;
	case ECharacterAttributeType::Wisdom:
		return Wisdom.GetAttributeValue();
		break;
	case ECharacterAttributeType::Charisma:
		return Charisma.GetAttributeValue();
		break;
	case ECharacterAttributeType::Hp:
		return Hp.GetAttributeValue();
		break;
	case ECharacterAttributeType::MaxHp:
		return MaxHp.GetAttributeValue();
		break;
	case ECharacterAttributeType::ArmorCount:
		return ArmorCount.GetAttributeValue();
		break;
	case ECharacterAttributeType::Initialtive:
		return Initialtive.GetAttributeValue();
		break;
	case ECharacterAttributeType::Accuracy:
		return Accuracy.GetAttributeValue();
		break;
	case ECharacterAttributeType::MoveRange:
		return MoveRange.GetAttributeValue();
		break;
	case ECharacterAttributeType::Exp:
		return Exp.GetAttributeValue();
		break;
	case ECharacterAttributeType::MaxExp:
		return MaxExp.GetAttributeValue();
		break;
	case ECharacterAttributeType::WeaponDamage:
		return WeaponDamage.GetAttributeValue();
		break;
	case ECharacterAttributeType::AbArmorCount:
		return AbArmorCount.GetAttributeValue();
		break;
	}

	return 0.f;
}