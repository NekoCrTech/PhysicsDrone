// Created by Neko Creative Technologies


#include "Pawns/PhDronePawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PhysicsFloatingMovement/PhysicsFloatingMovementComponent.h"


APhDronePawn::APhDronePawn()
{
	PrimaryActorTick.bCanEverTick = false;

	DroneMovementComponent = CreateDefaultSubobject<UPhysicsFloatingMovementComponent>(TEXT("PhysicsDroneMovementComponent"));
	DroneMovementComponent->SetOwnerData(this);

	DroneMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("DroneSkeletalMeshComponent"));
	DroneMeshComponent->SetSimulatePhysics(true);
	SetRootComponent(DroneMeshComponent);
	
	if (DroneMesh)
	{
		DroneMeshComponent->SetSkeletalMesh(DroneMesh);
	}

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(DroneMeshComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->bDoCollisionTest = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void APhDronePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void APhDronePawn::SetThrottleInput(float Value)
{
	DroneMovementComponent->ThrottleInput = Value;
}

void APhDronePawn::SetPitchInput(float Value)
{
	DroneMovementComponent->PitchInput = Value;
}

void APhDronePawn::SetYawInput(float Value)
{
	DroneMovementComponent->YawInput = Value;
}

void APhDronePawn::SetRollInput(float Value)
{
	DroneMovementComponent->RollInput = Value;
}

