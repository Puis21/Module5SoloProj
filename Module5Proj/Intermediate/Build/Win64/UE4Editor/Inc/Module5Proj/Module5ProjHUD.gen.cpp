// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Module5Proj/Module5ProjHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModule5ProjHUD() {}
// Cross Module References
	MODULE5PROJ_API UClass* Z_Construct_UClass_AModule5ProjHUD_NoRegister();
	MODULE5PROJ_API UClass* Z_Construct_UClass_AModule5ProjHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_Module5Proj();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AModule5ProjHUD::execUpdateAbilityShieldBar)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAbilityShieldBar(Z_Param_value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AModule5ProjHUD::execUpdateAbilitySwapBar)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_currentValue);
		P_GET_PROPERTY(FFloatProperty,Z_Param_maxValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAbilitySwapBar(Z_Param_currentValue,Z_Param_maxValue);
		P_NATIVE_END;
	}
	void AModule5ProjHUD::StaticRegisterNativesAModule5ProjHUD()
	{
		UClass* Class = AModule5ProjHUD::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateAbilityShieldBar", &AModule5ProjHUD::execUpdateAbilityShieldBar },
			{ "UpdateAbilitySwapBar", &AModule5ProjHUD::execUpdateAbilitySwapBar },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics
	{
		struct Module5ProjHUD_eventUpdateAbilityShieldBar_Parms
		{
			int32 value;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Module5ProjHUD_eventUpdateAbilityShieldBar_Parms, value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Module5ProjHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AModule5ProjHUD, nullptr, "UpdateAbilityShieldBar", nullptr, nullptr, sizeof(Module5ProjHUD_eventUpdateAbilityShieldBar_Parms), Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics
	{
		struct Module5ProjHUD_eventUpdateAbilitySwapBar_Parms
		{
			float currentValue;
			float maxValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_currentValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_maxValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::NewProp_currentValue = { "currentValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Module5ProjHUD_eventUpdateAbilitySwapBar_Parms, currentValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::NewProp_maxValue = { "maxValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Module5ProjHUD_eventUpdateAbilitySwapBar_Parms, maxValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::NewProp_currentValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::NewProp_maxValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Module5ProjHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AModule5ProjHUD, nullptr, "UpdateAbilitySwapBar", nullptr, nullptr, sizeof(Module5ProjHUD_eventUpdateAbilitySwapBar_Parms), Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AModule5ProjHUD_NoRegister()
	{
		return AModule5ProjHUD::StaticClass();
	}
	struct Z_Construct_UClass_AModule5ProjHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AbilityWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_AbilityWidgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AModule5ProjHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_Module5Proj,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AModule5ProjHUD_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilityShieldBar, "UpdateAbilityShieldBar" }, // 879774564
		{ &Z_Construct_UFunction_AModule5ProjHUD_UpdateAbilitySwapBar, "UpdateAbilitySwapBar" }, // 2095344293
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AModule5ProjHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Module5ProjHUD.h" },
		{ "ModuleRelativePath", "Module5ProjHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AModule5ProjHUD_Statics::NewProp_AbilityWidgetClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "Module5ProjHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AModule5ProjHUD_Statics::NewProp_AbilityWidgetClass = { "AbilityWidgetClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AModule5ProjHUD, AbilityWidgetClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AModule5ProjHUD_Statics::NewProp_AbilityWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AModule5ProjHUD_Statics::NewProp_AbilityWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AModule5ProjHUD_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AModule5ProjHUD_Statics::NewProp_AbilityWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AModule5ProjHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AModule5ProjHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AModule5ProjHUD_Statics::ClassParams = {
		&AModule5ProjHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AModule5ProjHUD_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AModule5ProjHUD_Statics::PropPointers),
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AModule5ProjHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AModule5ProjHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AModule5ProjHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AModule5ProjHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AModule5ProjHUD, 4005335918);
	template<> MODULE5PROJ_API UClass* StaticClass<AModule5ProjHUD>()
	{
		return AModule5ProjHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AModule5ProjHUD(Z_Construct_UClass_AModule5ProjHUD, &AModule5ProjHUD::StaticClass, TEXT("/Script/Module5Proj"), TEXT("AModule5ProjHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AModule5ProjHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
