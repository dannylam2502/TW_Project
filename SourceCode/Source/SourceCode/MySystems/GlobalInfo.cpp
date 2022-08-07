// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalInfo.h"
#include "SourceCode/Character/BaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SourceCode/MySystems/InputController.h"

// Sets default values
AGlobalInfo::AGlobalInfo()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGlobalInfo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGlobalInfo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGlobalInfo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector AGlobalInfo::GetUnitAxis(ABaseCharacter* parent, EAxis::Type eAxis)
{
	const FRotator yawRotation(0.f, parent->Controller->GetControlRotation().Yaw, 0.f);
	const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(eAxis);

	parent->GetCharacterMovement()->MaxWalkSpeed = UKismetMathLibrary::FInterpTo(parent->GetCharacterMovement()->MaxWalkSpeed, parent->maxWalkSpeed, parent->GetWorld()->DeltaTimeSeconds, 5.f);

	return direction;
}

void AGlobalInfo::MoveForward(ABaseCharacter* parent)
{
	if (parent->Controller != nullptr && parent->inputController->fVertical != 0.f)
	{
		parent->AddMovementInput(GetUnitAxis(parent, EAxis::X), parent->inputController->fVertical);

		// Test Debug.
		const FString strShow = parent->inputController->fVertical > 0 ? "Move Forward" : "Move Backward";
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Blue, strShow);
		//.
	}
}

void AGlobalInfo::MoveRight(ABaseCharacter* parent)
{
	if (parent->Controller != nullptr && parent->inputController->fHorizontal != 0.f)
	{
		parent->AddMovementInput(GetUnitAxis(parent, EAxis::Y), parent->inputController->fHorizontal);

		// Test Debug.
		const FString strShow = parent->inputController->fHorizontal > 0 ? "Move Right" : "Move Left";
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Blue, strShow);
		//.
	}
}

void AGlobalInfo::LookUp(ABaseCharacter* parent)
{
	if (parent->Controller != nullptr && parent->inputController->fMouseY != 0.f)
	{
		parent->AddControllerPitchInput(parent->inputController->fMouseY * parent->turnRateGamepad * parent->GetWorld()->GetDeltaSeconds());
	}
}

void AGlobalInfo::LookRight(ABaseCharacter* parent)
{
	if (parent->Controller != nullptr && parent->inputController->fMouseZ != 0.f)
	{
		parent->AddControllerYawInput(parent->inputController->fMouseZ * parent->turnRateGamepad * parent->GetWorld()->GetDeltaSeconds());
	}
}