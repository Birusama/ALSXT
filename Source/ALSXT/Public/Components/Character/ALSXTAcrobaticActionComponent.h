// MIT

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ALSXTCharacter.h"
#include "Settings/ALSXTAcrobaticActionSettings.h"
#include "Interfaces/ALSXTCharacterInterface.h"
#include "ALSXTAcrobaticActionComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALSXT_API UALSXTAcrobaticActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UALSXTAcrobaticActionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", Meta = (AllowPrivateAccess))
	TObjectPtr<UALSXTAcrobaticActionSettings> Settings;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", Meta = (AllowPrivateAccess))
	FALSXTGeneralAcrobaticActionSettings GeneralAcrobaticActionSettings;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Settings")
	bool CanPerformAcrobaticAction();

	UFUNCTION(BlueprintCallable, Category = "Settings")
	void TryAcrobaticAction();

	UFUNCTION(BlueprintCallable, Category = "Settings")
	void DetermineAcrobaticActionType(FGameplayTag& AcrobaticActionType);

	void BeginFlip();

	UFUNCTION(Server, Reliable)
	void ServerBeginFlip();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastBeginFlip();

	void BeginWallJump();

	void BeginWallRun();

	FTimerHandle WallRunTimer;

	void UpdateWallRun();

	void EndWallRun();
};
