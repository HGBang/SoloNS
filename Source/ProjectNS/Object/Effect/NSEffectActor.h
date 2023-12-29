// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "GameFramework/Actor.h"
#include "NSEffectActor.generated.h"

UCLASS()
class PROJECTNS_API ANSEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANSEffectActor();

protected:
	UPROPERTY(Category = "NS|Component", EditAnywhere, BlueprintReadWrite)
		TObjectPtr<UParticleSystemComponent>	EffectCascade;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION()
		void ParticleFinished(UParticleSystemComponent* System);

};
