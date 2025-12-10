// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxComponent_Exo1.h"

// *********************** CONSTRUCTOR *********************** 
UBoxComponent_Exo1::UBoxComponent_Exo1()
{
	PrimaryComponentTick.bCanEverTick = true; //Ajout du tick
	UE_LOG(LogTemp, Warning, TEXT("ok garmin ca marche"));
}
// ***********************************************************

// *********************** Begin Play ***********************
void UBoxComponent_Exo1::BeginPlay()
{
	Super::BeginPlay();

	// ici lie l'event "OnComponentBeginOverlap" à la fonction "OnOverlapBegin"
	OnComponentBeginOverlap.AddDynamic(this, &UBoxComponent_Exo1::OnOverlapBegin); //& devant la fonction permet de recuperer correctement l'adresse de la fonction (pointeur de fonction)
	OnComponentEndOverlap.AddDynamic(this, &UBoxComponent_Exo1::OnOverlapEnd);

	Actor_Owner->GetRootComponent()->SetMobility(EComponentMobility::Movable);// passe le component en movable pour eviter qu'il reste statique je le fais direct dans le constructor.
}
// **********************************************************

// *********************** Tick ***********************
void UBoxComponent_Exo1::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (isOnIt)
	{
		ActorMove(DeltaTime);
	}
}
// ****************************************************

// ******************** Overlapping ********************
//    ******************** Start ********************
void UBoxComponent_Exo1::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("je suis rentre je suis rentre!!!! !pjzojifdojidoijdfoipjfdqsoipj"));
	isOnIt = true;

}
//    ***********************************************
// 
//    ********************* End *********************
void UBoxComponent_Exo1::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("je suis sorti du cube"));
	isOnIt = false;
}
//    ***********************************************
// *****************************************************

void UBoxComponent_Exo1::ActorMove(float deltatime)
{
	Actor_Owner->AddActorLocalOffset(vector_cible * F_Speed);
}