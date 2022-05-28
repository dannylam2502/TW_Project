// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalInfo.h"
#include "SourceCode/Character/BaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

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

