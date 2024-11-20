// Created by Neko Creative Technologies


#include "PhysicsFloatingMovement/PhysicsFloatingMovementComponent.h"



UPhysicsFloatingMovementComponent::UPhysicsFloatingMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.5f;

	
	ThrottleInput = 0.0f;
	PitchInput = 0.0f;
	RollInput = 0.0f;
	YawInput = 0.0f;

	ArmLength = 0.2f;
	MaxThrust = 1000.0f; // Newtons
	DragCoefficient = 0.0001f;
	
}

void UPhysicsFloatingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Update motor forces based on current inputs
	CalculateMotorForces();
}

FVector4 UPhysicsFloatingMovementComponent::GetControls()
{
	return FVector4 {MotorForces[0],MotorForces[1],MotorForces[2],MotorForces[3]};
}

void UPhysicsFloatingMovementComponent::SetOwnerData(AActor* InOwner)
{
	CompOwner = InOwner;
}

void UPhysicsFloatingMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	MotorForces.Init(0.0f, 4);
	
}

void UPhysicsFloatingMovementComponent::CalculateMotorForces()
{
	// Inputs: T (Throttle), P (Pitch), R (Roll), Y (Yaw)
	float T = ThrottleInput * MaxThrust;
	float P = PitchInput * MaxThrust;
	float R = RollInput * MaxThrust;
	float Y = YawInput * MaxThrust;

	// Calculate motor thrust forces
	MotorForces[0] = T + P + R - Y; // Front-Left Motor
	MotorForces[1] = T + P - R + Y; // Front-Right Motor
	MotorForces[2] = T - P + R + Y; // Back-Left Motor
	MotorForces[3] = T - P - R - Y; // Back-Right Motor

	// Clamp motor forces to physical limits
	for (int32 i = 0; i < MotorForces.Num(); i++)
	{
		MotorForces[i] = FMath::Clamp(MotorForces[i], 0.0f, MaxThrust);
	}
	// Apply forces to the drone
	ApplyForcesToDrone();
}

void UPhysicsFloatingMovementComponent::ApplyForcesToDrone()
{
	if (CompOwner != nullptr)
	{
		if (UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(CompOwner->GetRootComponent()))
		{
					
			for (int32 i = 0; i < MotorForces.Num(); i++)
			{
				Root->AddForce(CompOwner->GetActorUpVector() * MotorForces[i], FName("Root") , true);
				UE_LOG(LogTemp, Warning, TEXT("Force: %f"), MotorForces[i]);
			}

			

			// // Calculate torques based on the motor positions and forces
			// FVector Torque = FVector::ZeroVector;
			//
			// // Pitch Torque (Front-Back motors)
			// float PitchTorque = ArmLength * (MotorForces[2] + MotorForces[3] - MotorForces[0] - MotorForces[1]);
			// Torque.X += PitchTorque; // Positive X is forward pitch
			//
			// // Roll Torque (Left-Right motors)
			// float RollTorque = ArmLength * (MotorForces[1] + MotorForces[3] - MotorForces[0] - MotorForces[2]);
			// Torque.Y += RollTorque; // Positive Y is right roll
			//
			// // Yaw Torque (Rotational drag difference between CW and CCW motors)
			// float YawTorque = DragCoefficient * (MotorForces[0] - MotorForces[1] + MotorForces[2] - MotorForces[3]);
			// Torque.Z += YawTorque; // Positive Z is counterclockwise yaw
			//
			// // Apply calculated torque to the root component (rotational force)
			// Root->AddTorqueInRadians(Torque, NAME_None, true);
			//
			// // Optional debug output
			// FString ForceMessage = FString::Printf(TEXT("Throttle Forces: %f, %f, %f"), MotorForces[0], MotorForces[1], MotorForces[2]);
			// FString TorqueMessage = FString::Printf(TEXT("Torque: %f, %f, %f"), Torque.X, Torque.Y, Torque.Z);
			// if (GEngine)
			// {
			// 	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Green, ForceMessage);
			// 	GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Green, TorqueMessage);
			// }
		}
	}
}

