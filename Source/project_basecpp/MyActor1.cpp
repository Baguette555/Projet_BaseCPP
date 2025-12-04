// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"

// Sets default values
AMyActor1::AMyActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Display, TEXT("ceci est mon premier texte en begin play"));

	// les différents type de varialbes les plus communes.

	float My_Float = 0.1f; //(variable en 32 bits)
	double My_Double = 1.2; //(variable en 64 bits plus précis au dela d'un certains nombre de chiffre aprés la virgule mais prend plus de mémoire)
	int My_Int = 10;
	char My_Char = 'a';
	bool My_bool = true;
	FString My_Fstring = "bonjour";
	FVector My_Fvector = FVector(0.2f, 1.0f, 3.1f);

	UE_LOG(LogTemp, Display, TEXT("affichage de mes differentes variable------------------debut-----------------"));


	UE_LOG(LogTemp, Display, TEXT("float %f"), My_Float);
	UE_LOG(LogTemp, Display, TEXT("double %f"), My_Double);
	UE_LOG(LogTemp, Display, TEXT("integer %d"), My_Int);
	UE_LOG(LogTemp, Display, TEXT("character %c"), My_Char);
	UE_LOG(LogTemp, Display, TEXT("Bool %s"), My_bool ? TEXT("true") : TEXT("false"));
	UE_LOG(LogTemp, Display, TEXT("Fstring %s"), *My_Fstring);
	UE_LOG(LogTemp, Display, TEXT("affichage fvector %s"), *My_Fvector.ToCompactString()); // converti le fvector en string pour pouvoir l'afficher



	UE_LOG(LogTemp, Display, TEXT("affichage de mes differentes variable------------------fin-----------------"));
	
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

