// Fill out your copyright notice in the Description page of Project Settings.

#include "GameProject.h"
#include "MyGameMode.h"
#include "MyGameState.h"

DEFINE_LOG_CATEGORY(GameStateLog);
AMyGameState::AMyGameState()
{
    NumSpheresCollected = 0;
    counter = 0;
    playerHealth = 100.0;
    openDoor1 = false;
    openDoor2 = false;
    openDoor3 = false;
    openDoor4 = false;
    goOutside = false;
}

// Called every frame
void AMyGameState::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(gameOver){
        if(counter < 1){
            SetMatchState(FName(TEXT("WaitingPostMatch")));
            counter++;
        }
    }
}

void AMyGameState::AddOneToNumSpheresCollected(){
    NumSpheresCollected++;
    UE_LOG(GameStateLog, Warning, TEXT("Collected a sphere!  Current number of spheres collected: %d"), NumSpheresCollected);
}


