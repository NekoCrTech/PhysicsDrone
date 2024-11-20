// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PhDronePawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UPhysicsFloatingMovementComponent;

UCLASS()
class PHYSICSDRONE_API APhDronePawn : public APawn
{
	GENERATED_BODY()

public:
	
	APhDronePawn();


protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetThrottleInput(float Value);
	UFUNCTION(BlueprintCallable)
	void SetPitchInput(float Value);
	UFUNCTION(BlueprintCallable)
	void SetYawInput(float Value);
	UFUNCTION(BlueprintCallable)
	void SetRollInput(float Value);

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USkeletalMesh* DroneMesh; 
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Physics Floating Movement")
	TObjectPtr<UPhysicsFloatingMovementComponent> DroneMovementComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Pawn|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Pawn|Properties")
	USkeletalMeshComponent* DroneMeshComponent;
	
private:
	

	UPROPERTY(EditDefaultsOnly, Category = "Pawn|Camera")
	TObjectPtr<UCameraComponent> Camera;
	
};
