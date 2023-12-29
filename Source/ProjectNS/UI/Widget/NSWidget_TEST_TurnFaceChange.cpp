// Copyright Project NS


#include "NSWidget_TEST_TurnFaceChange.h"
#include "../../Character/Player/NSPlayerCharacter.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSWidget_TEST_TurnFaceChange)

UNSWidget_TEST_TurnFaceChange::UNSWidget_TEST_TurnFaceChange() :
	Super(),
	NowTurn(0)
{
}

void UNSWidget_TEST_TurnFaceChange::Init()
{
	Super::Init();
}

void UNSWidget_TEST_TurnFaceChange::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UNSWidget_TEST_TurnFaceChange::NativeConstruct()
{
	Super::NativeConstruct();

	IcoBox = Cast<UHorizontalBox>(GetWidgetFromName(TEXT("IcoBox")));

	for (int i = 0; i < 9; ++i) {
		UImage* Image = Cast<UImage>(GetWidgetFromName("Ico" + i));

		Image->SetVisibility(ESlateVisibility::Hidden);
		
		if (Image) 
			EmptyImageArr.Add(Image);
	}
}

void UNSWidget_TEST_TurnFaceChange::UpdateTurn()
{
	if (ImageArr.Num()) {
		UpdateFaceHighlight(++NowTurn);
	}
}

void UNSWidget_TEST_TurnFaceChange::SetVecFaceImages(const TArray<TObjectPtr<ANSCharacter>>& Members)
{
	uint8 Num = Members.Num();

	int startNum = (9 - Num) / 2;


	for (const auto& Member : Members) {

		FString Path = "";

		const auto& Image = EmptyImageArr[startNum];
		EmptyImageArr.RemoveAt(startNum++);

		Image->SetVisibility(ESlateVisibility::Visible);

		if (IsValid(Cast<ANSPlayerCharacter>(Member))) {
			Path = FString("/Engine/EngineResources/AICON-Green.AICON-Green");

			UTexture2D* Texture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *Path));
			Image->SetBrushFromTexture(Texture);
		}
		else {
			Path = FString("/Engine/EngineResources/AICON-Red.AICON-Red");

			UTexture2D* Texture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *Path));
			Image->SetBrushFromTexture(Texture);
		}


		ImageArr.Add(Image);
	}

	UpdateFaceHighlight(NowTurn);
}

void UNSWidget_TEST_TurnFaceChange::UpdateFaceHighlight(int idx)
{
	if (ImageArr.Num() && idx > ImageArr.Num()) {
		for (int i = 0; i < ImageArr.Num(); ++i) {
			if (i == idx) {
				ImageArr[i]->SetOpacity(1.f);
			}
			else {
				ImageArr[i]->SetOpacity(0.3f);
			}
		}
	}
}
