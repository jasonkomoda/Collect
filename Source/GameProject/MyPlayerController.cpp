// Fill out your copyright notice in the Description page of Project Settings.

#include "GameProject.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"


AMyPlayerController::AMyPlayerController()
{

}


void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAxis("Turn", this, &APlayerController::AddYawInput);
    InputComponent->BindAxis("TurnRate", this, &AMyPlayerController::TurnAtRate);
    InputComponent->BindAxis("LookUp", this, &APlayerController::AddPitchInput);
    InputComponent->BindAxis("LookUpRate", this, &AMyPlayerController::LookUpAtRate);
    InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
}

void AMyPlayerController::MoveForward(float Value)
{
    if (Value != 0.0f)
    {
        // find out which way is forward
        const FRotator Rotation = GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        
        // get forward vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        GetPawn()->AddMovementInput(Direction, Value);
    }
}

void AMyPlayerController::MoveRight(float Value)
{
    if (Value != 0.0f )
    {
        // find out which way is right
        const FRotator Rotation = GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        
        // get right vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        // add movement in that direction
        GetPawn()->AddMovementInput(Direction, Value);
    }
}

void AMyPlayerController::TurnAtRate(float Rate)
{
    // calculate delta for this frame from the rate information
    GetPawn()->AddControllerYawInput(Rate * Cast<AMyCharacter>(GetPawn())->BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyPlayerController::LookUpAtRate(float Rate)
{
    // calculate delta for this frame from the rate information
    GetPawn()->AddControllerPitchInput(Rate * Cast<AMyCharacter>(GetPawn())->BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

