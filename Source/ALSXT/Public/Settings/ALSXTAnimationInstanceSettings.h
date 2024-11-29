#pragma once

#include "GameplayTagContainer.h"
#include "ALSXT/Public/Settings/ALSXTStationaryModeSettings.h"
#include "ALS/Public/Settings/AlsFeetSettings.h"
#include "ALS/Public/Settings/AlsGeneralAnimationSettings.h"
#include "ALS/Public/Settings/AlsGroundedSettings.h"
#include "ALS/Public/Settings/AlsInAirSettings.h"
#include "ALS/Public/Settings/AlsRotateInPlaceSettings.h"
#include "ALS/Public/Settings/AlsTransitionsSettings.h"
#include "ALS/Public/Settings/AlsTurnInPlaceSettings.h"
#include "ALS/Public/Settings/AlsViewAnimationSettings.h"
#include "Engine/DataAsset.h"
#include "ALSXTAnimationInstanceSettings.generated.h"

USTRUCT(BlueprintType)
struct ALSXT_API FALSXTJigglePhysicsSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EnableBreastsJigglePhysics{ false };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EnableButtJigglePhysics{ false };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EnableBellyJigglePhysics{ false };
};

UCLASS(Blueprintable, BlueprintType)
class ALSXT_API UALSXTAnimationInstanceSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FALSXTJigglePhysicsSettings JigglePhysicsSettings;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FALSXTStationaryModeAnimations StationaryMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsGeneralAnimationSettings General;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsViewAnimationSettings View;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsGroundedSettings Grounded;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsInAirSettings InAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsFeetSettings Feet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsTransitionsSettings Transitions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsRotateInPlaceSettings RotateInPlace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsGeneralTurnInPlaceSettings TurnInPlace;

public:
	UALSXTAnimationInstanceSettings();

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
