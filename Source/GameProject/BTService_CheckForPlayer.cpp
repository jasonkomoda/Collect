// Fill out your copyright notice in the Description page of Project Settings.

#include "GameProject.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "GameProjectCharacter.h"
#include "EnemyAI.h"
#include "EnemyCharacter.h"
#include "BTService_CheckForPlayer.h"

UBTService_CheckForPlayer::UBTService_CheckForPlayer()
{
    bCreateNodeInstance = true;
}

void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    AEnemyAI *EnemyPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());
    if(EnemyPC)
    {
        AGameProjectCharacter *Enemy = Cast<AGameProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
        if(Enemy){
            OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyKeyID, Enemy);
        }
    }
}


