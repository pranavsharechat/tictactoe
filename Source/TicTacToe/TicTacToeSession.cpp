// Fill out your copyright notice in the Description page of Project Settings.


#include "TicTacToeSession.h"
#include "OnlineSubsystemSessionSettings.h"
#include "OnlineSubsystemUtils.h"
#include "Engine/World.h"

ATicTacToeSession::ATicTacToeSession()
{
	OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &ATicTacToeSession::OnCreateSessionComplete);
	SessionName = FName("'TicTacSessioName");
}

void ATicTacToeSession::RegisterServer()
{
	Super::RegisterServer();

	//Create a Session 
	//Create Session on Server
	if (!bGameSessionCreated)
	{
		IOnlineSubsystem* OnlineSub = Online::GetSubsystem(GetWorld());
		
		if (OnlineSub)
		{
			IOnlineSessionPtr SessionInterface = OnlineSub->GetSessionInterface();
			if (SessionInterface.IsValid())
			{

				if (SessionInterface->GetNumSessions() > 0)
					return;

				FOnlineSessionSettings* sessionSettings = new FOnlineSessionSettings();
				sessionSettings->bIsLANMatch = true;
				sessionSettings->bShouldAdvertise = true;
				sessionSettings->bIsDedicated = true;
				sessionSettings->bAllowInvites = true;
				sessionSettings->bUseLobbiesIfAvailable = true;
				sessionSettings->bUseLobbiesVoiceChatIfAvailable = true;
				sessionSettings->bAllowJoinInProgress = true;
				sessionSettings->bAllowJoinViaPresence = true;
				sessionSettings->bUsesPresence = true;
				sessionSettings->NumPrivateConnections = 10;
				sessionSettings->NumPublicConnections = 10;
				sessionSettings->Set(SETTING_MAPNAME, FString("ServerMap"), EOnlineDataAdvertisementType::ViaOnlineService);

				OnCreateSessionCompleteDelegateHandle = SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);
				
				if (SessionInterface->CreateSession(0, NAME_GameSession, *sessionSettings))
				{
					UE_LOG(LogTemp, Warning, TEXT("Creating Session Successfully triggered!"));
				}

				
			}
		}

	}
}


void ATicTacToeSession::OnCreateSessionComplete(FName SsName, bool bWasSuccessful)
{
	const IOnlineSessionPtr sessionInterface = Online::GetSessionInterface(GetWorld());
	if (sessionInterface)
	{
		sessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);
	}

	if (bWasSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("Called OnCreateSessionComplete"));
		bGameSessionCreated = true;
		//CurrentSessionType = SessionType::Created;
		StartSession();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed  OnCreateSessionComplete"));
	}
}

void ATicTacToeSession::StartSession()
{
	UE_LOG(LogTemp, Warning, TEXT("Starting Session...."));

	const IOnlineSessionPtr sessionInterface = Online::GetSessionInterface(GetWorld());

	OnStartSessionCompleteDelegateHandle =
		sessionInterface->AddOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegate);

	if (sessionInterface->StartSession(NAME_GameSession))
	{
		UE_LOG(LogTemp, Warning, TEXT("Starting Session Method Called"));
	}
	else
	{
		sessionInterface->ClearOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegateHandle);
		UE_LOG(LogTemp, Warning, TEXT("Starting Session Method FAILED!"));
		//OnStartSessionCompleteEvent.Broadcast(false);
	}
}
