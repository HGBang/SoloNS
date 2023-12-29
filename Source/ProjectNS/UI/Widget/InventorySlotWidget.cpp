// Copyright Project NS


#include "InventorySlotWidget.h"
#include "Components/SizeBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(InventorySlotWidget)

UInventorySlotWidget::UInventorySlotWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SlotIndex(0)
{
}

void UInventorySlotWidget::Init()
{
	if (IsValid(BackTexture))
		BackgroundImage->SetBrushFromTexture(BackTexture);
}

void UInventorySlotWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInventorySlotWidget::SetSlotIndex(int32 InSlotIndex)
{
	SlotIndex = InSlotIndex;
}

void UInventorySlotWidget::UpdateSlot(int32 InSlotIndex, const FNSItemInfo& InItem)
{
	SlotIndex = InSlotIndex;

	ItemName = InItem.Name;
	ItemDescription = InItem.Description;
	ItemThumbnail->SetBrushFromTexture(InItem.Icon);

	if (InItem.Amount > 0)
		AmountText->SetText(FText::AsNumber(InItem.Amount));
	else
		AmountText->SetText(FText());
}
