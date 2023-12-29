// Copyright Project NS


#include "NSItem.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSItem)

UNSItem::UNSItem()
	: Super()
{
}

void UNSItem::SetItemInfo(const FNSItemInfo& InItemInfo)
{
	ItemInfo.Name = InItemInfo.Name;
	ItemInfo.Description = InItemInfo.Description;
	ItemInfo.Amount = InItemInfo.Amount;
	ItemInfo.Icon = InItemInfo.Icon;
	ItemInfo.Valid = InItemInfo.Valid;
}

void UNSItem::AddItemAmount(int32 InAmount)
{
	ItemInfo.AddAmount(InAmount);
}
