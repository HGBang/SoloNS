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
	/* RootBoxSize를 조정, PreConstruct 시점에 호출 */
	void UpdateBoxSize();

	/* BackGroundImage 세팅, PreConstruct 시점에 호출 */
	void UpdateBackgroundImage();

	/* GlobeProgressBar 세팅(FillImage와 Padding), PreConstruct 시점에 호출 */
	void UpdateGlobeProgressBar();

	/* ForegroundImage 세팅(Image와 Padding), PreConstruct 시점에 호출 */
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
