// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
    AMyPlayerController();
	
    virtual void SetupInputComponent() override;
    void MoveForward(float value);
    void MoveRight(float value);
    void LookUpAtRate(float value);
    void TurnAtRate(float value);
    
};
