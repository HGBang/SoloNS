// Copyright Project NS


#include "NSBattleArea.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "../CombatSystem/AttributeSet/NSCharacterAttributeSet.h"
#include "../CombatSystem/System/NSAbilityComponent.h"
#include "../Character/NSCharacter.h"
#include "../GameMode/NSGameMode.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSBattleArea)

ANSBattleArea::ANSBattleArea() : 
	Super(),
	TurnIndex(0),
	bIsActive(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AreaShape = CreateDefaultSubobject<USphereComponent>(TEXT("AreaSphere"));

	AreaShape->SetGenerateOverlapEvents(true);

	AreaShape->OnComponentBeginOverlap.AddDynamic(this, &ANSBattleArea::AreaBeginOverlap);


	//Replicated
	AreaShape->SetIsReplicated(true);
	bReplicates = 1;
	
}

void ANSBattleArea::BeginPlay()
{
	Super::BeginPlay();

	int32 MemberCount = InsideMembers.Num();

	for (int32 i = 0; i < MemberCount; ++i)
	{
		InsideMembers[i]->SetBattleArea(this);
	}
}

void ANSBattleArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANSBattleArea::AreaBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	// Area에 Overlap이 될경우 Area에 캐릭터들을 추가한다. 
	ANSCharacter* OverlapCharacter = Cast<ANSCharacter>(OtherActor);

	//없을경우 리턴
	if (!IsValid(OverlapCharacter))
		return;
	
	////이미 등록되어있을 경우 리턴 
	//if (InsideMembers.Find(OverlapCharacter))
	//{

	//	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("OverlapCharacter Find")));
	//	return;
	//}

	// 현재 Area가 활성화가 아닐 경우 플레이어를 등록하고 활성화한다. 
	if (!bIsActive)
	{
		OverlapCharacter->SetBattleArea(this);

		InsideMembers.Add(OverlapCharacter);

		StartBattle();
	}

	// 현재 활성화된 상태라면, 난입처리를 해야한다. 다음 라운드부터 해당 플레이어는 턴을 부여받게된다. 
	else 
	{
		OverlapCharacter->SetBattleArea(this);

		IntrudingMembers.Add(OverlapCharacter);

		int32 DiceValue = FMath::RandRange(DICE_MIN, DICE_TWENTY);

		DiceArray.Add(DiceValue);
	}
}

void ANSBattleArea::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, DiceArray);
	DOREPLIFETIME(ThisClass, TurnIndex);
	DOREPLIFETIME(ThisClass, bIsActive);
}

void ANSBattleArea::UpdateArea()
{
	bool MonsterEnable = false;

	int32 MemberCount = InsideMembers.Num();

	for (int32 i = 0; i < MemberCount; ++i)
	{
		if (!InsideMembers[i]->IsPlayer() && !InsideMembers[i]->IsDie())
			MonsterEnable = true;
	}

	if (!MonsterEnable)
		EndBattle();
}

void ANSBattleArea::ChangeTurn()
{
	UpdateArea();

	if (!bIsActive)
		return;

	++TurnIndex;

	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Change Turn")));

	int32 MaxIndex = InsideMembers.Num() - 1;

	if (TurnIndex > MaxIndex)
	{		
		TurnIndex = 0;

		//한바퀴를 돌았으면, 한라운드가 종료되었으므로 , 난입한 플레이어가 있는지 확인후 등록해야한다. 
		if (IntrudingMembers.Num())
		{
			int32 IntrudingCount = IntrudingMembers.Num();

			//기존 멤버에 난입멤버를 추가한다. 
			for (int32 i = 0; i < IntrudingCount; ++i)
				InsideMembers.Add(IntrudingMembers[i]);

			//난입멤버를 포함하여 다시 시작한다. 
			IncludeMember();

			//난입멤버를 지운다. 
			IntrudingMembers.Empty();
		}
	}
		

	// 만약 현재 턴의 캐릭터가 죽은상태라면?  턴을 넘긴다. 
	if (InsideMembers[TurnIndex]->IsDie())
		ChangeTurn();

	// 그게 아니라면 다음 캐릭터에게 턴을 부여한다.
	else
		InsideMembers[TurnIndex]->PlayTurn(DiceArray[TurnIndex]);
}

