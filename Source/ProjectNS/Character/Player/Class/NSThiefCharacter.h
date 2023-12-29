// Copyright Project NS

#pragma once

#include "../NSPlayerCharacter.h"
#include "NSThiefCharacter.generated.h"

UCLASS()
class PROJECTNS_API ANSThiefCharacter : public ANSPlayerCharacter
{
	GENERATED_BODY()
	
public:
	ANSThiefCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void CalculateAccuracy(ANSCharacter* Target) override;
};
