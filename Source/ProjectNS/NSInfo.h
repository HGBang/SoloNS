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
* 피해의 유형 분류.
* 공격의 무기/마법에 의해 결정된다.
*/
UENUM(BlueprintType)
enum class EDamageType : uint8
{
	Bludgeoning,			// 때리기
	Bludgeoning_Magical,	// 때리기 + 마법 무기 장착 시 / 마법에 의한 피해일 경우
	Piercing,				// 관통
	Piercing_Magical,		// 관통 + 마법 무기 장착 시 / 마법에 의한 피해일 경우
	Slashing,				// 베기
	Slashing_Magical,		// 베기 + 마법 무기 장착 시 / 마법에 의한 피해일 경우
	Cold,					// 냉기
	Fire,					// 화염
	Lightning,				// 번개
	Thunder,				// 천둥(소리)
	Phychic,				// 정신
	Poison,					// 독성
	Radiant,				// 광휘
	Necrotic				// 사령
};

/*
* 상태의 분류.
* 마법이나 특정 행동에 의해 유발되는 상태 이상이다.
*/
UENUM(BlueprintType)
enum class EConditionType : uint8
{
	Blinded,		// 장님
	Charmed,		// 매혹
	Frightened,		// 공포
	Grappled,		// 속박
	Incapacitated,	// 행동 불능
	Invisible,		// 투명
	Paralyzed,		// 마비
	Petrified,		// 석화
	Poisoned,		// 중독
	Prone,			// 넘어짐
	Restrained,		// 속박
	Stunned,		// 충격
	Unconscious,	// 무의식
	Exhaustion		// 탈진
};

/*
* 액션의 분류.
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
* 아이템 타입
* 장비, 소비 등
*/
UENUM(BlueprintType)
enum class EItemType : uint8
{
	None,		// None
	Equippable,	// 장착가능
	Usable		// 사용가능
};

/*
* NSItem
* Actor 형태로 월드에 실존하지는 않고, 구조체 단위로 존재함.
* 아이템 정보를 가지고 있고, 아이템의 정보는 UI 형태로만 보여짐.
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
	/* 아이템 이름 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText	Name;

	/* 아이템 개수 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32	Amount;

	/* 아이템 설명 (마우스 호버 시 띄울 설명) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText	Description;

	/* 아이템 아이콘 이미지 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UTexture2D>	Icon;

	/* 유효한지? */
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
