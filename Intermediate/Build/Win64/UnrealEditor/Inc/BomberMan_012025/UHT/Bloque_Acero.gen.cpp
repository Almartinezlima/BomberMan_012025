// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/Bloque_Acero.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloque_Acero() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque_Acero();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque_Acero_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloque_Acero
void ABloque_Acero::StaticRegisterNativesABloque_Acero()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloque_Acero);
UClass* Z_Construct_UClass_ABloque_Acero_NoRegister()
{
	return ABloque_Acero::StaticClass();
}
struct Z_Construct_UClass_ABloque_Acero_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Bloque_Acero.h" },
		{ "ModuleRelativePath", "Public/Bloque_Acero.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MallaBloque_Acero_MetaData[] = {
		{ "Category", "Componentes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Componente de malla est\xc3\xa1tica para representar el bloque de acero\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Bloque_Acero.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Componente de malla est\xc3\xa1tica para representar el bloque de acero" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MallaBloque_Acero;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloque_Acero>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABloque_Acero_Statics::NewProp_MallaBloque_Acero = { "MallaBloque_Acero", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABloque_Acero, MallaBloque_Acero), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MallaBloque_Acero_MetaData), NewProp_MallaBloque_Acero_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABloque_Acero_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloque_Acero_Statics::NewProp_MallaBloque_Acero,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloque_Acero_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABloque_Acero_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloque_Acero_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloque_Acero_Statics::ClassParams = {
	&ABloque_Acero::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABloque_Acero_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABloque_Acero_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloque_Acero_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloque_Acero_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloque_Acero()
{
	if (!Z_Registration_Info_UClass_ABloque_Acero.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloque_Acero.OuterSingleton, Z_Construct_UClass_ABloque_Acero_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloque_Acero.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloque_Acero>()
{
	return ABloque_Acero::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloque_Acero);
ABloque_Acero::~ABloque_Acero() {}
// End Class ABloque_Acero

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_BomberMan_012025_Source_BomberMan_012025_Public_Bloque_Acero_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloque_Acero, ABloque_Acero::StaticClass, TEXT("ABloque_Acero"), &Z_Registration_Info_UClass_ABloque_Acero, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloque_Acero), 1339186380U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_BomberMan_012025_Source_BomberMan_012025_Public_Bloque_Acero_h_2985900612(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_BomberMan_012025_Source_BomberMan_012025_Public_Bloque_Acero_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_BomberMan_012025_Source_BomberMan_012025_Public_Bloque_Acero_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
