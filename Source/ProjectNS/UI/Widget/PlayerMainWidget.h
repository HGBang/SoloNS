// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "NSWidget.h"
#include "PlayerMainWidget.generated.h"

class UCharacterSheetWidget;

/**
 * 
 */
UCLASS()
class PROJECTNS_API UPlayerMainWidget : public UNSWidget
{
	GENERATED_BODY()

public:
	UPlayerMainWidget(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

protected:
	virtual void NativePreConstruct() final;
	virtual void NativeConstruct() final;

public:
	UCharacterSheetWidget* GetCharacterSheetWidget() const { return CharacterSheetWidget; }

protected:
	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UCharacterSheetWidget> CharacterSheetWidget;
};
