// Copyright JSY


#include "UI/HUD/AuraHUD.h"

#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (!IsValid(OverlayWidgetController))
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("오버레이 위젯 클래스가 초기화되지 않았으니, BP_AuraHUD 작성해 주세요"));
	checkf(OverlayWidgetControllerClass, TEXT("오버레이 위젯 컨트롤러 클래스가 초기화되지 않음, BP_AuraHUD 작성해 주세요"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);
	
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	//블루프린트에서의 초기화
	OverlayWidget->SetWidgetController(WidgetController);
	
	//블루프린트에서의 초기화도 끝나고 값 설정
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}


