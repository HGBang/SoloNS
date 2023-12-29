// Copyright Project NS

#pragma once

#include "../NSPlayerCharacter.h"
#include "NSMagicianCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSMagicianCharacter : public ANSPlayerCharacter
{
	GENERATED_BODY()
	
public:
	ANSMagicianCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void CalculateAccuracy(ANSCharacter* Target) override;
};
