// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SOURCECODE_API InputController
{
public:
	InputController();
	~InputController();

	float fVertical;
	float fHorizontal;
	float fMouseZ;
	float fMouseY;

	bool bSprint;
	
};
