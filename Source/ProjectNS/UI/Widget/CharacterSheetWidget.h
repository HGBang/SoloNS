// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "NSWidget.h"
#include "CharacterSheetWidget.generated.h"

class UInventoryWidget;

/**
 * 
 */
UCLASS()
class PROJECTNS_API UCharacterSheetWidget : public UNSWidget
{
	GENERATED_BODY()

public:
	UCharacterSheetWidget(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

protected:
	virtual void NativePreConstruct() final;
	virtual void NativeConstruct() final;

public:
	void UpdateInventorySlots(const TArray<TObjectPtr<UNSItem>>& Inventory);

public:
	UInventoryWidget* GetInventoryWidget() const { return InventoryWidget; }

protected:
	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UInventoryWidget> InventoryWidget;
};
