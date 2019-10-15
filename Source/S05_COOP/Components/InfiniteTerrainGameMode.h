// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S05_COOPGameModeBase.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class S05_COOP_API AInfiniteTerrainGameMode : public AS05_COOPGameModeBase
{
	GENERATED_BODY()

public:

	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, Category ="Pool")
	class UActorPool* NavMeshBoundsVolumePool;
	
private:

	void AddToPool(class ANavMeshBoundsVolume* VolumeToAdd);
};
