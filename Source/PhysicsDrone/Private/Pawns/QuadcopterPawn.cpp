// Created by Neko Creative Tecnologies


#include "Pawns/QuadcopterPawn.h"

// Sets default values
AQuadcopterPawn::AQuadcopterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuadcopterPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuadcopterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AQuadcopterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

