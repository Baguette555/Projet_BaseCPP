// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor4.h"

// Sets default values
AMyActor4::AMyActor4()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor4::BeginPlay()
{
	Super::BeginPlay();

	AMyActor4::My_Member_Function1();
	AMyActor4::My_Member_Function2(My_Menber_Int, 1);
	My_Menber_Int = AMyActor4::My_Member_Function3(My_Menber_Int, 2);
	AMyActor4::My_Member_Function1();
	
}

// Called every frame
void AMyActor4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (My_Bool)
	{
		UE_LOG(LogTemp, Display, TEXT("My_Menber_Int = %d"), My_Menber_Int);
	}

}

// Fonctions
void AMyActor4::My_Member_Function1()
{

	UE_LOG(LogTemp, Display, TEXT("-------------------------->test de fonction "));
}


void AMyActor4::My_Member_Function2(int My_int1, int My_int2)
{
	int My_Int3 = My_int1 + My_int2;
	My_Menber_Int = My_Int3;
}


int AMyActor4::My_Member_Function3(int My_int1, int My_int2)
{
	int My_Int3 = My_int1 * My_int2;
	return My_Int3;
}
