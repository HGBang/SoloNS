// Copyright Project NS


#include "CharacterSheetComponent.h"
#include "../Item/NSItem.h"
#include "../UI/Widget/CharacterSheetWidget.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterSheetComponent)

UCharacterSheetComponent::UCharacterSheetComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UCharacterSheetComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCharacterSheetComponent::AppendItem(UNSItem* InItem)
{
}

UNSItem* UCharacterSheetComponent::GetSameItem(UNSItem* InItem)
{
	// 같은 아이템이 있는지 비교
	for (auto& Item : Inventory)
	{
		// 같은 아이템이 있다면
		if (Item->GetItemName().EqualTo(InItem->GetItemName()))
			return Item;
	}
	return nullptr;
}

void UCharacterSheetComponent::SetCharacterSheetWidget(UCharacterSheetWidget* InCharacterSheetWidget)
{
	CharacterSheetWidget = InCharacterSheetWidget;
}

void UCharacterSheetComponent::AddItem(UNSItem* InItem)
{
	// TODO : Inventory가 현재 70칸인데 아이템이 70개를 넘어서 들어오는 경우에 대한 체크 필요
	// TODO : 같은 아이템이 들어왔을때 Stacking이 필요
	if (!IsValid(InItem)) return;

	// 같은 아이템이 있는지 비교
	if (UNSItem* Item = GetSameItem(InItem))
		Item->AddItemAmount(InItem->GetItemAmount());

	Inventory.Add(InItem);
	CharacterSheetWidget->UpdateInventorySlots(Inventory);
}
