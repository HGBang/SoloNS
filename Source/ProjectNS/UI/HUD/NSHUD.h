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
	/* NSCharacter���� PlayerController�� PlayerState�� ��� �غ�� ���¿��� ȣ�� */
	void InitOverlay(APlayerController* PC, APlayerState* PS, UNSAbilityComponent* AC, UNSAttributeSet* AS);

	/*
	* NSHUD�� ������� OverlayWidgetController�� ��ȯ�Ѵ�.
	* ���� �������� �ʾҴٸ�, ��ϵ� OverlayWidgetControllerClass�� �����ؼ� ��������� ����ϰ� ��ȯ�Ѵ�.
	*/
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	
public:
	/* ȭ�鿡 ���� HUD�� ����� Widget */
	UPROPERTY()
	TObjectPtr<UNSWidget> OverlayWidget;

private:
	/* ������ WidgetClass, ������� ���� �� crash */
	UPROPERTY(EditDefaultsOnly, Category = "NS|HUD", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UNSWidget> OverlayWidgetClass;

	/* Widget���� ������ ���� WidgetController */
	UPROPERTY(VisibleAnywhere, Category = "NS|HUD", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	/* ������ WidgetControllerClass, ������� ���� �� crash */
	UPROPERTY(EditDefaultsOnly, Category = "NS|HUD", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
