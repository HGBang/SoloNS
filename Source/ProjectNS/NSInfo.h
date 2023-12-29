// Copyright Project NS

#pragma once

#include "CoreMinimal.h"

#include "Networking.h"
#include "Sockets.h"
#include "SocketSubSystem.h"
#include "Net/Unrealnetwork.h"

#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

#include "Kismet/KismetMathLibrary.h"

#include "Logging/StructuredLog.h"

#include "Engine/DataTable.h"

#include <map>

#include "UObject/NoExportTypes.h"
#include "NSInfo.generated.h"


#define DICE_MIN	1
#define DICE_FOUR	4
#define DICE_SIX	6
#define DICE_EIGHT	8
#define DICE_TEN	10
#define DICE_TWELVE	12
#define DICE_TWENTY	20

#define CUSTOM_DEPTH_RED 250

#define	SPELL_SAVE_BASE 8


DECLARE_LOG_CATEGORY_EXTERN(NS_Log, Log, All);


UENUM(BlueprintType)
enum class ECharacterAttributeType : uint8
{
	None,
	Level,
	Strength,
	Dexterity,
	Constitution,
	Intelligence,
	Wisdom,
	Charisma,
	Hp,
	MaxHp,
	ArmorCount,
	AbArmorCount,
	Initialtive,
	Accuracy,
	MoveRange,
	Exp,
	MaxExp,
	WeaponDamage,
	MagicDamage,
	SpellKnown,
	SpellSave,
	SpellAccuracy
};

/*
* ������ ���� �з�.
* ������ ����/������ ���� �����ȴ�.
*/
UENUM(BlueprintType)
enum class EDamageType : uint8
{
	Bludgeoning,			// ������
	Bludgeoning_Magical,	// ������ + ���� ���� ���� �� / ������ ���� ������ ���
	Piercing,				// ����
	Piercing_Magical,		// ���� + ���� ���� ���� �� / ������ ���� ������ ���
	Slashing,				// ����
	Slashing_Magical,		// ���� + ���� ���� ���� �� / ������ ���� ������ ���
	Cold,					// �ñ�
	Fire,					// ȭ��
	Lightning,				// ����
	Thunder,				// õ��(�Ҹ�)
	Phychic,				// ����
	Poison,					// ����
	Radiant,				// ����
	Necrotic				// ���
};

/*
* ������ �з�.
* �����̳� Ư�� �ൿ�� ���� ���ߵǴ� ���� �̻��̴�.
*/
UENUM(BlueprintType)
enum class EConditionType : uint8
{
	Blinded,		// ���
	Charmed,		// ��Ȥ
	Frightened,		// ����
	Grappled,		// �ӹ�
	Incapacitated,	// �ൿ �Ҵ�
	Invisible,		// ����
	Paralyzed,		// ����
	Petrified,		// ��ȭ
	Poisoned,		// �ߵ�
	Prone,			// �Ѿ���
	Restrained,		// �ӹ�
	Stunned,		// ���
	Unconscious,	// ���ǽ�
	Exhaustion		// Ż��
};

/*
* �׼��� �з�.
*/
UENUM(BlueprintType)
enum class EActionType : uint8
{
	Move,
	Minor,
	Major,
	ReAction
};

/* 
* ������ Ÿ��
* ���, �Һ� ��
*/
UENUM(BlueprintType)
enum class EItemType : uint8
{
	None,		// None
	Equippable,	// ��������
	Usable		// ��밡��
};

/*
* NSItem
* Actor ���·� ���忡 ���������� �ʰ�, ����ü ������ ������.
* ������ ������ ������ �ְ�, �������� ������ UI ���·θ� ������.
*/
USTRUCT(BlueprintType)
struct FNSItemInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FNSItemInfo();
	
	void SetName(const FText& InName);
	void SetAmount(int32 InAmount);
	void SetDescription(const FText& InDescription);
	void SetIcon(UTexture2D* InIcon);
	void SetValid(bool IsValid);

	void AddAmount(int32 InAmount);

public:
	/* ������ �̸� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText	Name;

	/* ������ ���� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32	Amount;

	/* ������ ���� (���콺 ȣ�� �� ��� ����) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText	Description;

	/* ������ ������ �̹��� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UTexture2D>	Icon;

	/* ��ȿ����? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool	Valid;
};

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSInfo : public UObject
{
	GENERATED_BODY()
};
