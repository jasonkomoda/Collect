// Fill out your copyright notice in the Description page of Project Settings.

#include "GameProject.h"
#include "EnemyAI.h"
#include "EnemyCharacter.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
    SpawnPoint = FVector(200.0, 300.0, 88.0);
    static ConstructorHelpers::FObjectFinder<USkeletalMesh>myMesh(TEXT("/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin.SK_Mannequin"));
    static ConstructorHelpers::FObjectFinder<UAnimBlueprint>Anim(TEXT("/Game/AnimStarterPack/UE4ASP_HeroTPP_AnimBlueprint.UE4ASP_HeroTPP_AnimBlueprint"));
    if(myMesh.Succeeded()){
        GetMesh()->SetSkeletalMesh(myMesh.Object);
    }
    static ConstructorHelpers::FObjectFinder<UMaterialInterface>Material(TEXT("/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse"));
    if(Material.Succeeded()){
        GetMesh()->SetMaterial(0, Material.Object);
        GetMesh()->SetMaterial(1, Material.Object);
    }
    GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -84.0f));
    GetMesh()->SetRelativeRotation(FQuat(FVector(0.0f, 0.0f, 1.0f), -PI/2));
    GetMesh()->SetAnimInstanceClass(Anim.Object->GeneratedClass);
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
    
    //SetActorLocation(SpawnPoint);
    
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

