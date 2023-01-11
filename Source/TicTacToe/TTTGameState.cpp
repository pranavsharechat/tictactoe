// Fill out your copyright notice in the Description page of Project Settings.


#include "TTTGameState.h"

ATTTGameState::ATTTGameState()
{

}

void ATTTGameState::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();
}

void ATTTGameState::HandleMatchHasEnded()
{
	Super::HandleMatchHasEnded();
}

void ATTTGameState::AddPlayerState(APlayerState* PlayerState)
{
	Super::AddPlayerState(PlayerState);
}

void ATTTGameState::RemovePlayerState(APlayerState* PlayerState)
{
	Super::RemovePlayerState(PlayerState);
}


