// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformExo_TrigBox1.h"
#include "project_basecppCharacter.h"

// *********************** CONSTRUCTOR *********************** 
UPlatformExo_TrigBox1::UPlatformExo_TrigBox1()
{
	PrimaryComponentTick.bCanEverTick = true; //Ajout du tick
	UE_LOG(LogTemp, Warning, TEXT("ok garmin ca marche"));
}
// ***********************************************************

// *********************** Begin Play ***********************
void UPlatformExo_TrigBox1::BeginPlay()
{
	Super::BeginPlay();

	// ici lie l'event "OnComponentBeginOverlap" à la fonction "OnOverlapBegin"
	OnComponentBeginOverlap.AddDynamic(this, &UPlatformExo_TrigBox1::OnOverlapBegin); //& devant la fonction permet de recuperer correctement l'adresse de la fonction (pointeur de fonction)
	OnComponentEndOverlap.AddDynamic(this, &UPlatformExo_TrigBox1::OnOverlapEnd);

	SelfActor->GetRootComponent()->SetMobility(EComponentMobility::Movable);// passe le component en movable pour eviter qu'il reste statique je le fais direct dans le constructor.
}
// **********************************************************

void UPlatformExo_TrigBox1::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// ******************** Overlapping ********************
//    ******************** Start ********************
void UPlatformExo_TrigBox1::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	Aproject_basecppCharacter* Player = Cast<Aproject_basecppCharacter>(OtherActor); // Cast Aproject_basecppCharacter dans OtherActor
	if (Player)
	{
		FVector Checkpoint_Location;
		Checkpoint_Location = FVector(Checkpoint_Cible->GetActorLocation());
		Player->SetActorLocation(Checkpoint_Location);
	}
	UE_LOG(LogTemp, Warning, TEXT("Faut tuer le joueur mtn"));
}
//    ***********************************************
// *****************************************************

//    ********************* End *********************
void UPlatformExo_TrigBox1::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("je suis sorti du deathzone"));
}
//    ***********************************************
// *****************************************************