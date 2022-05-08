// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;

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

private: // Variable.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* mSpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* mCamera;

	float mTurnRateGamepad;

protected: // Functions.
	void MoveForward(float value);
	void MoveRight(float value);
	FVector GetUnitAxis(EAxis::Type eAxis);
	void TurnAtRate(float rate);
	void LookUpAtRate(float rate);


	virtual void SetupPlayerInputComponent(class UInputComponent* input) override;

public:
	FORCEINLINE class USpringArmComponent* GetSpringArm() const { return mSpringArm; }
	FORCEINLINE class UCameraComponent* GetCamera() const { return mCamera; }

};
