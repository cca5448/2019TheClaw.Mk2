#pragma once

#include "frc/commands/Command.h"

class StartClimberFwd: public frc::Command
{
	public:
		StartClimberFwd();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};
