// Copyright Project NS


#include "NSWidget.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSWidget)

void UNSWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;

	OnSetWidgetController();
}

void UNSWidget::OnSetWidgetController_Implementation()
{
}
