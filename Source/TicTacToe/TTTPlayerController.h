// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TTTPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATTTPlayerController : public APlayerController
{
	GENERATED_BODY()

	ATTTPlayerController();

	virtual void PostInitializeComponents() override;

	virtual void OnRep_PlayerState() override;
	
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(Server,Reliable,WithValidation,BlueprintCallable)
	void SetPlayerInfo(const FString& CandidateName);

};
