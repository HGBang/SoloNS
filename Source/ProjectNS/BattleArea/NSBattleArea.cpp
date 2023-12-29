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

	// Area�� Overlap�� �ɰ�� Area�� ĳ���͵��� �߰��Ѵ�. 
	ANSCharacter* OverlapCharacter = Cast<ANSCharacter>(OtherActor);

	//������� ����
	if (!IsValid(OverlapCharacter))
		return;
	
	////�̹� ��ϵǾ����� ��� ���� 
	//if (InsideMembers.Find(OverlapCharacter))
	//{

	//	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("OverlapCharacter Find")));
	//	return;
	//}

	// ���� Area�� Ȱ��ȭ�� �ƴ� ��� �÷��̾ ����ϰ� Ȱ��ȭ�Ѵ�. 
	if (!bIsActive)
	{
		OverlapCharacter->SetBattleArea(this);

		InsideMembers.Add(OverlapCharacter);

		StartBattle();
	}

	// ���� Ȱ��ȭ�� ���¶��, ����ó���� �ؾ��Ѵ�. ���� ������� �ش� �÷��̾�� ���� �ο��ްԵȴ�. 
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

		//�ѹ����� ��������, �Ѷ��尡 ����Ǿ����Ƿ� , ������ �÷��̾ �ִ��� Ȯ���� ����ؾ��Ѵ�. 
		if (IntrudingMembers.Num())
		{
			int32 IntrudingCount = IntrudingMembers.Num();

			//���� ����� ���Ը���� �߰��Ѵ�. 
			for (int32 i = 0; i < IntrudingCount; ++i)
				InsideMembers.Add(IntrudingMembers[i]);

			//���Ը���� �����Ͽ� �ٽ� �����Ѵ�. 
			IncludeMember();

			//���Ը���� �����. 
			IntrudingMembers.Empty();
		}
	}
		

	// ���� ���� ���� ĳ���Ͱ� �������¶��?  ���� �ѱ��. 
	if (InsideMembers[TurnIndex]->IsDie())
		ChangeTurn();

	// �װ� �ƴ϶�� ���� ĳ���Ϳ��� ���� �ο��Ѵ�.
	else
		InsideMembers[TurnIndex]->PlayTurn(DiceArray[TurnIndex]);
}

void ANSBattleArea::StartBattle()
{
	int32 MemberCount = InsideMembers.Num();

	// ���� ��� ������ ���Ե�  ����� �ֻ����� + INI���� ���Ѵ�. 
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

	// ������ ���� ���� �̿��Ͽ� , ���� ����� �����Ѵ�
	for (int32 i = 0; i < MemberCount - 1; ++i)
	{
		for (int32 j = i + 1; j < MemberCount; ++j)
		{
			if (CompareMembersByDiceValue(InsideMembers[i], InsideMembers[j], DiceArray[i], DiceArray[j]))
				Swap(InsideMembers[i], InsideMembers[j]);
		}
	}

	// ���ĿϷ��� �����ڿ��� Turn�� �ο��Ѵ�. 
	InsideMembers[TurnIndex]->PlayTurn(DiceArray[TurnIndex]);

	// Battle �� ���۵Ǿ����Ƿ� Area�� Active���·� ��ȯ.
	bIsActive = true;
}

void ANSBattleArea::EndBattle()
{

	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("End Battle ")));

	//Battle�� ����Ǹ� ��� Dice�� ��ü�� �����Ѵ�. 
	DiceArray.Empty();
	InsideMembers.Empty();
	IntrudingMembers.Empty();

	bIsActive = false;
	Destroy();
}

void ANSBattleArea::IncludeMember()
{
	int32 MemberCount = InsideMembers.Num();

	// ������ ���� ���� �̿��Ͽ� , ���� ����� �����Ѵ�
	for (int32 i = 0; i < MemberCount - 1; ++i)
	{
		for (int32 j = i + 1; j < MemberCount; ++j)
		{
			if (CompareMembersByDiceValue(InsideMembers[i], InsideMembers[j], DiceArray[i], DiceArray[j]))
				Swap(InsideMembers[i], InsideMembers[j]);
		}
	}

	// ���ĿϷ��� �����ڿ��� Turn�� �ο��Ѵ�. 
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

