// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();

	bool My_Bool = false;
	int My_Int = 0;
	int My_Int2 = 0;

	// condition if

	if (My_Bool)
	{
		UE_LOG(LogTemp, Display, TEXT("My_Bool = true"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("My_Bool = false"));
	}

	// boucle while

	while (My_Int < 20)
	{
		My_Int = My_Int + 1;
		UE_LOG(LogTemp, Display, TEXT("integer %d"), My_Int);
	}

	UE_LOG(LogTemp, Display, TEXT("reached limit"));

	// boucle while with break

	while (My_Int2 < 20)
	{
		My_Int2 = My_Int2 + 1;
		UE_LOG(LogTemp, Display, TEXT("integer %d"), My_Int2);

		if (My_Int2 > 15)
		{
			UE_LOG(LogTemp, Display, TEXT("break activated"));
			break; // on sort de la boucle direct
		}
	}
	
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

