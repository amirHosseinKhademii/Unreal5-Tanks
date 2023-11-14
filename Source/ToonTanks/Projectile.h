// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent *ProjectileMesh;

	UPROPERTY(VisibleAnyWhere, Category = "Movement")
	class UProjectileMovementComponent *ProjectileMovement;

	UFUNCTION()
	void OnHit(UPrimitiveComponent *HitComp,
			   AActor *OtherActor,
			   UPrimitiveComponent *OtherComp,
			   FVector NormalImpulse,
			   const FHitResult &Hit);

	UPROPERTY(EditAnywhere, Category = "Damage")
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystem *HitParticle;

	UPROPERTY(VisibleAnywhere, Category = "Effects")
	class UParticleSystemComponent *TrailParticle;

	UPROPERTY(EditAnywhere, Category = "Effects")
	class USoundBase *HitSound;

	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase *LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
};
