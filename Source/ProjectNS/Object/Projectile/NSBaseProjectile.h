// Copyright Project NS

#pragma once

#include "../../NSInfo.h"
#include "GameFramework/Actor.h"
#include "NSBaseProjectile.generated.h"

class UNSGamePlayEffect;
class USphereComponent;
class ANSCharacter;
class UProjectileMovementComponent;

UCLASS()
class PROJECTNS_API ANSBaseProjectile : public AActor
{
	GENERATED_BODY()

public:
	ANSBaseProjectile();

protected:
	UPROPERTY(Category = "NS|Component", EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USphereComponent>		ProjectileBody;

	UPROPERTY(Category = "NS|Component", EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent>	ProjectileMesh;

	UPROPERTY(Category = "NS|Component", EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION()
		virtual void ProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);

};
