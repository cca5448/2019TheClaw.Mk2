#pragma once

#include "frc/commands/Command.h"

class MoveLiftJoint1ToPosition: public frc::Command
{
    private:
        double m_TARGET_POS;
	public:
		MoveLiftJoint1ToPosition(double pos);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};