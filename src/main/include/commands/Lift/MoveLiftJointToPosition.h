#pragma once

#include "frc/commands/Command.h"

class MoveLiftJointToPosition: public frc::Command
{
    private:
        short m_TARGET_JOINT;
        double m_TARGET_POS;
	public:
		MoveLiftJointToPosition(short joint, double pos);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};