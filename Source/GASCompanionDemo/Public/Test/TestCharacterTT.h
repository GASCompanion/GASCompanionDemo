// Copyright 2020 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestCharacterTT.generated.h"


USTRUCT(BlueprintType)
struct FTestStruct
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category="Test")
	float Foo = 0.f;

};

UCLASS()
class GASCOMPANIONDEMO_API ATestCharacterTT : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacterTT();

	UPROPERTY(EditDefaultsOnly, Category="Test")
	FTestStruct TestStruct;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
