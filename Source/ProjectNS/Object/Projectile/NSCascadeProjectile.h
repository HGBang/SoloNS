// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "NSBaseProjectile.h"
#include "NSCascadeProjectile.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSCascadeProjectile : public ANSBaseProjectile
{
	GENERATED_BODY()

public:
	ANSCascadeProjectile();

protected:
	UPROPERTY(Category = "NS|Component", EditAnywhere, BlueprintReadWrite)
		TObjectPtr<UParticleSystemComponent>	ProjectileCascade;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
		virtual void ProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult) override;

protected:
	UFUNCTION()
		void ParticleFinished(UParticleSystemComponent* System);
	
};
