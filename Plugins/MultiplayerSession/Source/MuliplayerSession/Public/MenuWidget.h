// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MenuWidget.generated.h"

class UButton;
class UMultiplayerSessionSubsystem;
class FOnlineSessionSearchResult;

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UMenuWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/* 메뉴를 생성하고 호출할 용도 */
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections = 4, const FString& TypeOfMatch = TEXT("FreeForAll"), const FString& LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/L_Lobby")));

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeDestruct() override;

/* MultiplayerSessionSubsystem에서 받을 콜백 함수들 */
protected:
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);

	void OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);

	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);

	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);

	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);

private:
	UFUNCTION()
	void OnHostButtonClicked();

	UFUNCTION()
	void OnJoinButtonClicked();

	/* 메뉴가 종료될 때 내부적으로 호출*/
	void MenuTearDown();

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> HostButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> JoinButton;

	/* 멀티플레이어 세션 관련 Subsystem */
	TObjectPtr<UMultiplayerSessionSubsystem> MultiplayerSessionSubsystem;

	int32	NumPublicConnections;
	FString	MatchType;

	FString PathToLobby;
};
