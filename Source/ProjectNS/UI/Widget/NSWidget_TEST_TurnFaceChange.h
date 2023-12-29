// Copyright Project NS

#pragma once

#include "NSWidget.h"
#include "NSWidget_TEST_TurnFaceChange.generated.h"

class UHorizontalBox;
class ANSCharacter;
class UImage;

// TEST TEST TEST
// TODO : ����� �� Ŭ������ ���� �ʿ�.
UCLASS()
class PROJECTNS_API UNSWidget_TEST_TurnFaceChange : public UNSWidget
{
	GENERATED_BODY()

public:
	UNSWidget_TEST_TurnFaceChange();
	virtual void Init() override;

protected:
	virtual void NativePreConstruct() final;
	virtual void NativeConstruct() final;

protected:
	TObjectPtr<UHorizontalBox> IcoBox;
	TArray<TObjectPtr<UImage>> ImageArr;
	TArray<TObjectPtr<UImage>> EmptyImageArr;

	uint8	NowTurn;

public:
	// TEST TEST TEST
	// TODO : ����� �� �Լ��� ���� �ʿ�.
	UFUNCTION(BlueprintCallable)
	void UpdateTurn();

	void SetVecFaceImages(const TArray<TObjectPtr<ANSCharacter>>& Members);

private:
	void UpdateFaceHighlight(int idx);
};
