# GAS Companion Example Project

> Requires GAS Companion installed in engine

This is a c++ project, you'll need [Visual Studio 2019 and compilation toolchain](https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/DevelopmentSetup/VisualStudioSetup/) in order to compile the project.

## Engine compatibility

Last saved on 5.3 - Should be compatible with Unreal 5.3 versions and higher (you can tweak .uproject `EngineAssociation` field to match your launcher installed engine)

Some .uasset were saved in 5.3, trying to load the project in an unreal version lower than 5.3 may fail to load assets that were saved in 5.3 (will not appear in content browser). Trying to open the project in Unreal Editor 5.3 or higher is recommended.

## Installation

### via git

1. Clone the repository using `git clone`
2. Open `GASCompanionDemo.uproject` (compilation needed)

### Download Project

1. Open the [releases page](https://github.com/GASCompanion/GASCompanionDemo/releases)
2. Download latest `GASCompanionDemo_..._Win64.zip` file for your platform and engine version (Includes pre-built binaries)
3. Open `GASCompanionDemo.uproject`

## Maps

Example maps can be found in `/Game/Demo/Maps`

- Playground: Very basic map with a Third Person Character Blueprint.
- Playground Player State: Same map as Playground but using Player State to hold the ASC.
- Combo: Third Person Character with a basic three part combo. Demonstrates:
  - Combo ability and usage of Gameplay Effect Containers and custom Target Types to handle hit detection (using a sphere trace in front of character)
  - Health Bar used as a Widget Component
- Custom HUD: Map showcasing the use of an additional Attribute Set generated via the wizard and a custom HUD Widget showing how to:
  - Handle attribute changes within a UMG widget
  - React to gameplay effects changes (showing an icon whenever the Burnt effect is applied and active)
  - Be notified of cooldown changes for 3 abilities.
  - Basic example of a simple Gameplay Cue to handle the visuals of the Burnt gameplay effect.

## Documentation

- [GAS Companion Documentation](https://gascompanion.github.io/)
