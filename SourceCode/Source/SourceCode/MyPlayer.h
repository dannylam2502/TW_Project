// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class SOURCECODE_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

private:
	USkeletalMeshComponent *mMeshComponent;

	FVector mPosInitMesh = FVector(0.f, 0.f, -90.f);
	FRotator mRotInitMesh = FRotator(0.f, -90.f, 0.f);

public:
	// Sets default values for this character's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
