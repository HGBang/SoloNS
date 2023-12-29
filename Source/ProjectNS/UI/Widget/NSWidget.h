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
	/* WidgetController 등록 함수 */
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	/* 각 Widget마다 초기화 할 것들 정의 */
	virtual void Init() {}

protected:
	/*
	* WidgetController가 등록되고 해야할 것들을 추가(Delegate 등록 등)
	* Blueprint에서 등록 가능
	*/
	UFUNCTION(BlueprintNativeEvent)
	void OnSetWidgetController();
	
public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
};
