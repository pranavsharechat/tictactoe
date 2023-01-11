// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Online.h"
#include "GameFramework/GameSession.h"
#include "TicTacToeSession.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCSOnStartSessionComplete, bool, Successful);

UCLASS()
class TICTACTOE_API ATicTacToeSession : public AGameSession
{
	GENERATED_BODY()

	ATicTacToeSession();
	
	bool bGameSessionCreated;
	
	FCSOnStartSessionComplete OnStartSessionCompleteEvent;
	
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle OnStartSessionCompleteDelegateHandle;

	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;

	virtual void RegisterServer() override;


	virtual void OnCreateSessionComplete(FName SsName, bool bWasSuccessful);

	void StartSession();
	
};
