// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Module5Proj/Module5ProjGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModule5ProjGameMode() {}
// Cross Module References
	MODULE5PROJ_API UClass* Z_Construct_UClass_AModule5ProjGameMode_NoRegister();
	MODULE5PROJ_API UClass* Z_Construct_UClass_AModule5ProjGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Module5Proj();
// End Cross Module References
	void AModule5ProjGameMode::StaticRegisterNativesAModule5ProjGameMode()
	{
	}
	UClass* Z_Construct_UClass_AModule5ProjGameMode_NoRegister()
	{
		return AModule5ProjGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AModule5ProjGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AModule5ProjGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Module5Proj,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AModule5ProjGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Module5ProjGameMode.h" },
		{ "ModuleRelativePath", "Module5ProjGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AModule5ProjGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AModule5ProjGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AModule5ProjGameMode_Statics::ClassParams = {
		&AModule5ProjGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AModule5ProjGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AModule5ProjGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AModule5ProjGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AModule5ProjGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AModule5ProjGameMode, 2893075706);
	template<> MODULE5PROJ_API UClass* StaticClass<AModule5ProjGameMode>()
	{
		return AModule5ProjGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AModule5ProjGameMode(Z_Construct_UClass_AModule5ProjGameMode, &AModule5ProjGameMode::StaticClass, TEXT("/Script/Module5Proj"), TEXT("AModule5ProjGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AModule5ProjGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
