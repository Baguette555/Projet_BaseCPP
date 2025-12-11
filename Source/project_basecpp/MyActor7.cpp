// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor7.h"
#include "project_basecppCharacter.h"

// Sets default values
AMyActor7::AMyActor7()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Création du root
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Comp"));
	SetRootComponent(RootComp); // Déterminer l'objet en root component

	// Création du trigger
	TriggerComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Comp"));
	TriggerComp->SetupAttachment(RootComp); // Attacher le trigger au Root Component
	TriggerComp->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f)); // Fixer la taille par défaut

	TriggerComp->OnComponentBeginOverlap.AddDynamic(this, &AMyActor7::OnOverlapBegin); // Attacher Dynamiquement le begin overlap au trigger
	TriggerComp->OnComponentEndOverlap.AddDynamic(this, &AMyActor7::OnOverlapEnd); // Attacher Dynamiquement le end overlap au trigger

	// Création du mesh
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Comp"));
	MyMesh->SetupAttachment(RootComp); // Attacher le mesh au Root Component

	// -------> Attribution d'un cube au static mesh ------->
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));

		if (CubeMesh.Succeeded())
		{
			MyMesh->SetStaticMesh(CubeMesh.Object);
		}
	// ----------------------------------------------------->

		Tags.Add("mon_tag"); // permet de rajouter un tag sur l'acteur
}

void AMyActor7::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor7::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ******************** Overlapping ********************
//    ******************** Start ********************
void AMyActor7::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	Aproject_basecppCharacter* Player = Cast<Aproject_basecppCharacter>(OtherActor); // Cast Aproject_basecppCharacter dans OtherActor
	if (Player)
	{
		Player->OnOverlapWithCppActor(15); // Appel de l'event blueprint
	}
	UE_LOG(LogTemp, Warning, TEXT("je suis rentre je suis rentre!!!! !pjzojifdojidoijdfoipjfdqsoipj"));
}
//    ***********************************************
// 
//    ********************* End *********************
void AMyActor7::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("je suis sorti du cube"));
}
//    ***********************************************
// *****************************************************