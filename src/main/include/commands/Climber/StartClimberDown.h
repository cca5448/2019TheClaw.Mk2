#pragma once

#include "frc/commands/Command.h"

class StartClimberRev: public frc::Command
{
	public:
		StartClimberRev();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};
