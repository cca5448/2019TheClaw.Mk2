#pragma once

#include "frc/commands/Command.h"
#include "WPILib.h"

class StartCameraServer: public frc::Command
{
	public:
		StartCameraServer();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};