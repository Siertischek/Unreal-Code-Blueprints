// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	if(XPositive)
	{
		PlatformChange.X = PlatformChange.X + PlatformVelocity;
	}
	if(XNegative)
	{
		PlatformChange.X = PlatformChange.X - PlatformVelocity;
	}
	if(YPositive)
	{
		PlatformChange.Y = PlatformChange.Y + PlatformVelocity;
	}
	if(YNegative)
	{
		PlatformChange.Y = PlatformChange.Y - PlatformVelocity;
	}
	if(ZPositive)
	{
		PlatformChange.Z = PlatformChange.Z + PlatformVelocity;
	}
	if(ZNegative)
	{
		PlatformChange.Z = PlatformChange.Z - PlatformVelocity;
	}

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + PlatformChange * DeltaTime;

	SetActorLocation(CurrentLocation);
	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if(DistanceMoved > DistanceLimit)
	{
		FVector MoveDirection = PlatformChange.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * DistanceLimit;
		SetActorLocation(StartLocation);
		PlatformChange = -PlatformChange;
	}
}

