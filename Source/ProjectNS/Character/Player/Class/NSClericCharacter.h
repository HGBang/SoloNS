// Copyright Project NS

#pragma once

#include "../NSPlayerCharacter.h"
#include "NSClericCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSClericCharacter : public ANSPlayerCharacter
{
	GENERATED_BODY()
	
public:
	ANSClericCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void CalculateAccuracy(ANSCharacter* Target) override;
};
