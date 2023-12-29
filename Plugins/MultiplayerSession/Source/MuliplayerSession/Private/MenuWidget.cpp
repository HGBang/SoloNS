// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "Components/Button.h"
#include "MultiplayerSessionSubsystem.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystem.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(MenuWidget)

UMenuWidget::UMenuWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, NumPublicConnections(4)
	, MatchType(TEXT("FreeForAll"))
	, PathToLobby{}
{
}

void UMenuWidget::MenuSetup(int32 NumberOfPublicConnections, const FString& TypeOfMatch, const FString& LobbyPath)
{
	NumPublicConnections = NumberOfPublicConnections;
	MatchType = TypeOfMatch;
	PathToLobby = FString::Printf(TEXT("?listen"), *LobbyPath);

	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	SetIsFocusable(true);

	if (UWorld* World = GetWorld())
	{
		if (APlayerController* PlayerController = World->GetFirstPlayerController())
		{
			// InputMode Setting
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeData);

			// Mouse Cursor Setting
			PlayerController->SetShowMouseCursor(true);
		}
	}

	if (UGameInstance* GameInst = GetGameInstance())
	{
		MultiplayerSessionSubsystem = GameInst->GetSubsystem<UMultiplayerSessionSubsystem>();
	}

	// Delegate 등록
	if (IsValid(MultiplayerSessionSubsystem))
	{
		MultiplayerSessionSubsystem->MultiplayerOnCreateSessionComplete.AddDynamic(this, &ThisClass::OnCreateSession);
		MultiplayerSessionSubsystem->MultiplayerOnFindSessionsComplete.AddUObject(this, &ThisClass::OnFindSession);
		MultiplayerSessionSubsystem->MultiplayerOnJoinSessionComplete.AddUObject(this, &ThisClass::OnJoinSession);
		MultiplayerSessionSubsystem->MultiplayerOnDestroySessionComplete.AddDynamic(this, &ThisClass::OnDestroySession);
		MultiplayerSessionSubsystem->MultiplayerOnStartSessionComplete.AddDynamic(this, &ThisClass::OnStartSession);
	}
}

void UMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IsValid(HostButton))
		HostButton->OnClicked.AddDynamic(this, &ThisClass::OnHostButtonClicked);

	if (IsValid(JoinButton))
		JoinButton->OnClicked.AddDynamic(this, &ThisClass::OnJoinButtonClicked);
}

void UMenuWidget::NativeDestruct()
{
	// 메뉴가 제거되기전에 처리
	MenuTearDown();

	Super::NativeDestruct();
}

void UMenuWidget::OnCreateSession(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 15.0f, FColor::Yellow, FString::Printf(TEXT("Session Created Successfully")));

		if (UWorld* World = GetWorld())
		{
			// 일단 테스트용으로 만들어둔 로비 레벨로
			World->ServerTravel(PathToLobby);
		}
	}
	else
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 15.0f, FColor::Red, FString::Printf(TEXT("Failed to Create Session")));

		if (IsValid(HostButton))
			HostButton->SetIsEnabled(true);
	}
}

void UMenuWidget::OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful)
{
	if (!MultiplayerSessionSubsystem)	return;

	// SessionResults를 순환하며 MatchType을 비교
	for (auto SearchResult : SessionResults)
	{
		FString SettingsValue;
		SearchResult.Session.SessionSettings.Get(FName("MatchType"), SettingsValue);

		// MatchType이 일치하면 Join
		if (SettingsValue == MatchType)
		{
			MultiplayerSessionSubsystem->JoinSession(SearchResult);
			return;
		}
	}

	if (!bWasSuccessful || SessionResults.Num() <= 0)
	{
		if (IsValid(JoinButton))
			JoinButton->SetIsEnabled(true);
	}
}

void UMenuWidget::OnJoinSession(EOnJoinSessionCompleteResult::Type Result)
{
	if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			FString Address;
			SessionInterface->GetResolvedConnectString(NAME_GameSession, Address);

			if (APlayerController* PC = GetGameInstance()->GetFirstLocalPlayerController())
				PC->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
		}
	}

	if (Result != EOnJoinSessionCompleteResult::Success)
	{
		if (IsValid(JoinButton))
			JoinButton->SetIsEnabled(true);
	}
}

void UMenuWidget::OnDestroySession(bool bWasSuccessful)
{
}

void UMenuWidget::OnStartSession(bool bWasSuccessful)
{
}

void UMenuWidget::MenuTearDown()
{
	RemoveFromParent();
	if (UWorld* World = GetWorld())
	{
		if (APlayerController* PlayerController = World->GetFirstPlayerController())
		{
			// InputMode Setting
			FInputModeGameOnly InputModeData;
			PlayerController->SetInputMode(InputModeData);

			// Mouse Cursor Setting
			PlayerController->SetShowMouseCursor(false);
		}
	}
}

void UMenuWidget::OnHostButtonClicked()
{
	HostButton->SetIsEnabled(false);

	if (IsValid(MultiplayerSessionSubsystem))
		MultiplayerSessionSubsystem->CreateSession(NumPublicConnections, MatchType);
}

void UMenuWidget::OnJoinButtonClicked()
{
	JoinButton->SetIsEnabled(false);

	if (IsValid(MultiplayerSessionSubsystem))
	{
		MultiplayerSessionSubsystem->FindSession(10000);
	}
}
