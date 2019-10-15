// Fill out your copyright notice in the Description page of Project Settings.

#include "SHealthComponent.h"
#include "Character/SCharacter.h"

#include "Net/UnrealNetwork.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
USHealthComponent::USHealthComponent()
{
	DefaultHealth = 100;



	
}


// Called when the game starts
void USHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &USHealthComponent::HandleTakeAnyDamage);
	}

	Health = DefaultHealth;
	
}



void USHealthComponent::HandleTakeAnyDamage(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	if (Damage <= 0.0f)
	{
		return;
	}


	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
	FVector Location = DamagedActor->GetActorLocation();
	FString HealthDelta = *FString::SanitizeFloat(Health);
	DrawDebugString(GetWorld(), Location, HealthDelta, DamagedActor, FColor::Red, .1f, 0, 2.f);
	OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamagedActor);
}



