#pragma once

#include "frc/commands/Command.h"

class StopClimber: public frc::Command
{
	public:
		StopClimber();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};