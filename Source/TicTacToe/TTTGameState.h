// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TTTGameState.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATTTGameState : public AGameState
{
	GENERATED_BODY()

	ATTTGameState();
	
	virtual void HandleMatchHasStarted() override;

	virtual void HandleMatchHasEnded() override;

	virtual void AddPlayerState(APlayerState* PlayerState) override;

	virtual void RemovePlayerState(APlayerState* PlayerState) override;


};
