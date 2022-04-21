// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> mySkeletalMesh(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny"));
	mMeshComponent = this->GetMesh();
	mMeshComponent->SkeletalMesh = mySkeletalMesh.Object;
	mMeshComponent->SetRelativeLocationAndRotation(mPosInitMesh, mRotInitMesh);

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

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

