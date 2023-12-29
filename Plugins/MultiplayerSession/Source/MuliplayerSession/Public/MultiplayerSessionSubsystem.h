// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerSessionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnCreateSessionComplete, bool, bWasSuccessful);

// FOnlineSessionSearchResult�� UCLASS�� �ƴϹǷ� Dynamic���� ������ �� ����, �������Ʈ���� Implement�� �� ����
DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiplayerOnFindSessionsComplete, const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
DECLARE_MULTICAST_DELEGATE_OneParam(FMultiplayerOnJoinSessionComplete, EOnJoinSessionCompleteResult::Type Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnDestroySessionComplete, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnStartSessionComplete, bool, bWasSuccessful);

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UMultiplayerSessionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UMultiplayerSessionSubsystem();

/* �޴� Ŭ�������� ������ �ڵ鸵�ϱ� ���� �Լ���. */
public:
	void CreateSession(int32 NumPublicConnections, FString MatchType);
	void FindSession(int32 MaxSearchResults);
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);
	void DestroySession();
	void StartSession();

/* IOnlineSessionPtr�� Delegate List�� �߰�, ���������� ȣ���. */
protected:
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);

/* �� �Լ��� ���� �Ǿ��� �� �ѷ��� Delegate�� */
public:
	FMultiplayerOnCreateSessionComplete		MultiplayerOnCreateSessionComplete;
	FMultiplayerOnFindSessionsComplete		MultiplayerOnFindSessionsComplete;
	FMultiplayerOnJoinSessionComplete		MultiplayerOnJoinSessionComplete;
	FMultiplayerOnDestroySessionComplete	MultiplayerOnDestroySessionComplete;
	FMultiplayerOnStartSessionComplete		MultiplayerOnStartSessionComplete;
	 
private:
	IOnlineSessionPtr					SessionInterface;
	TSharedPtr<FOnlineSessionSettings>	LastSessoinSettings;
	TSharedPtr<FOnlineSessionSearch>	LastSessionSearch;

	/**
	* To add to the Online Session Interface delegate list.
	* We'll bind our MultiplayerSessionSubsystem internal callbacks to these.
	*/

	FOnCreateSessionCompleteDelegate	CreateSessionCompleteDelegate;
	FDelegateHandle						CreateSessionCompleteDelegateHandle;

	FOnFindSessionsCompleteDelegate		FindSessionsCompleteDelegate;
	FDelegateHandle						FindSessionsCompleteDelegateHandle;

	FOnJoinSessionCompleteDelegate		JoinSessionCompleteDelegate;
	FDelegateHandle						JoinSessionCompleteDelegateHandle;

	FOnDestroySessionCompleteDelegate	DestroySessionCompleteDelegate;
	FDelegateHandle						DestroySessionCompleteDelegateHandle;

	FOnStartSessionCompleteDelegate		StartSessionCompleteDelegate;
	FDelegateHandle						StartSessionCompleteDelegateHandle;

	bool	bCreateSessionOnDestroy;
	int32	LastNumPublicConnections;
	FString LastMatchType;
};
