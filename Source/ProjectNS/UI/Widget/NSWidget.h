// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "Blueprint/UserWidget.h"
#include "NSWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/* WidgetController ��� �Լ� */
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	/* �� Widget���� �ʱ�ȭ �� �͵� ���� */
	virtual void Init() {}

protected:
	/*
	* WidgetController�� ��ϵǰ� �ؾ��� �͵��� �߰�(Delegate ��� ��)
	* Blueprint���� ��� ����
	*/
	UFUNCTION(BlueprintNativeEvent)
	void OnSetWidgetController();
	
public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
};
