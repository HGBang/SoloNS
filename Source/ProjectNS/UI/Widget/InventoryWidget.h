// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "NSWidget.h"
#include "InventoryWidget.generated.h"

class USizeBox;
class UBorder;
class UGridPanel;
class UButton;
class UNSItem;
class UInventorySlotWidget;

/**
 * 
 */
UCLASS()
class PROJECTNS_API UInventoryWidget : public UNSWidget
{
	GENERATED_BODY()

public:
	UInventoryWidget(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

protected:
	virtual void NativeOnInitialized() final;
	virtual void NativePreConstruct() final;
	virtual void NativeConstruct() final;

public:
	void CreateInventorySlots();
	void UpdateInventorySlots(const TArray<TObjectPtr<UNSItem>>& Inventory);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<USizeBox> RootSizeBox;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UBorder> RootBorder;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UGridPanel> ItemSlotGrid;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UButton> AllCategoryButton;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UButton> EquipCategoryButton;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UButton> TestCategoryButton;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "NS|Widget", meta = (AllowPrivateAccess = true))
	int32 ItemSlotRow;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "NS|Widget", meta = (AllowPrivateAccess = true))
	int32 ItemSlotColumn;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Widget", meta = (AllowPrivateAccess = true))
	TArray<TObjectPtr<UInventorySlotWidget>> InventorySlots;
};
