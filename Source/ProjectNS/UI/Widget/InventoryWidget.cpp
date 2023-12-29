// Copyright Project NS


#include "InventoryWidget.h"
#include "Components/SizeBox.h"
#include "Components/Border.h"
#include "Components/GridPanel.h"
#include "Components/Button.h"
#include "Components/GridSlot.h"
#include "Blueprint/WidgetTree.h"
#include "InventorySlotWidget.h"
#include "../../Item/NSItem.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(InventoryWidget)

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, ItemSlotRow(10)
	, ItemSlotColumn(7)
{
}

void UInventoryWidget::Init()
{
	InventorySlots.Init(nullptr, ItemSlotRow * ItemSlotColumn);

	// WidgetTree에서 모든 Widget을 가져와서 InventorySlot들을 초기화 한다.
	TArray<UWidget*> widgets = ItemSlotGrid->GetAllChildren();
	//WidgetTree->GetAllWidgets(widgets);
	
	UInventorySlotWidget* InventorySlot = nullptr;
	for (auto& widget : widgets)
	{
		InventorySlot = Cast<UInventorySlotWidget>(widget);
		if (!IsValid(InventorySlot)) continue;

		InventorySlot->Init();

		int32 slotIndex = ItemSlotGrid->GetChildIndex(widget);
		InventorySlot->SetSlotIndex(slotIndex);
		InventorySlots[slotIndex] = InventorySlot;
	}
}

void UInventoryWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//CreateInventorySlots();
}

void UInventoryWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInventoryWidget::CreateInventorySlots()
{
	int32 SlotNumber = ItemSlotRow * ItemSlotColumn;
	for (int32 i = 0; i < SlotNumber; ++i)
	{
		UInventorySlotWidget* ItemSlot = CreateWidget<UInventorySlotWidget>(this, UInventorySlotWidget::StaticClass());
		ItemSlotGrid->AddChildToGrid(ItemSlot, i / ItemSlotColumn, i % ItemSlotColumn);
	}
}

void UInventoryWidget::UpdateInventorySlots(const TArray<TObjectPtr<UNSItem>>& Inventory)
{
	// TODO : 현재는 Inventory를 받아와서 Inventory의 아이템 개수만큼만 업데이트를 하는데 방식 변경이 필요함
	int32 ItemCount = Inventory.Num();
	for (int32 i = 0; i < ItemCount; ++i)
	{
		InventorySlots[i]->UpdateSlot(i, Inventory[i]->GetItemInfo());
	}
}
