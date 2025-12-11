// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor6.h"

// Sets default values
AMyActor6::AMyActor6()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor6::BeginPlay()
{
	Super::BeginPlay();
	Start_point = GetActorLocation();
	
}

// Called every frame
void AMyActor6::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	distance_resolution();
	Actor_Move();
	UE_LOG(LogTemp, Display, TEXT("float %f"), My_Distance);

}

void AMyActor6::distance_resolution()
{
	FVector Actual_Location = GetActorLocation();
	My_Distance = FVector::Dist(Actual_Location, Start_point);

	if (B_Fall_Back == false and My_Distance > Distance_to_go)
	{
		B_Fall_Back = true;
	}
	else
	{
		if (B_Fall_Back == true and My_Distance < 10)
		{
			B_Fall_Back = false;
		}
	}
	return void();
}

void AMyActor6::Actor_Move()
{
	if (B_Fall_Back == false)
	{
		AddActorLocalOffset(Direction_vector * platform_speed);
	}

	else
	{
		AddActorLocalOffset((Direction_vector * platform_speed) * -1);
	}
}

