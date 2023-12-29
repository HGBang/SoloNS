// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "NSWidget.h"
#include "InventorySlotWidget.generated.h"

class USizeBox;
class UButton;
class UTextBlock;
class UImage;

/**
 * 
 */
UCLASS()
class PROJECTNS_API UInventorySlotWidget : public UNSWidget
{
	GENERATED_BODY()

public:
	UInventorySlotWidget(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

protected:
	virtual void NativePreConstruct() final;
	virtual void NativeConstruct() final;

public:
	void SetSlotIndex(int32 InSlotIndex);
	void UpdateSlot(int32 InSlotIndex, const FNSItemInfo& InItem);

public:
	int32 GetSlotIndex() const { return SlotIndex; }
	const FText& GetItemName() const { return ItemName; }

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NS|Widget")
	TObjectPtr<UTexture2D> BackTexture;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<USizeBox> RootSizeBox;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UButton> SlotButton;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UImage> BackgroundImage;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UImage> ItemThumbnail;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UTextBlock> AmountText;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget")
	FText ItemName;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget")
	FText ItemDescription;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget")
	int32 SlotIndex;
};
