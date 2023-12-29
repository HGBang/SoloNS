// Copyright Project NS


#include "NSHUD.h"
#include "ProjectNS/UI/Widget/NSWidget.h"
#include "ProjectNS/UI/Controller/OverlayWidgetController.h"
#include "ProjectNS/CombatSystem/System/NSAbilityComponent.h"
#include "ProjectNS/CombatSystem/AttributeSet/NSAttributeSet.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSHUD)

void ANSHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UNSAbilityComponent* AC, UNSAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("ANSHUD::InitOverlay : OverlayWidgetClass is not vaild!"));
	checkf(OverlayWidgetControllerClass, TEXT("ANSHUD::InitOverlay : OverlayWidgetControllerClass is not vaild!"));

	// OverlayWidet ����
	OverlayWidget = CreateWidget<UNSWidget>(GetWorld(), OverlayWidgetClass);

	// OverlayWidgetController ���� �� Widget�� Controller ���
	FWidgetControllerParams Params(PC, PS, AC, AS);
	OverlayWidget->SetWidgetController(GetOverlayWidgetController(Params));

	// ȭ�鿡 �߰�
	OverlayWidget->AddToViewport();
}

UOverlayWidgetController* ANSHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	// ���� ������ ���� ������ְ�, ������ ����
	if (!IsValid(OverlayWidgetController))
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
	}

	return OverlayWidgetController;
}
