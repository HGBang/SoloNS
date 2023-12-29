// Copyright Project NS


#include "CharacterSheetWidget.h"
#include "InventoryWidget.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterSheetWidget)

UCharacterSheetWidget::UCharacterSheetWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UCharacterSheetWidget::Init()
{
	if (IsValid(InventoryWidget))
		InventoryWidget->Init();
}

void UCharacterSheetWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UCharacterSheetWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCharacterSheetWidget::UpdateInventorySlots(const TArray<TObjectPtr<UNSItem>>& Inventory)
{
	InventoryWidget->UpdateInventorySlots(Inventory);
}
