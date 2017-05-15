// Fill out your copyright notice in the Description page of Project Settings.

#include "GameProject.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"
#include "CollectableSphere.h"
#include "EnemyCharacter.h"
#include "MyGameMode.h"

DEFINE_LOG_CATEGORY(GameModeLog);
AMyGameMode::AMyGameMode() : AGameMode()
{
    /** initialize some of the defaults, blueprinting this will override it, notice the use of StaticClass to get the UClass class type properly */
    //DefaultPawnClass = AMyCharacter::StaticClass();
    PlayerControllerClass = AMyPlayerController::StaticClass();
    GameStateClass = AMyGameState::StaticClass();
    UE_LOG(GameModeLog, Warning, TEXT("MatchState: %s"), *GetMatchState().ToString());
    EnemySpawnPoints.Add(FVector(2794.0, 295.0, 88.0));
    EnemySpawnPoints.Add(FVector(6711.0, -681.0, 88.0));
    EnemySpawnPoints.Add(FVector(6711.0, -900.0, 88.0));
    EnemySpawnPoints.Add(FVector(1795.0, -1056.0, 88.0));
    EnemySpawnPoints.Add(FVector(3382.0, 1708.0, 88.0));
    EnemySpawnPoints.Add(FVector(3582.0, 1708.0, 88.0));
    EnemySpawnPoints.Add(FVector(5591.0, -2234.0, 88.0));
    EnemySpawnPoints.Add(FVector(5970.0, -2378.0, 88.0));
    EnemySpawnPoints.Add(FVector(5758.0, -1837.0, 88.0));
    EnemySpawnPoints.Add(FVector(8109.0, -2786.0, 88.0));
    EnemySpawnPoints.Add(FVector(8109.0, -3561.0, 88.0));
    EnemySpawnPoints.Add(FVector(7226.0, -3561.0, 88.0));
    EnemySpawnPoints.Add(FVector(7226.0, -2786.0, 88.0));
    EnemySpawnPoints.Add(FVector(7226.0, -9000.0, 90.0));
    EnemySpawnPoints.Add(FVector(6175.0, -12404.0, 115.0));
    EnemySpawnPoints.Add(FVector(6059.0, 15041.0, 308.0));
    EnemySpawnPoints.Add(FVector(8133.0, -17991.0, 95.0));
    EnemySpawnPoints.Add(FVector(7257.0, -18636.0, 177.0));
    EnemySpawnPoints.Add(FVector(3881.0, -15534.0, 358.0));
    EnemySpawnPoints.Add(FVector(1695.0, -15584.0, 360.0));
    EnemySpawnPoints.Add(FVector(-1403.0, -12083.0, -515.));
    FirstTwoDoorSpawnPoints.Add(FVector(1738.0, 10.0, 0.0));
    FirstTwoDoorSpawnPoints.Add(FVector(3338.0, 590.0, 0.0));
    SecondTwoDoorSpawnPoints.Add(FVector(6410.0, -1862.0, 88.0));
    SecondTwoDoorSpawnPoints.Add(FVector(6990.0, -3462.0, 88.0));
    
}

AMyGameMode::~AMyGameMode()
{
    // not doing anything here, but it's necessary to have a virtual destructor, note c++11 helps with this in theory
}

void AMyGameMode::HandleMatchIsWaitingToStart()
{
    UE_LOG(GameModeLog, Warning, TEXT("MatchState: %s"), *GetMatchState().ToString());
}

void AMyGameMode::StartPlay()
{
    Super::StartPlay();
    SetMatchState(FName(TEXT("InProgress")));
   UE_LOG(GameModeLog, Warning, TEXT("MatchState: %s"), *GetMatchState().ToString());
}

void AMyGameMode::HandleMatchHasEnded()
{
    UE_LOG(GameModeLog, Warning, TEXT("MatchState: %s"), *GetMatchState().ToString());
    SetMatchState(FName(TEXT("LeavingMap")));
}

void AMyGameMode::HandleLeavingMap()
{
    UE_LOG(GameModeLog, Warning, TEXT("MatchState: %s"), *GetMatchState().ToString());

}