void ANSBattleArea::StartBattle()
{
	int32 MemberCount = InsideMembers.Num();

	// 먼저 모든 영역에 포함된  멤버의 주사위값 + INI값을 구한다. 
	for (int32 i = 0; i < MemberCount; ++i)
	{
		int32 Dice = FMath::RandRange(DICE_MIN, DICE_TWENTY);

		UNSCharacterAttributeSet* AttributeSet = Cast<UNSCharacterAttributeSet>(InsideMembers[i]->GetComponentByClass<UNSAbilityComponent>()->GetAttributeSet());

		if (IsValid(AttributeSet))
		{
			float IniValue = AttributeSet->GetCharacterAttributeValue(ECharacterAttributeType::Initialtive);

			IniValue += Dice;

			DiceArray.Add(IniValue);
		}
	}

	// 위에서 구한 값을 이용하여 , 현재 멤버를 정렬한다
	for (int32 i = 0; i < MemberCount - 1; ++i)
	{
		for (int32 j = i + 1; j < MemberCount; ++j)
		{
			if (CompareMembersByDiceValue(InsideMembers[i], InsideMembers[j], DiceArray[i], DiceArray[j]))
				Swap(InsideMembers[i], InsideMembers[j]);
		}
	}

	// 정렬완료후 선공자에게 Turn을 부여한다. 
	InsideMembers[TurnIndex]->PlayTurn(DiceArray[TurnIndex]);

	// Battle 이 시작되었으므로 Area를 Active상태로 변환.
	bIsActive = true;
}

void ANSBattleArea::EndBattle()
{

	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("End Battle ")));

	//Battle이 종료되면 모든 Dice와 객체를 해제한다. 
	DiceArray.Empty();
	InsideMembers.Empty();
	IntrudingMembers.Empty();

	bIsActive = false;
	Destroy();
}

void ANSBattleArea::IncludeMember()
{
	int32 MemberCount = InsideMembers.Num();

	// 위에서 구한 값을 이용하여 , 현재 멤버를 정렬한다
	for (int32 i = 0; i < MemberCount - 1; ++i)
	{
		for (int32 j = i + 1; j < MemberCount; ++j)
		{
			if (CompareMembersByDiceValue(InsideMembers[i], InsideMembers[j], DiceArray[i], DiceArray[j]))
				Swap(InsideMembers[i], InsideMembers[j]);
		}
	}

	// 정렬완료후 선공자에게 Turn을 부여한다. 
	InsideMembers[TurnIndex]->PlayTurn(DiceArray[TurnIndex]);
}

bool ANSBattleArea::CompareMembersByDiceValue(TObjectPtr<ANSCharacter> MemberA, TObjectPtr<ANSCharacter> MemberB, int32 DiceA, int32 DiceB)
{
	UNSAbilityComponent* AbilityCompA = MemberA->GetComponentByClass<UNSAbilityComponent>();
	UNSAbilityComponent* AbilityCompB = MemberB->GetComponentByClass<UNSAbilityComponent>();

	if (IsValid(AbilityCompA) && IsValid(AbilityCompB))
	{
		UNSCharacterAttributeSet* AttributeSetA = Cast<UNSCharacterAttributeSet>(AbilityCompA->GetAttributeSet());
		UNSCharacterAttributeSet* AttributeSetB = Cast<UNSCharacterAttributeSet>(AbilityCompB->GetAttributeSet());

		if (IsValid(AttributeSetA) && IsValid(AttributeSetB))
		{
			float INIValueA = AttributeSetA->GetCharacterAttributeValue(ECharacterAttributeType::Initialtive);
			float INIValueB = AttributeSetB->GetCharacterAttributeValue(ECharacterAttributeType::Initialtive);

			return (INIValueA + DiceA) < (INIValueB + DiceB);
		}
	}

	return false;
}

