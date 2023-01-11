// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TTTPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATTTPlayerState : public APlayerState
{
	GENERATED_BODY()

	ATTTPlayerState();

	virtual void ClientInitialize(AController* InController) override;

	virtual void CopyProperties(APlayerState* PlayerState) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PostInitializeComponents() override;

public:
	UPROPERTY(BlueprintReadWrite, Replicated, ReplicatedUsing = OnRep_CandidateName)
	FString CandidateName;

	UFUNCTION()
	void OnRep_CandidateName();

	UFUNCTION(BlueprintCallable)
	void SetPlayerNickName(FString Name);

};
