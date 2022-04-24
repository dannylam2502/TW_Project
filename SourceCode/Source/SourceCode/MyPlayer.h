// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class SOURCECODE_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

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

private:
	USkeletalMeshComponent* mMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "SpringArm")
		class USpringArmComponent* mSpringArm;
	UPROPERTY(VisibleAnywhere, Category = "CameraFllow")
		class UCameraComponent* mCamera;

	class UCharacterMovementComponent* mPlayerMovement;

	//MyInputController mInputController;

	void InputKey(UInputComponent* input);

	void MoveForward(float value);
	void MoveRight(float value);
	void LookPitch(float value);
	void LookYaw(float value);

	FVector mDirection;
	FRotator mRotatorPlayer;
	FRotator mRotatorYaw;

};
