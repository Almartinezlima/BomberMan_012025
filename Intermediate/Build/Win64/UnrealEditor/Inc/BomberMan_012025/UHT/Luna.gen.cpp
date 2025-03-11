// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/Luna.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLuna() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ALuna();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ALuna_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ALuna
void ALuna::StaticRegisterNativesALuna()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALuna);
UClass* Z_Construct_UClass_ALuna_NoRegister()
{
	return ALuna::StaticClass();
}
struct Z_Construct_UClass_ALuna_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Luna.h" },
		{ "ModuleRelativePath", "Public/Luna.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALuna>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ALuna_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALuna_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALuna_Statics::ClassParams = {
	&ALuna::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALuna_Statics::Class_MetaDataParams), Z_Construct_UClass_ALuna_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALuna()
{
	if (!Z_Registration_Info_UClass_ALuna.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALuna.OuterSingleton, Z_Construct_UClass_ALuna_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALuna.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ALuna>()
{
	return ALuna::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALuna);
ALuna::~ALuna() {}
// End Class ALuna

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_BomberMan_012025_Source_BomberMan_012025_Public_Luna_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALuna, ALuna::StaticClass, TEXT("ALuna"), &Z_Registration_Info_UClass_ALuna, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALuna), 3263545974U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_BomberMan_012025_Source_BomberMan_012025_Public_Luna_h_2357433583(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_BomberMan_012025_Source_BomberMan_012025_Public_Luna_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_BomberMan_012025_Source_BomberMan_012025_Public_Luna_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
