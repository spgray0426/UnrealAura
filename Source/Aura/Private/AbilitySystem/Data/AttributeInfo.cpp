// Copyright JSY


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] 속성정보에서 AttributeTag 정보를 찾을 수 없습니다 [%s]."), *GetNameSafe(this), *AttributeTag.ToString());
	}

	return FAuraAttributeInfo();
}