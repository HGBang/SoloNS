// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectNS : ModuleRules
{
	public ProjectNS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core",
			"CoreUObject",
			"Engine",

			// Input
			"InputCore",
			"EnhancedInput",

			// UI
			"UMG",
            "Slate",
            "SlateCore",

			// NetWork
			"Networking",
			"Sockets",

			// ParticleSystem
			"Niagara",

			// Navigation
			"NavigationSystem",

			// AI
			"AIModule"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
