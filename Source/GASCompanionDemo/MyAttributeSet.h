// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "MyAttributeSet.generated.h"

UCLASS()
class GASCOMPANIONDEMO_API UMyAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UMyAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Yo)
    FGameplayAttributeData Yo = 10.0;
    ATTRIBUTE_ACCESSORS(UMyAttributeSet, Yo)    

protected:
    
    UFUNCTION()
    virtual void OnRep_Yo(const FGameplayAttributeData& OldYo);
	
	
};
