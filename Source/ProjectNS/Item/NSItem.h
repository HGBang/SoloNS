// Copyright Project NS

#pragma once

#include "../NSInfo.h"
#include "UObject/NoExportTypes.h"
#include "NSItem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, config = Engine)
class PROJECTNS_API UNSItem : public UObject
{
	GENERATED_BODY()
	
public:
	UNSItem();

public:
	void SetItemInfo(const FNSItemInfo& InItemInfo);
	void AddItemAmount(int32 InAmount);

public:
	const FNSItemInfo& GetItemInfo() const { return ItemInfo; }
	const FText& GetItemName() const { return ItemInfo.Name; }
	int32 GetItemAmount() const { return ItemInfo.Amount; }
	const FText& GetItemDescription() const { return ItemInfo.Description; }
	const UTexture2D* GetItemIcon()	const { return ItemInfo.Icon; }

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NS|Item", meta = (AllowPrivateAccess = true))
	FNSItemInfo ItemInfo;
};
