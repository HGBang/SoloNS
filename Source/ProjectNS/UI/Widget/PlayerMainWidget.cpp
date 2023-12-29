// Copyright Project NS


#include "PlayerMainWidget.h"
#include "CharacterSheetWidget.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(PlayerMainWidget)

UPlayerMainWidget::UPlayerMainWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UPlayerMainWidget::Init()
{
	if (IsValid(CharacterSheetWidget))
	{
		CharacterSheetWidget->Init();
		CharacterSheetWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UPlayerMainWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UPlayerMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
}
