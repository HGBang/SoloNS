// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "UObject/NoExportTypes.h"
#include "NSWidgetController.generated.h"

class UNSAbilityComponent;
class UNSAttributeSet;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

public:
	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* PC, APlayerState* PS, UNSAbilityComponent* AC, UNSAttributeSet* AS)
		: PlayerController(PC)
		, PlayerState(PS)
		, AbilityComponent(AC)
		, AttributeSet(AS)
	{}

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NS|WidgetController")
	TObjectPtr<APlayerController>	PlayerController = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NS|WidgetController")
	TObjectPtr<APlayerState>		PlayerState = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NS|WidgetController")
	TObjectPtr<UNSAbilityComponent>	AbilityComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NS|WidgetController")
	TObjectPtr<UNSAttributeSet>		AttributeSet = nullptr;
};

/**
 * 
 */
UCLASS()
class PROJECTNS_API UNSWidgetController : public UObject
{
	GENERATED_BODY()
	
public:
	/* FWidgetControllerParams로 멤버 변수들 세팅 */
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& InParams);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "NS|WidgetController")
	TObjectPtr<APlayerController>	PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "NS|WidgetController")
	TObjectPtr<APlayerState>		PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "NS|WidgetController")
	TObjectPtr<UNSAbilityComponent> AbilityComponent;

	UPROPERTY(BlueprintReadOnly, Category = "NS|WidgetController")
	TObjectPtr<UNSAttributeSet>		AttributeSet;
};
