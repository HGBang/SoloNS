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

	// OverlayWidet 생성
	OverlayWidget = CreateWidget<UNSWidget>(GetWorld(), OverlayWidgetClass);

	// OverlayWidgetController 생성 및 Widget에 Controller 등록
	FWidgetControllerParams Params(PC, PS, AC, AS);
	OverlayWidget->SetWidgetController(GetOverlayWidgetController(Params));

	// 화면에 추가
	OverlayWidget->AddToViewport();
}

UOverlayWidgetController* ANSHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	// 만약 없으면 새로 만들어주고, 있으면 리턴
	if (!IsValid(OverlayWidgetController))
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
	}

	return OverlayWidgetController;
}
