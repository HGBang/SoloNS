// Copyright Project NS


#include "NSCascadeProjectile.h"

ANSCascadeProjectile::ANSCascadeProjectile() : 
	Super()
{
	// Craete Component
	ProjectileCascade = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ProjectileCascade"));

	// Component Delegate
	ProjectileCascade->OnSystemFinished.AddDynamic(this, &ANSCascadeProjectile::ParticleFinished);

	// Replicate
	ProjectileCascade->SetIsReplicated(true);
}

void ANSCascadeProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ANSCascadeProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANSCascadeProjectile::ProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::ProjectileBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void ANSCascadeProjectile::ParticleFinished(UParticleSystemComponent* System)
{
	Destroy();
}
