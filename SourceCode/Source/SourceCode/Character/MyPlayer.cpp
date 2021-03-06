// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyPlayer::AMyPlayer() :
	mTurnRateGamepad (50.f),
	maxWalkSpeed (250.f),
	canSprint (false),
	mSpringArm (NULL),
	mCamera (NULL)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Configure character.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMesh(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny"));
	this->GetMesh()->SkeletalMesh = skeletalMesh.Object;
	FVector localMesh(0.f, 0.f, -98.f);
	FRotator rotaMesh(0.f, -90.f, 0.f);
	this->GetMesh()->SetRelativeLocationAndRotation(localMesh, rotaMesh);

	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> animControllerBP(TEXT("/Game/AnimationAsset/Player/PlayerAnimController.PlayerAnimController"));
	this->GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	this->GetMesh()->SetAnimInstanceClass(animControllerBP.Object->GetAnimBlueprintGeneratedClass());

	this->GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	this->GetCharacterMovement()->bOrientRotationToMovement = true;
	this->GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	this->GetCharacterMovement()->MaxWalkSpeed = maxWalkSpeed;
	this->GetCharacterMovement()->MaxWalkSpeedCrouched = maxWalkSpeed * 0.5f;
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

		// Test Debug.
		const FString strShow = value > 0 ? "Move Forward" : "Move Backward";
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Blue, strShow);
		//.

	}

}

void AMyPlayer::MoveRight(float value)
{
	if (Controller != nullptr && value != 0.f)
	{
		AddMovementInput(GetUnitAxis(EAxis::Y), value);

		// Test Debug.
		const FString strShow = value > 0 ? "Move Right" : "Move Left";
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Blue, strShow);
		//.

	}

}

FVector AMyPlayer::GetUnitAxis(EAxis::Type eAxis)
{
	const FRotator yawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
	const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(eAxis);

	this->GetCharacterMovement()->MaxWalkSpeed = UKismetMathLibrary::FInterpTo(this->GetCharacterMovement()->MaxWalkSpeed, maxWalkSpeed, GetWorld()->DeltaTimeSeconds, 5.f);

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

void AMyPlayer::PressedSprint()
{
	canSprint = true;
	maxWalkSpeed = 500.f;

	// Test Debug.
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Blue, "Use Sprint");
	//.

}

void AMyPlayer::ReleasedSprint()
{
	canSprint = false;
	maxWalkSpeed = 250.f;

	// Test Debug.
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Blue, "None Sprint");
	//.

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* input)
{
	Super::SetupPlayerInputComponent(input);

	input->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	input->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
	input->BindAxis("TurnAtRate", this, &AMyPlayer::TurnAtRate);
	input->BindAxis("LookUpAtRate", this, &AMyPlayer::LookUpAtRate);

	input->BindAction("Sprint", EInputEvent::IE_Pressed, this, &AMyPlayer::PressedSprint);
	input->BindAction("Sprint", EInputEvent::IE_Released, this, &AMyPlayer::ReleasedSprint);

}
