// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "EnemyCharacter.h"
#include "MyGameMode.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(GameModeLog, Log, All);
/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	
    AMyGameMode();
    
    virtual ~AMyGameMode();
    
    virtual void StartPlay() override;
    
    virtual void HandleMatchIsWaitingToStart();
    
    virtual void HandleMatchHasEnded();
    
    virtual void HandleLeavingMap();
    
public:
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FVector> EnemySpawnPoints;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FVector> FirstTwoDoorSpawnPoints;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FVector> SecondTwoDoorSpawnPoints;
};

