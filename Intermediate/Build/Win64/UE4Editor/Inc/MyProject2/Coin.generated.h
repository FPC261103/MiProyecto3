// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
struct FKey;
#ifdef MYPROJECT2_Coin_generated_h
#error "Coin.generated.h already included, missing '#pragma once' in Coin.h"
#endif
#define MYPROJECT2_Coin_generated_h

#define MyProject2_Source_MyProject2_Coin_h_13_SPARSE_DATA
#define MyProject2_Source_MyProject2_Coin_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCoinClicked);


#define MyProject2_Source_MyProject2_Coin_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCoinClicked);


#define MyProject2_Source_MyProject2_Coin_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACoin(); \
	friend struct Z_Construct_UClass_ACoin_Statics; \
public: \
	DECLARE_CLASS(ACoin, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject2"), NO_API) \
	DECLARE_SERIALIZER(ACoin)


#define MyProject2_Source_MyProject2_Coin_h_13_INCLASS \
private: \
	static void StaticRegisterNativesACoin(); \
	friend struct Z_Construct_UClass_ACoin_Statics; \
public: \
	DECLARE_CLASS(ACoin, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject2"), NO_API) \
	DECLARE_SERIALIZER(ACoin)


#define MyProject2_Source_MyProject2_Coin_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACoin(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACoin) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACoin); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACoin); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACoin(ACoin&&); \
	NO_API ACoin(const ACoin&); \
public:


#define MyProject2_Source_MyProject2_Coin_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACoin(ACoin&&); \
	NO_API ACoin(const ACoin&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACoin); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACoin); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACoin)


#define MyProject2_Source_MyProject2_Coin_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MatCara() { return STRUCT_OFFSET(ACoin, MatCara); } \
	FORCEINLINE static uint32 __PPO__MatSello() { return STRUCT_OFFSET(ACoin, MatSello); }


#define MyProject2_Source_MyProject2_Coin_h_10_PROLOG
#define MyProject2_Source_MyProject2_Coin_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject2_Source_MyProject2_Coin_h_13_PRIVATE_PROPERTY_OFFSET \
	MyProject2_Source_MyProject2_Coin_h_13_SPARSE_DATA \
	MyProject2_Source_MyProject2_Coin_h_13_RPC_WRAPPERS \
	MyProject2_Source_MyProject2_Coin_h_13_INCLASS \
	MyProject2_Source_MyProject2_Coin_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject2_Source_MyProject2_Coin_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject2_Source_MyProject2_Coin_h_13_PRIVATE_PROPERTY_OFFSET \
	MyProject2_Source_MyProject2_Coin_h_13_SPARSE_DATA \
	MyProject2_Source_MyProject2_Coin_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject2_Source_MyProject2_Coin_h_13_INCLASS_NO_PURE_DECLS \
	MyProject2_Source_MyProject2_Coin_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MYPROJECT2_API UClass* StaticClass<class ACoin>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject2_Source_MyProject2_Coin_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
