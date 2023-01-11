// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TicTacToeGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UTicTacToeGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite,EditInstanceOnly)
	FString PlayerName;
	
};
