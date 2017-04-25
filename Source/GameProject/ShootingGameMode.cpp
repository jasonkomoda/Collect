// Fill out your copyright notice in the Description page of Project Settings.

#include "GameProject.h"
#include "ShootingGameMode.h"
#include "MyGameState.h"

AShootingGameMode::AShootingGameMode() : AGameMode()
{
    GameStateClass = AMyGameState::StaticClass();
    
}


AShootingGameMode::~AShootingGameMode()
{
    // not doing anything here, but it's necessary to have a virtual destructor, note c++11 helps with this in theory
}
