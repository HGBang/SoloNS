// Copyright Project NS


#include "NSNiagaraProjectile.h"
#include "NiagaraComponent.h"

ANSNiagaraProjectile::ANSNiagaraProjectile() : 
	Super()
{
	// Craete Component
	ProjectileNiagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ProjectileNiagara"));

	// Delegate Component
	ProjectileNiagara->OnSystemFinished.AddDynamic(this, &ANSNiagaraProjectile::ParticleFinished);

	// Replicate
	ProjectileNiagara->SetIsReplicated(true);

}

void ANSNiagaraProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ANSNiagaraProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANSNiagaraProjectile::ProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::ProjectileBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void ANSNiagaraProjectile::ParticleFinished(UNiagaraComponent* System)
{
	Destroy();
}
