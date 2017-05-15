// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "MyGameMode.h"
#include "MyGameState.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(GameStateLog, Log, All);
/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AMyGameState : public AGameState
{
	GENERATED_BODY()
	
    AMyGameState();
    
public:
    
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    int NumSpheresCollected;
    
    int counter;
    
    AMyGameMode* GameModeClass;
    
    void AddOneToNumSpheresCollected();
	
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float playerHealth;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool openDoor1;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool openDoor2;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool openDoor3;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool openDoor4;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool goOutside;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool gameOver;
};
