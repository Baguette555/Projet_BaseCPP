// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformExo_TrigBox2.h"

// *********************** CONSTRUCTOR *********************** 
UPlatformExo_TrigBox2::UPlatformExo_TrigBox2()
{
	PrimaryComponentTick.bCanEverTick = true; //Ajout du tick
	UE_LOG(LogTemp, Warning, TEXT("ok garmin ca marche"));
}
// ***********************************************************

// *********************** Begin Play ***********************
void UPlatformExo_TrigBox2::BeginPlay()
{
	Super::BeginPlay();

	// ici lie l'event "OnComponentBeginOverlap" à la fonction "OnOverlapBegin"
	OnComponentBeginOverlap.AddDynamic(this, &UPlatformExo_TrigBox2::OnOverlapBegin); //& devant la fonction permet de recuperer correctement l'adresse de la fonction (pointeur de fonction)
	OnComponentEndOverlap.AddDynamic(this, &UPlatformExo_TrigBox2::OnOverlapEnd);

	Actor_Owner->GetRootComponent()->SetMobility(EComponentMobility::Movable);// passe le component en movable pour eviter qu'il reste statique je le fais direct dans le constructor.
	Start_point = Actor_Owner->GetActorLocation();
}
// **********************************************************

// *********************** Tick ***********************
void UPlatformExo_TrigBox2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (isOnIt)
	{
		distance_resolution();
		Actor_Move();
	}
}
// ****************************************************

// ******************** Overlapping ********************
//    ******************** Start ********************
void UPlatformExo_TrigBox2::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("je suis rentre je suis rentre!!!! !pjzojifdojidoijdfoipjfdqsoipj"));
	isOnIt = true;
}
//    ***********************************************
// 
//    ********************* End *********************
void UPlatformExo_TrigBox2::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("je suis sorti du cube"));
	isOnIt = false;
}
//    ***********************************************
// *****************************************************

void UPlatformExo_TrigBox2::distance_resolution()
{
	FVector Actual_Location = Actor_Owner->GetActorLocation();
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

void UPlatformExo_TrigBox2::Actor_Move()
{
	if (B_Fall_Back == false)
	{
		Actor_Owner->AddActorLocalOffset(Direction_vector * platform_speed);
	}

	else
	{
		Actor_Owner->AddActorLocalOffset((Direction_vector * platform_speed) * -1);
	}
}