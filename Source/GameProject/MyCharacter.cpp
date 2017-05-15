// Fill out your copyright notice in the Description page of Project Settings.

#include "GameProject.h"
#include "CollectableSphere.h"
#include "MyGameMode.h"
#include "MyGameState.h"
#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    CameraVisibilitySphere = CreateDefaultSubobject<USphereComponent>(TEXT("CameraVisbilitySphere"));
    CameraVisibilitySphere->InitSphereRadius(12.0f);
    
    // Set size for collision capsule
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
    
    // set our turn rates for input
    BaseTurnRate = 45.f;
    BaseLookUpRate = 45.f;
    
    // Don't rotate when the controller rotates. Let that just affect the camera.
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
    // Configure character movement
    GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
    GetCharacterMovement()->JumpZVelocity = 600.f;
    GetCharacterMovement()->AirControl = 0.2f;
    
    // Create a camera boom (pulls in towards the player if there is a collision)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 100.0f; // The camera follows at this distance behind the character
    CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
    
    // Create a follow camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
    FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
    CameraVisibilitySphere->SetupAttachment(FollowCamera);
    SpawnPoint = FVector(842.0, 272.0, 88.0);
    static ConstructorHelpers::FObjectFinder<USkeletalMesh>myMesh(TEXT("/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin.SK_Mannequin"));
    static ConstructorHelpers::FObjectFinder<UAnimBlueprint>Anim(TEXT("/Game/AnimStarterPack/UE4ASP_HeroTPP_AnimBlueprint.UE4ASP_HeroTPP_AnimBlueprint"));
    if(myMesh.Succeeded()){
        GetMesh()->SetSkeletalMesh(myMesh.Object);
    }
    static ConstructorHelpers::FObjectFinder<UMaterialInterface>Material1(TEXT("/Game/GTFreeMaterials/Materials/Metal_CyberCube.Metal_CyberCube"));
    static ConstructorHelpers::FObjectFinder<UMaterialInterface>Material2(TEXT("/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse"));
    if(Material1.Succeeded() && Material2.Succeeded()){
        GetMesh()->SetMaterial(0, Material1.Object);
        GetMesh()->SetMaterial(1, Material2.Object);
    }

    CameraBoom->SetRelativeLocation(FVector(0.0, 34.0, 79.0));
    GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -84.0f));
    GetMesh()->SetRelativeRotation(FQuat(FVector(0.0f, 0.0f, 1.0f), -PI/2));
    GetMesh()->SetAnimInstanceClass(Anim.Object->GeneratedClass);
    GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMyCharacter::OnOverlapBegin);
    
    
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
    //SetActorLocation(SpawnPoint);
    GameStateClass = Cast<AMyGameState>(GetWorld()->GetGameState());
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}

// Called to bind functionality to inputvoid AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



void AMyCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if((Cast<ACollectableSphere>(OtherActor)) && (OtherActor != this) && (OtherComponent != nullptr))
    {
        OtherActor->Destroy();
        playSound = true;
        GameStateClass->AddOneToNumSpheresCollected();
    }
}

