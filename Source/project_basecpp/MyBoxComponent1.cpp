// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBoxComponent1.h"

// *********************** CONSTRUCTOR *********************** 
UMyBoxComponent1::UMyBoxComponent1()
{
	PrimaryComponentTick.bCanEverTick = true; //Ajout du tick
	UE_LOG(LogTemp, Warning, TEXT("ok garmin ca marche"));
}
// ***********************************************************

// *********************** Begin Play ***********************
void UMyBoxComponent1::BeginPlay()
{
	Super::BeginPlay();

	// ici lie l'event "OnComponentBeginOverlap" à la fonction "OnOverlapBegin"
	OnComponentBeginOverlap.AddDynamic(this, &UMyBoxComponent1::OnOverlapBegin); //& devant la fonction permet de recuperer correctement l'adresse de la fonction (pointeur de fonction)
	OnComponentEndOverlap.AddDynamic(this, &UMyBoxComponent1::OnOverlapEnd);
}
// **********************************************************

// *********************** Tick ***********************
void UMyBoxComponent1::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
// ****************************************************

// ******************** Overlapping ********************
//    ******************** Start ********************
void UMyBoxComponent1::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("je suis rentre je suis rentre!!!! !pjzojifdojidoijdfoipjfdqsoipj"));

}
//    ***********************************************
// 
//    ********************* End *********************
void UMyBoxComponent1::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("je suis sorti du cube"));
}
//    ***********************************************
// *****************************************************