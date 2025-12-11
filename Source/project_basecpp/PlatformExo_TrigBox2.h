// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "PlatformExo_TrigBox2.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) //Permet de l'appliquer sur un acteur
class PROJECT_BASECPP_API UPlatformExo_TrigBox2 : public UBoxComponent
{
	GENERATED_BODY()

	// public: //appel du constructor qui n'est pas là d'office, je le rajoute donc
	UPlatformExo_TrigBox2();

public:
	UPROPERTY(EditAnywhere, Category = "Platform Parameters")
	float Distance_to_go = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Platform Parameters")
	FVector Direction_vector = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = "Platform Parameters")
	float platform_speed = 0.0f;

	FVector Start_point = FVector(0.0f, 0.0f, 0.0f);
	float My_Distance = 0.0;

	AActor* Actor_Owner = GetOwner();
	bool isOnIt = false;
	bool B_Fall_Back = false;


	// public fonctions
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void distance_resolution();
	void Actor_Move();


protected:

	virtual void BeginPlay() override;


private:

	/** called when something enters the box component */
	UFUNCTION()// = UFunction = fonction utilisée par unreal
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the box component */
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
