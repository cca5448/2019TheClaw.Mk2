#pragma once

#include "frc/commands/Command.h"

class MoveLiftJoint2ToPosition: public frc::Command
{
    private:
        double m_TARGET_POS;
	public:
		MoveLiftJoint2ToPosition(double pos);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};