// Copyright Project NS

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OutLineInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UOutLineInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTNS_API IOutLineInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TurnOnOutline();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TurnOffOutline();
};
