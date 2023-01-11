// Fill out your copyright notice in the Description page of Project Settings.


#include "TicTacToeGameMode.h"
#include "TicTacToeSession.h"
#include "GameFramework/DefaultPawn.h"
#include "TTTPlayerState.h"
#include "TTTGameState.h"
#include "TTTPlayerController.h"

ATicTacToeGameMode::ATicTacToeGameMode()
{
	GameSessionClass = ATicTacToeSession::StaticClass();
	DefaultPawnClass = ADefaultPawn::StaticClass();
	PlayerStateClass = ATTTPlayerState::StaticClass();
	GameStateClass = ATTTGameState::StaticClass();
	PlayerControllerClass = ATTTPlayerController::StaticClass();
	
}