// Created by Neko Creative Tecnologies

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuadcopterPhMovComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSDRONE_API UQuadcopterPhMovComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuadcopterPhMovComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
