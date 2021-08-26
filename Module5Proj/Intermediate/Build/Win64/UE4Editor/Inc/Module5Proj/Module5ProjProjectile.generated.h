// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef MODULE5PROJ_Module5ProjProjectile_generated_h
#error "Module5ProjProjectile.generated.h already included, missing '#pragma once' in Module5ProjProjectile.h"
#endif
#define MODULE5PROJ_Module5ProjProjectile_generated_h

#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_SPARSE_DATA
#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAModule5ProjProjectile(); \
	friend struct Z_Construct_UClass_AModule5ProjProjectile_Statics; \
public: \
	DECLARE_CLASS(AModule5ProjProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Module5Proj"), NO_API) \
	DECLARE_SERIALIZER(AModule5ProjProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAModule5ProjProjectile(); \
	friend struct Z_Construct_UClass_AModule5ProjProjectile_Statics; \
public: \
	DECLARE_CLASS(AModule5ProjProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Module5Proj"), NO_API) \
	DECLARE_SERIALIZER(AModule5ProjProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AModule5ProjProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AModule5ProjProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AModule5ProjProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AModule5ProjProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AModule5ProjProjectile(AModule5ProjProjectile&&); \
	NO_API AModule5ProjProjectile(const AModule5ProjProjectile&); \
public:


#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AModule5ProjProjectile(AModule5ProjProjectile&&); \
	NO_API AModule5ProjProjectile(const AModule5ProjProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AModule5ProjProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AModule5ProjProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AModule5ProjProjectile)


#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AModule5ProjProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AModule5ProjProjectile, ProjectileMovement); }


#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_12_PROLOG
#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_SPARSE_DATA \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_RPC_WRAPPERS \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_INCLASS \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_SPARSE_DATA \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_INCLASS_NO_PURE_DECLS \
	Module5Proj_Source_Module5Proj_Module5ProjProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MODULE5PROJ_API UClass* StaticClass<class AModule5ProjProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Module5Proj_Source_Module5Proj_Module5ProjProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
