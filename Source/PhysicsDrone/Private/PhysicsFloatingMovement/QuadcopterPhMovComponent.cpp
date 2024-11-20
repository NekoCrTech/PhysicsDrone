// Created by Neko Creative Tecnologies


#include "PhysicsFloatingMovement/QuadcopterPhMovComponent.h"

// Sets default values for this component's properties
UQuadcopterPhMovComponent::UQuadcopterPhMovComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuadcopterPhMovComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuadcopterPhMovComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

