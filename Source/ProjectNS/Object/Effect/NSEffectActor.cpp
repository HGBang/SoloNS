// Copyright Project NS


#include "NSEffectActor.h"

// Sets default values
ANSEffectActor::ANSEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Craete Component
	EffectCascade = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EffectCascade"));

	// Component Delegate
	EffectCascade->OnSystemFinished.AddDynamic(this, &ANSEffectActor::ParticleFinished);

	// Replicate
	EffectCascade->SetIsReplicated(true);

}

// Called when the game starts or when spawned
void ANSEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANSEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANSEffectActor::ParticleFinished(UParticleSystemComponent* System)
{
}

