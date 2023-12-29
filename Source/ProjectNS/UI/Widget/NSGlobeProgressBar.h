// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "NSWidget.h"
#include "NSGlobeProgressBar.generated.h"

class USizeBox;
class UOverlay;
class UImage;
class UProgressBar;

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSGlobeProgressBar : public UNSWidget
{
	GENERATED_BODY()

public:
	UNSGlobeProgressBar(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativePreConstruct() final;
	virtual void NativeConstruct() final;

protected:
	/* RootBoxSize�� ����, PreConstruct ������ ȣ�� */
	void UpdateBoxSize();

	/* BackGroundImage ����, PreConstruct ������ ȣ�� */
	void UpdateBackgroundImage();

	/* GlobeProgressBar ����(FillImage�� Padding), PreConstruct ������ ȣ�� */
	void UpdateGlobeProgressBar();

	/* ForegroundImage ����(Image�� Padding), PreConstruct ������ ȣ�� */
	void UpdateForegroundImage();
	

protected:
	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<USizeBox>		RootSizeBox;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UOverlay>		RootOverlay;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UImage>			BackgroundImage;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UProgressBar>	GlobeProgressBar;

	UPROPERTY(BlueprintReadOnly, Category = "NS|Widget", meta = (BindWidget))
	TObjectPtr<UImage>			ForegroundImage;

protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "NS|WidgetProperty", meta = (AllowPrivateAccess = "true"))
	float BoxWidth;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "NS|WidgetProperty", meta = (AllowPrivateAccess = "true"))
	float BoxHeight;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "NS|WidgetProperty", meta = (AllowPrivateAccess = "true"))
	FSlateBrush BackGroundImageBrush;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "NS|WidgetProperty", meta = (AllowPrivateAccess = "true"))
	FSlateBrush ProgressBarImageBrush;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "NS|WidgetProperty", meta = (AllowPrivateAccess = "true"))
	float GlobePadding;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "NS|WidgetProperty", meta = (AllowPrivateAccess = "true"))
	FSlateBrush ForegoundImageBrush;
};
