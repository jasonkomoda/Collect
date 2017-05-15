// Fill out your copyright notice in the Description page of Project Settings.

#include "GameProject.h"
#include "CollectableSphere.h"


// Sets default values
ACollectableSphere::ACollectableSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    Collectable = CreateDefaultSubobject<USphereComponent>("CollectableSphere");
    RootComponent = Collectable;
    Collectable->InitSphereRadius(20.0f);
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
    MeshComp->SetupAttachment(Collectable);
    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
    if(Mesh.Succeeded()){
        MeshComp->SetStaticMesh(Mesh.Object);
        MeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -20.0f));
        MeshComp->SetWorldScale3D(FVector(0.4f, 0.4f, 0.4f));
    }
    static ConstructorHelpers::FObjectFinder<UMaterialInterface>Material(TEXT("/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse"));
    if(Material.Succeeded()){
        MeshComp->SetMaterial(0, Material.Object);
    }
}

// Called when the game starts or when spawned
void ACollectableSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectableSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}
