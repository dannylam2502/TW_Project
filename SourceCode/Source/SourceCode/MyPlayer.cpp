// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "MyInputController.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> mySkeletalMesh(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny"));
	mMeshComponent = this->GetMesh();
	mMeshComponent->SkeletalMesh = mySkeletalMesh.Object;
	FVector posInitMesh = FVector(0.f, 0.f, -90.f);
	FRotator rotInitMesh = FRotator(0.f, -90.f, 0.f);
	mMeshComponent->SetRelativeLocationAndRotation(posInitMesh, rotInitMesh);

	mSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	mSpringArm->SetupAttachment(RootComponent);
	mSpringArm->TargetArmLength = 200.f;

	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraFllow"));
	mCamera->SetupAttachment(mSpringArm, USpringArmComponent::SocketName);
	FVector posInitCamera = FVector(0.f, 45.f, 50.f);
	mCamera->SetRelativeLocation(posInitCamera);

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	//mInputController = new MyInputController();

}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputKey(PlayerInputComponent);



}

void AMyPlayer::MoveForward(float value)
{
	//mInputController->moveVertical = value;

}

void AMyPlayer::MoveRight(float value)
{
	//mInputController->moveHorizontal = value;

}

void AMyPlayer::LookPitch(float value)
{
	//mInputController->lookHorizontal = value;

}

void AMyPlayer::LookYaw(float value)
{
	//mInputController->lookVertical = value;

}

void AMyPlayer::InputKey(UInputComponent* input)
{
	input->BindAxis("", this, &AMyPlayer::MoveForward);
	input->BindAxis("", this, &AMyPlayer::MoveRight);
	input->BindAxis("", this, &AMyPlayer::LookPitch);
	input->BindAxis("", this, &AMyPlayer::LookYaw);

}