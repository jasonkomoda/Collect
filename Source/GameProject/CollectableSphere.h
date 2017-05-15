// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CollectableSphere.generated.h"

UCLASS()
class GAMEPROJECT_API ACollectableSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    USphereComponent* Collectable;
	UPROPERTY(EditAnywhere)
    UStaticMeshComponent* MeshComp;
    
};
