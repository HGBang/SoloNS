// Copyright Project NS


#include "NSBaseProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../../CombatSystem/System/NSAbilityComponent.h"
#include "../../Character/NSCharacter.h"

// Sets default values
ANSBaseProjectile::ANSBaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Create Component
	ProjectileBody = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileBody"));
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));


	// Component Setting
	SetRootComponent(ProjectileBody);
	ProjectileBody->SetGenerateOverlapEvents(true);

	ProjectileMesh->SetupAttachment(ProjectileBody);
	ProjectileMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	// Component Delegate
	ProjectileBody->OnComponentBeginOverlap.AddDynamic(this, &ANSBaseProjectile::ProjectileBeginOverlap);

	// Replecate
	ProjectileBody->SetIsReplicated(true);
	ProjectileMesh->SetIsReplicated(true);

}

// Called when the game starts or when spawned
void ANSBaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANSBaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANSBaseProjectile::ProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(GetOwner());
	ANSCharacter* Target = Cast<ANSCharacter>(OtherActor);

	if (IsValid(OwnerCharacter))
	{
		UNSAbilityComponent* OwnerAbilityComp = OwnerCharacter->GetAbilityComponent();

		if (IsValid(OwnerAbilityComp))
		{
			if (IsValid(Target))
				OwnerAbilityComp->ActivatedAbilityEvent(TEXT("BeginOverlapEvent"), OwnerCharacter, Target);

			else
				UE_LOGFMT(NS_Log, Log, "ANSBaseProjectile - Target Cast Failed");
		}
		else
			UE_LOGFMT(NS_Log, Log, "ANSBaseProjectile - OwnerAbilityComp Cast Failed");
	}
	else
		UE_LOGFMT(NS_Log, Log, "ANSBaseProjectile - OwnerCharacter Cast Failed");

}

