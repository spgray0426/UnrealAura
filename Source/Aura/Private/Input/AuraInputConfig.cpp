// Copyright JSY


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FAuraInputAction& Action: AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("InputTag에 대한 AbilityInputAction을 찾을 수 없습니다 , [%s] InputConfig에서 [%s]"), *GetNameSafe(this), *InputTag.ToString());
	}

	return nullptr;
}
