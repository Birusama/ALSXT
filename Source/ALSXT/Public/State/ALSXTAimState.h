#pragma once

#include "ALSXTAimState.generated.h"

USTRUCT(BlueprintType)
struct ALSXT_API FALSXTAimState
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = -180, ClampMax = 180, ForceUnits = "deg"))
		FRotator ControlRotation { EForceInit::ForceInit };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTag WeaponReadyPosition{ FGameplayTag::EmptyTag };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTag FirearmStance{ FGameplayTag::EmptyTag };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTag FirearmSightLocation{ FGameplayTag::EmptyTag };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTag FingerPose{ FGameplayTag::EmptyTag };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTag FingerPoseAnimation{ FGameplayTag::EmptyTag };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector OriginPoint{ EForceInit::ForceInit };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform OriginTransform;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform OriginOffset;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform GripTransform;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName GripSocketName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform ForegripTransform;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ForegripSocketName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTag ForegripAnimation{ FGameplayTag::EmptyTag };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector TargetPoint{ EForceInit::ForceInit };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform TargetTransform;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform OpticTransform;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName OpticSocketName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform FrontSightTransform;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName FrontSightSocketName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector BarrelPoint{ EForceInit::ForceInit };

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName BarrelSocketName;
};

