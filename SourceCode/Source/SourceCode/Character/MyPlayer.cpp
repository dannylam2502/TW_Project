// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "SourceCode/MySystems/InputController.h"
#include "UObject/ConstructorHelpers.h"

#include "SourceCode/MyState/BasicState.h"
#include "SourceCode/MyState/CharacterIdleState.h"
#include "SourceCode/MyState/CharacterWalkState.h"
#include "SourceCode/MyState/CharacterRunState.h"
//#include "Components/StaticMeshComponent.h"

AMyPlayer::AMyPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitCharacter();
	MakeFSM();
}

void AMyPlayer::InitCharacter()
{
	inputController = new InputController();

	// Configure character.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMesh(TEXT("/Game/Art/Mixamo/Paladin/Paladin_J_Nordstrom.Paladin_J_Nordstrom"));
	this->GetMesh()->SkeletalMesh = skeletalMesh.Object;
	FVector localMesh(0.f, 0.f, -98.f);
	FRotator rotaMesh(0.f, -90.f, 0.f);
	this->GetMesh()->SetRelativeLocationAndRotation(localMesh, rotaMesh);

	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> animControllerBP(TEXT("/Game/Art/Mixamo/Paladin/ControllerAnim/PaladinAnimController.PaladinAnimController"));
	this->GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	this->GetMesh()->SetAnimInstanceClass(animControllerBP.Object->GetAnimBlueprintGeneratedClass());

	//meshChar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Char Main"));
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> meshCharMain(TEXT("/Game/Art/Model/SM_MainChar_01_polySurface35.SM_MainChar_01_polySurface35"));
	//FVector localMesh(0.f, 0.f, -98.f);
	//FRotator rotaMesh(0.f, -90.f, 0.f);
	//meshChar->SetStaticMesh(meshCharMain.Object);
	//meshChar->SetRelativeLocationAndRotation(localMesh, rotaMesh);
	//meshChar->SetupAttachment(RootComponent);

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
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	springArm->SetupAttachment(RootComponent);
	springArm->TargetArmLength = 400.f;
	springArm->bUsePawnControlRotation = true;

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(springArm, USpringArmComponent::SocketName);
	camera->bUsePawnControlRotation = false;
}

void AMyPlayer::MakeFSM()
{
	idleState = new CharacterIdleState(this, StateID::Idle);
	idleState->LoadData();
	walkState = new CharacterWalkState(this, StateID::Walk);
	walkState->LoadData();
	runState = new CharacterRunState(this, StateID::Run);
	runState->LoadData();

	currentState = idleState;
	currentStateID = currentState->stateID;
}

void AMyPlayer::ChangeState(BasicState* state)
{
	currentState->ExitState();
	currentState = state;
	currentState->runStateTime = 0.f;
	currentStateID = currentState->stateID;
	currentState->EnterState();
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bPause) return;

	currentState->runStateTime += DeltaTime;
	currentState->ExcuseState();
	currentState->CheckNextState();
}

#pragma region Input.
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* input)
{
	Super::SetupPlayerInputComponent(input);

	input->BindAxis("OnMoveVertical", this, &AMyPlayer::OnMoveVertical);
	input->BindAxis("OnMoveHorizontal", this, &AMyPlayer::OnMoveHorizontal);
	input->BindAxis("OnLookMouseZ", this, &AMyPlayer::OnLookMouseZ);
	input->BindAxis("OnLookMouseY", this, &AMyPlayer::OnLookMouseY);

	input->BindAction("Sprint", EInputEvent::IE_Pressed, this, &AMyPlayer::PressedSprint);
	input->BindAction("Sprint", EInputEvent::IE_Released, this, &AMyPlayer::ReleasedSprint);
}

void AMyPlayer::OnMoveVertical(float value)
{
	inputController->fVertical = value;
}

void AMyPlayer::OnMoveHorizontal(float value)
{
	inputController->fHorizontal = value;
}

void AMyPlayer::OnLookMouseZ(float rate)
{
	inputController->fMouseZ = rate;
}

void AMyPlayer::OnLookMouseY(float rate)
{
	inputController->fMouseY = rate;
}

void AMyPlayer::PressedSprint()
{
	inputController->bSprint = true;
}

void AMyPlayer::ReleasedSprint()
{
	inputController->bSprint = false;
}
#pragma endregion