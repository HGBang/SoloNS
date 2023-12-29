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
	// ���� �������� �ִ��� ��
	for (auto& Item : Inventory)
	{
		// ���� �������� �ִٸ�
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
	// TODO : Inventory�� ���� 70ĭ�ε� �������� 70���� �Ѿ ������ ��쿡 ���� üũ �ʿ�
	// TODO : ���� �������� �������� Stacking�� �ʿ�
	if (!IsValid(InItem)) return;

	// ���� �������� �ִ��� ��
	if (UNSItem* Item = GetSameItem(InItem))
		Item->AddItemAmount(InItem->GetItemAmount());

	Inventory.Add(InItem);
	CharacterSheetWidget->UpdateInventorySlots(Inventory);
}
