// Fill out your copyright notice in the Description page of Project Settings.


#include "TTTPlayerController.h"
#include "TicTacToeGameMode.h"
#include "OnlineSubsystemUtils.h"
#include "TTTPlayerState.h"

ATTTPlayerController::ATTTPlayerController()
{

}

void ATTTPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ATTTPlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}


void ATTTPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	

	/*if (GetNetMode() == ENetMode::NM_Client)
	{
		UE_LOG(LogTemp, Warning, TEXT(" In Player Controller in Client Mode"));
	}

	else if (GetNetMode() == ENetMode::NM_Standalone)
	{
		UE_LOG(LogTemp, Warning, TEXT(" In Player Controller in Standalone Mode"));
	}*/
}

void ATTTPlayerController::SetPlayerInfo_Implementation(const FString& CandidateName)
{
	//Set Player Properties
	ATicTacToeGameMode* gm = Cast<ATicTacToeGameMode>(GetWorld()->GetAuthGameMode());

	if (gm)
	{
		ATTTPlayerState* pState = Cast<ATTTPlayerState>(PlayerState);
		pState->SetPlayerNickName(CandidateName);
	}
}

bool ATTTPlayerController::SetPlayerInfo_Validate(const FString& CandidateName)
{
	return true;
}
