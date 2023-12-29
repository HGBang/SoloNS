// Copyright Project NS


#include "NSDragonAICharacter.h"
#include "../../../CombatSystem/System/NSAbilityComponent.h"
#include "../../../CombatSystem/System/NSGameAbility.h"
#include "Components/BoxComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSDragonAICharacter)

ANSDragonAICharacter::ANSDragonAICharacter() :
	Super()
{
	bIsBoss = true;
	LegendaryActionCount = 3;
	LegendaryRegistanceCount = 3;


	TailAttackBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TailAttackBox"));
	BreathAttackBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BreathAttackBox"));
	ScratchAttackBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ScratchAttackBox"));

	TailAttackBox->SetGenerateOverlapEvents(true);
	BreathAttackBox->SetGenerateOverlapEvents(true);
	ScratchAttackBox->SetGenerateOverlapEvents(true);


	TailAttackBox->OnComponentBeginOverlap.AddDynamic(this, &ANSDragonAICharacter::TailAttackBoxBeginOverlap);
	BreathAttackBox->OnComponentBeginOverlap.AddDynamic(this, &ANSDragonAICharacter::BreathAttackBoxBeginOverlap);
	ScratchAttackBox->OnComponentBeginOverlap.AddDynamic(this, &ANSDragonAICharacter::ScratchAttackBoxBeginOverlap);



}

void ANSDragonAICharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilityComponent))
	{
		if(IsValid(MeleeAttackAbility))
			AbilityComponent->GiveAbility(MeleeAttackAbility);

		if (IsValid(FearAbility))
			AbilityComponent->GiveAbility(FearAbility);

		if (IsValid(FearAbility))
			AbilityComponent->GiveAbility(ScratchingAbility);

		if (IsValid(FearAbility))
			AbilityComponent->GiveAbility(TailAbility);

		if (IsValid(FearAbility))
			AbilityComponent->GiveAbility(BreathAbility);
	}

	TailAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BreathAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ScratchAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);



}

void ANSDragonAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ANSDragonAICharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	FAttachmentTransformRules AttachmentRule(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
	TailAttackBox->AttachToComponent(GetMesh(), AttachmentRule, TailAttackSocketName);
	BreathAttackBox->AttachToComponent(GetMesh(), AttachmentRule, BreathSocketName);
	ScratchAttackBox->AttachToComponent(GetMesh(), AttachmentRule, ScratchSocketName);
}

void ANSDragonAICharacter::PlayTurn(const float& DiceValue)
{
	Super::PlayTurn(DiceValue);

	//if (IsValid(AbilityComponent))
	//	AbilityComponent->ActivatedAbility(TEXT("MeleeAttack"));

	Action_Breath();
}

void ANSDragonAICharacter::CharacterTurnEnd()
{
	Super::CharacterTurnEnd();
}

void ANSDragonAICharacter::Action_AttackMelee()
{
	Super::Action_AttackMelee();


}

void ANSDragonAICharacter::Move_MoveToPoint(const FVector& Pos)
{
	Super::Move_MoveToPoint(Pos);
}

void ANSDragonAICharacter::Free_LegendaryRegistance()
{
}

void ANSDragonAICharacter::ActiveCollisionTailAttack()
{
	TailAttackBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void ANSDragonAICharacter::DeActiveCollisionTailAttack()
{
	TailAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ANSDragonAICharacter::ActiveCollisionBreathAttack()
{
	BreathAttackBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void ANSDragonAICharacter::DeActiveCollisionBreathAttack()
{
	BreathAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ANSDragonAICharacter::ActiveCollisionScratchAttack()
{
	ScratchAttackBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void ANSDragonAICharacter::DeActiveCollisionScratchAttack()
{
	ScratchAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ANSDragonAICharacter::Action_Fear()
{
	if (IsValid(AbilityComponent))
		AbilityComponent->ActivatedAbility(TEXT("Fear"));

}

void ANSDragonAICharacter::Action_Scratching()
{
	if (IsValid(AbilityComponent))
		AbilityComponent->ActivatedAbility(TEXT("Scratching"));
}

void ANSDragonAICharacter::Action_Tail()
{
	if (IsValid(AbilityComponent))	
		AbilityComponent->ActivatedAbility(TEXT("Tail"));
	
}

void ANSDragonAICharacter::Action_Breath()
{
	if (IsValid(AbilityComponent))
		AbilityComponent->ActivatedAbility(TEXT("Breath"));
}

void ANSDragonAICharacter::LAction_Tail()
{
}

void ANSDragonAICharacter::LAction_Wing()
{


}

void ANSDragonAICharacter::TailAttackBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(GetOwner());
	ANSCharacter* Target = Cast<ANSCharacter>(OtherActor);


	if (IsValid(AbilityComponent))
	{

		if (IsValid(Target))
			AbilityComponent->ActivatedAbilityEvent(TEXT("TailAttackBeginOverlapEvent"), this, Target);

		else
			UE_LOGFMT(NS_Log, Log, "ANSDragonAICharacter - Target Cast Failed");
	}
	else
		UE_LOGFMT(NS_Log, Log, "ANSDragonAICharacter - OwnerAbilityComp Cast Failed");


	TailAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ANSDragonAICharacter::BreathAttackBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(GetOwner());
	ANSCharacter* Target = Cast<ANSCharacter>(OtherActor);

	if (IsValid(AbilityComponent))
	{

		if (IsValid(Target))
			AbilityComponent->ActivatedAbilityEvent(TEXT("BreathAttackBeginOverlapEvent"), this, Target);

		else
			UE_LOGFMT(NS_Log, Log, "ANSDragonAICharacter - Target Cast Failed");
	}
	else
		UE_LOGFMT(NS_Log, Log, "ANSDragonAICharacter - OwnerAbilityComp Cast Failed");


	BreathAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ANSDragonAICharacter::ScratchAttackBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(GetOwner());
	ANSCharacter* Target = Cast<ANSCharacter>(OtherActor);

	if (IsValid(AbilityComponent))
	{

		if (IsValid(Target))
			AbilityComponent->ActivatedAbilityEvent(TEXT("ScratchAttackBeginOverlapEvent"), this, Target);

		else
			UE_LOGFMT(NS_Log, Log, "ANSDragonAICharacter - Target Cast Failed");
	}
	else
		UE_LOGFMT(NS_Log, Log, "ANSDragonAICharacter - OwnerAbilityComp Cast Failed");


	ScratchAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
