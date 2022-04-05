// Copyright 2020 Mickael Daniel. All Rights Reserved.


#include "TestAttributeSet.h"
#include "Net/UnrealNetwork.h"

// Sets default values
UTestAttributeSet::UTestAttributeSet()
{
	// Default constructor
}

void UTestAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max attributes we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);

    // Set adjust code here
    //
    // Example:
    //
    // If a Max value changes, adjust current to keep Current % of Current to Max
    //
    // if (Attribute == GetMaxHealthAttribute())
    // {
    //     AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
    // }
}

void UTestAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    FGSCAttributeSetExecutionData ExecutionData;
    GetExecutionDataFromMod(Data, ExecutionData);

    AActor* SourceActor = ExecutionData.SourceActor;
    AActor* TargetActor = ExecutionData.TargetActor;

    // And cast SourceActor / TargetActor to whatever Character classes you may be using and need access to

    // Set clamping or handling or "meta" attributes here (like damages)

    // Example 1: Using helpers to handle each attribute in their own methods (See GSCAttributeSet.cpp)

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     HandleHealthAttribute(ExecutionData);
    // }

    // Example 2: Basic example to clamp the value of an Health Attribute between 0 and another MaxHealth Attribute

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
    // }
}

void UTestAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UTestAttributeSet, SomeAttr, COND_None, REPNOTIFY_Always);
}

void UTestAttributeSet::OnRep_SomeAttr(const FGameplayAttributeData& OldSomeAttr)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UTestAttributeSet, SomeAttr, OldSomeAttr);
}
