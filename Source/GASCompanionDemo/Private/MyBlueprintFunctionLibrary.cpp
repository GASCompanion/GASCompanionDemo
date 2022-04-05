// Copyright 2020 Mickael Daniel. All Rights Reserved.


#include "MyBlueprintFunctionLibrary.h"

bool UMyBlueprintFunctionLibrary::DoSomethingElse(const AActor* Actor)
{
	return IsValid(Actor);
}
