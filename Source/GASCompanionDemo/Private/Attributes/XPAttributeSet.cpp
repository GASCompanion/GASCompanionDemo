// Copyright 2021 Mickael Daniel. All Rights Reserved.


#include "Attributes/XPAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

// Sets default values
UXPAttributeSet::UXPAttributeSet()
{
	// Set default values for this Set Attributes here
}

void UXPAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max attributes we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);
}

void UXPAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

	FGSCAttributeSetExecutionData ExecutionData;
	GetExecutionDataFromMod(Data, ExecutionData);

	AActor* SourceActor = ExecutionData.SourceActor;
	AActor* TargetActor = ExecutionData.TargetActor;

	// And cast SourceActor / TargetActor to whatever Character classes you may be using and need access to

    const FGameplayTagContainer SourceTags = ExecutionData.SourceTags;
    const FGameplayEffectContextHandle Context = ExecutionData.Context;

	// ...
}

void UXPAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, CurrentXP, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, NextLevelXPThreshold, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UXPAttributeSet, Level, COND_None, REPNOTIFY_Always);
}

void UXPAttributeSet::OnRep_CurrentXP(const FGameplayAttributeData& OldCurrentXP)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet, CurrentXP, OldCurrentXP);
}

void UXPAttributeSet::OnRep_NextLevelXPThreshold(const FGameplayAttributeData& OldNextLevelXPThreshold)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet, NextLevelXPThreshold, OldNextLevelXPThreshold);
}

void UXPAttributeSet::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UXPAttributeSet, Level, OldLevel);
}
