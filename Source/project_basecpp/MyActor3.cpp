// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor3.h"

// Fonctions---------------->
void My_Function()// fonction simple
{
	UE_LOG(LogTemp, Display, TEXT("this is my function"));
}

void My_Function2(int My_Int1, int My_Int2)// fonction avec arguments
{
	int My_int3 = My_Int1 + My_Int2;
	UE_LOG(LogTemp, Display, TEXT("resultat calcul avec passage de valeurs %d"), My_int3);
}

float My_Function3(float My_float1, float My_float2)// fonction avec arguments et retour
{
	float My_float3 = My_float1 + My_float2;
	return My_float3;
}
// Fonctions---------------->


// Sets default values
AMyActor3::AMyActor3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	My_Function();

	My_Function2(2, 5);

	float My_Float4 = My_Function3(2.2f, 3.4f);
	UE_LOG(LogTemp, Display, TEXT("float %f"), My_Float4);

}

