// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "PhysicsFloatingMovementComponent.generated.h"


enum class ESystemPosition : uint8;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSDRONE_API UPhysicsFloatingMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPhysicsFloatingMovementComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	FVector4 GetControls();

	UFUNCTION()
	void SetOwnerData(AActor* InOwner);
	
	
	// Inputs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drone Input")
	float ThrottleInput; // Range: 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drone Input")
	float PitchInput; // Range: -1.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drone Input")
	float RollInput; // Range: -1.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drone Input")
	float YawInput; // Range: -1.0 to 1.0

	// Drone configuration
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drone Config")
	float MaxThrust; // Maximum thrust per motor (e.g., 10.0 N)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drone Config")
	float DragCoefficient; // Propeller drag coefficient (e.g., 0.0001)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drone Config")
	float ArmLength; // Distance from the center to each motor (e.g., 0.2 meters)

	// Physics simulation
	void CalculateMotorForces();

protected:
	virtual void BeginPlay() override;

private:
	
	TArray<float> MotorForces; // Stores calculated thrust for each motor
	void ApplyForcesToDrone();

	UPROPERTY()
	AActor* CompOwner = nullptr;
	
			
};
