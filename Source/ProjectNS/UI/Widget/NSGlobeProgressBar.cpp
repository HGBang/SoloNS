// Copyright Project NS


#include "NSGlobeProgressBar.h"
#include "Components/SizeBox.h"
#include "Components/Overlay.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Components/OverlaySlot.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSGlobeProgressBar)

UNSGlobeProgressBar::UNSGlobeProgressBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, BoxWidth(0.0f)
	, BoxHeight(0.0f)
	, BackGroundImageBrush{}
	, ProgressBarImageBrush{}
	, GlobePadding(0.0f)
	, ForegoundImageBrush{}
{
}

void UNSGlobeProgressBar::NativePreConstruct()
{
	Super::NativePreConstruct();

	UpdateBoxSize();
	UpdateBackgroundImage();
	UpdateGlobeProgressBar();
	UpdateForegroundImage();
}

void UNSGlobeProgressBar::NativeConstruct()
{
	Super::NativeConstruct();


}

void UNSGlobeProgressBar::UpdateBoxSize()
{
	if (IsValid(RootSizeBox))
	{
		RootSizeBox->SetWidthOverride(BoxWidth);
		RootSizeBox->SetHeightOverride(BoxHeight);
	}

	else
		UE_LOG(LogTemp, Warning, TEXT("UNSGlobeProgressBar::UpdateBoxSize : RootSizeBox is not valid!"));
}

void UNSGlobeProgressBar::UpdateBackgroundImage()
{
	if (IsValid(BackgroundImage))
		BackgroundImage->SetBrush(BackGroundImageBrush);

	else
		UE_LOG(LogTemp, Warning, TEXT("UNSGlobeProgressBar::UpdateBackgroundImage : BackgroundImage is not valid!"));
}

void UNSGlobeProgressBar::UpdateGlobeProgressBar()
{
	if (IsValid(GlobeProgressBar))
	{
		FProgressBarStyle BarStyle;
		// BackgroundImage는 따로 사용하기때문에 투명하게 변경
		BarStyle.BackgroundImage.TintColor = FSlateColor(FColor(1, 1, 1, 0));
		BarStyle.FillImage = ProgressBarImageBrush;
		GlobeProgressBar->SetWidgetStyle(BarStyle);

		// Padding
		if (UOverlaySlot* Overlay = Cast<UOverlaySlot>(GlobeProgressBar->Slot))
			Overlay->SetPadding(FMargin(GlobePadding, GlobePadding, GlobePadding, GlobePadding));
	}

	else
		UE_LOG(LogTemp, Warning, TEXT("UNSGlobeProgressBar::UpdateGlobeProgressBar : GlobeProgressBar is not valid!"));
}

void UNSGlobeProgressBar::UpdateForegroundImage()
{
	if (IsValid(ForegroundImage))
	{
		ForegroundImage->SetBrush(ForegoundImageBrush);

		// Padding
		if (UOverlaySlot* Overlay = Cast<UOverlaySlot>(ForegroundImage->Slot))
			Overlay->SetPadding(FMargin(GlobePadding, GlobePadding, GlobePadding, GlobePadding));
	}

	else
		UE_LOG(LogTemp, Warning, TEXT("UNSGlobeProgressBar::UpdateForegroundImage : ForegroundImage is not valid!"));
}
