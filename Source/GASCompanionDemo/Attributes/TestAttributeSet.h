// Copyright 2020 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "TestAttributeSet.generated.h"

UCLASS()
class GASCOMPANIONDEMO_API UTestAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UTestAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_SomeAttr)
    FGameplayAttributeData SomeAttr = 0.0;
    ATTRIBUTE_ACCESSORS(UTestAttributeSet, SomeAttr)

protected:

    UFUNCTION()
    virtual void OnRep_SomeAttr(const FGameplayAttributeData& OldSomeAttr);
};
