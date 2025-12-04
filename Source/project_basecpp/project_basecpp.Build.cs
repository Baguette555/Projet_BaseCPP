// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class project_basecpp : ModuleRules
{
	public project_basecpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"project_basecpp",
			"project_basecpp/Variant_Platforming",
			"project_basecpp/Variant_Platforming/Animation",
			"project_basecpp/Variant_Combat",
			"project_basecpp/Variant_Combat/AI",
			"project_basecpp/Variant_Combat/Animation",
			"project_basecpp/Variant_Combat/Gameplay",
			"project_basecpp/Variant_Combat/Interfaces",
			"project_basecpp/Variant_Combat/UI",
			"project_basecpp/Variant_SideScrolling",
			"project_basecpp/Variant_SideScrolling/AI",
			"project_basecpp/Variant_SideScrolling/Gameplay",
			"project_basecpp/Variant_SideScrolling/Interfaces",
			"project_basecpp/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
