// Fill out your copyright notice in the Description page of Project Settings.


#include "NSCharacter.h"
#include "../Animation/NSAnimInstance.h"
#include "../BattleArea/NSBattleArea.h"
#include "../CombatSystem/GamePlayEffect/NSGamePlayEffect.h"
#include "../CombatSystem/System/NSAbilityComponent.h"
#include "../CombatSystem/System/NSGameAbility.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSCharacter)

ANSCharacter::ANSCharacter(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer),
	bTurn(false),
	bIsDie(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	AbilityComponent = CreateDefaultSubobject<UNSAbilityComponent>(TEXT("AbilityComp"));
	AbilityComponent->SetIsReplicated(true);

	//Replicate
	SetReplicates(true);

	//Action Setting
	CharacterActionType.Add(EActionType::Major, false);
	CharacterActionType.Add(EActionType::Minor, false);
	CharacterActionType.Add(EActionType::ReAction, false);
	CharacterActionType.Add(EActionType::Move, false);


	//Collider 
	MeleeAttackBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MeleeAttackBox"));

	MeleeAttackBox->SetGenerateOverlapEvents(true);



	MeleeAttackBox->OnComponentBeginOverlap.AddDynamic(this, &ANSCharacter::MeleeAttackBoxBeginOverlap);
	
}

void ANSCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	FAttachmentTransformRules AttachmentRule(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
	MeleeAttackBox->AttachToComponent(GetMesh(), AttachmentRule, SocketName);
}

void ANSCharacter::TurnOnOutline_Implementation()
{
	GetMesh()->SetRenderCustomDepth(true);
}

void ANSCharacter::TurnOffOutline_Implementation()
{
	GetMesh()->SetRenderCustomDepth(false);
}

bool ANSCharacter::IsAccuracy()
{
	bool CurrentAccuracy = bIsAccuracy;
	bIsAccuracy = false;

	return CurrentAccuracy;
}

void ANSCharacter::BeginPlay()
{
	Super::BeginPlay();	
	MeleeAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//if (IsValid(AbilityComponent)) {
	//	for (const TSubclassOf<UNSGameAbility>& SubClass : AbilityClassArr) {
	//		if (IsValid(SubClass)) {
	//			AbilityComponent->GiveAbility(SubClass);
	//		}
	//		else
	//			UE_LOGFMT(NS_Log, Log, "ANSCharacter - BeginPlay : TSubClass Valid Check Failed");
	//	}
	//}
	//else
	//	UE_LOGFMT(NS_Log, Log, "ANSCharacter - BeginPlay : AbilityComponent Valid Check Failed");




}

void ANSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANSCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, bTurn);
	DOREPLIFETIME(ThisClass, BattleArea);
	DOREPLIFETIME(ThisClass, bIsDie);
}

void ANSCharacter::Death()
{
	bIsDie = true;


}

void ANSCharacter::PlayTurn(const float& DiceValue)
{
	bTurn = true;
}

void ANSCharacter::CharacterTurnEnd()
{
	if (!bTurn)
		return;

	bTurn = false;
	BattleArea->ChangeTurn();

	CharacterActionType[EActionType::Major] = false;
	CharacterActionType[EActionType::Minor] = false;
	CharacterActionType[EActionType::ReAction] = false;
	CharacterActionType[EActionType::Move] = false;
}

void ANSCharacter::ActivatedCollision()
{
	MeleeAttackBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void ANSCharacter::DeActivatedCollision()
{
	MeleeAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ANSCharacter::MajorAction_DefaultAttack()
{
	if(!CharacterActionType.Find(EActionType::Major))
		CharacterActionType[EActionType::Major] = true;

	if (bIsAccuracy)
		bIsAccuracy = false;

	//AbilityComponent->ActivatedAbility(TEXT("MeleeAttack"));
}

void ANSCharacter::MajorAction_Evade()
{
	if (!CharacterActionType.Find(EActionType::Major))
		CharacterActionType[EActionType::Major] = true;
}

void ANSCharacter::MajorAction_Retreat()
{
	if (!CharacterActionType.Find(EActionType::Major))
		CharacterActionType[EActionType::Major] = true;	
}

void ANSCharacter::MajorAction_Dash()
{
	if (!CharacterActionType.Find(EActionType::Major))
		CharacterActionType[EActionType::Major] = true;
}

void ANSCharacter::MajorAction_UseItem()
{
	if (!CharacterActionType.Find(EActionType::Major))
		CharacterActionType[EActionType::Major] = true;
}

void ANSCharacter::MinorAction_UseItem()
{
	if (!CharacterActionType.Find(EActionType::Minor))
		CharacterActionType[EActionType::Minor] = true;
}

void ANSCharacter::ReAction_Attack()
{
	if (!CharacterActionType.Find(EActionType::ReAction))
		CharacterActionType[EActionType::ReAction] = true;
}

void ANSCharacter::CalculateAccuracy(ANSCharacter* Target)
{
}

void ANSCharacter::MeleeAttackBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ANSCharacter* OwnerCharacter = Cast<ANSCharacter>(GetOwner());
	ANSCharacter* Target = Cast<ANSCharacter>(OtherActor);	



	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Overlap Start : %d")));

		if (IsValid(AbilityComponent))
		{		

			if (IsValid(Target))
				AbilityComponent->ActivatedAbilityEvent(TEXT("BeginOverlapEvent"), this, Target);

			else
				UE_LOGFMT(NS_Log, Log, "ANSCharacter - Target Cast Failed");
		}
		else
			UE_LOGFMT(NS_Log, Log, "ANSCharacter - OwnerAbilityComp Cast Failed");


		MeleeAttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}




