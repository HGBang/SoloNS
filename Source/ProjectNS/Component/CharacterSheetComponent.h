// Copyright Project NS

#pragma once

#include "../NSInfo.h"
#include "Components/ActorComponent.h"
#include "CharacterSheetComponent.generated.h"

class UNSItem;
class UCharacterSheetWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTNS_API UCharacterSheetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCharacterSheetComponent();

protected:
	virtual void BeginPlay() override;

	void AppendItem(UNSItem* InItem);
	UNSItem* GetSameItem(UNSItem* InItem);

public:
	void SetCharacterSheetWidget(UCharacterSheetWidget* InCharacterSheetWidget);

	UFUNCTION(BlueprintCallable)
	void AddItem(UNSItem* InItem);

public:
	const TArray<TObjectPtr<UNSItem>>& GetInventory() const { return Inventory; }

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NS|Inventory", meta = (AllowPrivateAccess = true))
	TArray<TObjectPtr<UNSItem>> Inventory;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "NS|Inventory", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCharacterSheetWidget> CharacterSheetWidget;
};
