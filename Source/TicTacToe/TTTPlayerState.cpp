// Fill out your copyright notice in the Description page of Project Settings.


#include "TTTPlayerState.h"
#include "Net/OnlineEngineInterface.h"
#include "Net/UnrealNetwork.h"

ATTTPlayerState::ATTTPlayerState()
{
	CandidateName = "";
}

void ATTTPlayerState::ClientInitialize(AController* InController)
{
	Super::ClientInitialize(InController);
}

void ATTTPlayerState::CopyProperties(APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);
	
}

void ATTTPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);


	DOREPLIFETIME(ATTTPlayerState, CandidateName);
	
}

void ATTTPlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ATTTPlayerState::OnRep_CandidateName()
{
	UE_LOG(LogTemp, Warning, TEXT("Player Name Replicated. Its called %s"), *CandidateName);
	//OnCandidateNameChanged.Broadcast(CandidateName);
}

void ATTTPlayerState::SetPlayerNickName(FString Name)
{
	CandidateName = Name;
}
