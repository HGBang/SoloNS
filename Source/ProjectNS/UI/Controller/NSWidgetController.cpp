// Copyright Project NS


#include "NSWidgetController.h"
#include "ProjectNS/CombatSystem/System/NSAbilityComponent.h"
#include "ProjectNS/CombatSystem/AttributeSet/NSAttributeSet.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSWidgetController)

void UNSWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& InParams)
{
	PlayerController =	InParams.PlayerController;
	PlayerState =		InParams.PlayerState;
	AbilityComponent =	InParams.AbilityComponent;
	AttributeSet =		InParams.AttributeSet;
}
