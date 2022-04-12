// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "XPAttributeSet.generated.h"

UCLASS()
class GASCOMPANIONDEMO_API UXPAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UXPAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "XP", ReplicatedUsing = OnRep_CurrentXP)
    FGameplayAttributeData CurrentXP = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, CurrentXP)    
    
    UPROPERTY(BlueprintReadOnly, Category = "XP", ReplicatedUsing = OnRep_NextLevelXPThreshold)
    FGameplayAttributeData NextLevelXPThreshold = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, NextLevelXPThreshold)    
    
    UPROPERTY(BlueprintReadOnly, Category = "XP", ReplicatedUsing = OnRep_Level)
    FGameplayAttributeData Level = 0.0;
    ATTRIBUTE_ACCESSORS(UXPAttributeSet, Level)    

protected:
    
    UFUNCTION()
    virtual void OnRep_CurrentXP(const FGameplayAttributeData& OldCurrentXP);

    UFUNCTION()
    virtual void OnRep_NextLevelXPThreshold(const FGameplayAttributeData& OldNextLevelXPThreshold);

    UFUNCTION()
    virtual void OnRep_Level(const FGameplayAttributeData& OldLevel);
};
