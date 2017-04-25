// Fill out your copyright notice in the Description page of Project Settings.

#include "GameProject.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAI.h"
#include "GameProjectCharacter.h"
#include "BTTask_MoveToPlayer.h"

EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AEnemyAI *CharPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());
    AGameProjectCharacter *Enemy = Cast<AGameProjectCharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharPC->EnemyKeyID));
    if(Enemy)
    {
        CharPC->MoveToActor(Enemy, 100.f, true, true, true, 0, true);
        return EBTNodeResult::Succeeded;
    }
    else
    {
        return EBTNodeResult::Failed;
    }
    EBTNodeResult::Failed;
}


