// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	mSpringArm = NULL;
	mCamera = NULL;

	mTurnRateGamepad = 50.f;

	// Configure character.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMesh(TEXT("/Game/Characters/Mannequin_UE4/Meshes/SK_Mannequin.SK_Mannequin"));
	this->GetMesh()->SkeletalMesh = skeletalMesh.Object;
	FVector localMesh(0.f, 0.f, -98.f);
	FRotator rotaMesh(0.f, -90.f, 0.f);
	this->GetMesh()->SetRelativeLocationAndRotation(localMesh, rotaMesh);

	this->GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	this->GetCharacterMovement()->bOrientRotationToMovement = true;
	this->GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	float maxWallSpeed = 500.f;
	this->GetCharacterMovement()->MaxWalkSpeed = maxWallSpeed;
	this->GetCharacterMovement()->MaxWalkSpeedCrouched = maxWallSpeed * 0.5f;
	this->GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	this->GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Configure Camera.
	mSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	mSpringArm->SetupAttachment(RootComponent);
	mSpringArm->TargetArmLength = 400.f;
	mSpringArm->bUsePawnControlRotation = true;

	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	mCamera->SetupAttachment(mSpringArm, USpringArmComponent::SocketName);
	mCamera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPlayer::MoveForward(float value)
{
	if (Controller != nullptr && value != 0.f)
	{
		AddMovementInput(GetUnitAxis(EAxis::X), value);
	}

}

void AMyPlayer::MoveRight(float value)
{
	if (Controller != nullptr && value != 0.f)
	{
		AddMovementInput(GetUnitAxis(EAxis::Y), value);
	}

}

FVector AMyPlayer::GetUnitAxis(EAxis::Type eAxis)
{
	const FRotator yawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
	const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(eAxis);
	return direction;
}

void AMyPlayer::TurnAtRate(float rate)
{
	AddControllerYawInput(rate * mTurnRateGamepad * GetWorld()->GetDeltaSeconds());

}

void AMyPlayer::LookUpAtRate(float rate)
{
	AddControllerPitchInput(rate * mTurnRateGamepad * GetWorld()->GetDeltaSeconds());

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* input)
{
	Super::SetupPlayerInputComponent(input);

	input->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	input->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
	input->BindAxis("TurnAtRate", this, &AMyPlayer::TurnAtRate);
	input->BindAxis("LookUpAtRate", this, &AMyPlayer::LookUpAtRate);

}
