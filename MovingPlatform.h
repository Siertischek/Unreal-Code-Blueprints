// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLECOURSE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Direction")
	bool XPositive;
	UPROPERTY(EditAnywhere, Category="Direction")
	bool XNegative;
	UPROPERTY(EditAnywhere, Category="Direction")
	bool YPositive;
	UPROPERTY(EditAnywhere, Category="Direction")
	bool YNegative;
	UPROPERTY(EditAnywhere, Category="Direction")
	bool ZPositive;
	UPROPERTY(EditAnywhere, Category="Direction")
	bool ZNegative;

	UPROPERTY(EditAnywhere, Category="Movement")
	float PlatformVelocity = 100;
	UPROPERTY(EditAnywhere, category="Movement")
	float DistanceLimit = 1000;

	UPROPERTY(EditAnywhere, category="Movement")
	float DistanceMoved = -1;

	FVector PlatformChange = FVector(0,0,0);

	FVector StartLocation;
};
