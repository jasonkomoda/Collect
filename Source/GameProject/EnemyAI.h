// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "EnemyAI.generated.h"


/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AEnemyAI : public AAIController
{
	GENERATED_BODY()
	
	UPROPERTY(transient)
    class UBlackboardComponent *BlackboardComp;
    
    UPROPERTY(transient)
    class UBehaviorTreeComponent *BehaviorComp;
    
public:
    
    AEnemyAI();
    
    virtual void Possess(APawn *InPawn) override;
    uint8 EnemyKeyID;
};
