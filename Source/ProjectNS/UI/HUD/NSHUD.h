// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "GameFramework/HUD.h"
#include "NSHUD.generated.h"

class UNSWidget;
class UOverlayWidgetController;
class UNSAbilityComponent;
class UNSAttributeSet;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSHUD : public AHUD
{
	GENERATED_BODY()

public:
	/* NSCharacter에서 PlayerController와 PlayerState가 모두 준비된 상태에서 호출 */
	void InitOverlay(APlayerController* PC, APlayerState* PS, UNSAbilityComponent* AC, UNSAttributeSet* AS);

	/*
	* NSHUD의 멤버변수 OverlayWidgetController를 반환한다.
	* 만약 생성되지 않았다면, 등록된 OverlayWidgetControllerClass로 생성해서 멤버변수에 등록하고 반환한다.
	*/
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	
public:
	/* 화면에 메인 HUD로 출력할 Widget */
	UPROPERTY()
	TObjectPtr<UNSWidget> OverlayWidget;

private:
	/* 생성할 WidgetClass, 등록하지 않을 시 crash */
	UPROPERTY(EditDefaultsOnly, Category = "NS|HUD", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UNSWidget> OverlayWidgetClass;

	/* Widget과의 연동을 위한 WidgetController */
	UPROPERTY(VisibleAnywhere, Category = "NS|HUD", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	/* 생성할 WidgetControllerClass, 등록하지 않을 시 crash */
	UPROPERTY(EditDefaultsOnly, Category = "NS|HUD", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
