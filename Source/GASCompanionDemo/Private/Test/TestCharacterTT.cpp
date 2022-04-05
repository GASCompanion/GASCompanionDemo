// Copyright 2020 Mickael Daniel. All Rights Reserved.


#include "Test/TestCharacterTT.h"

// Sets default values
ATestCharacterTT::ATestCharacterTT()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestCharacterTT::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATestCharacterTT::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestCharacterTT::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

