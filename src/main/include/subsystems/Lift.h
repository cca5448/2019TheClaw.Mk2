#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class Lift : public frc::Subsystem
{
	private:

    public:
		Lift();
		void InitDefaultCommand() override;
		void SetLiftJointToPosition(short joint, double pos);
		double GetLiftJointPosition(short joint);
		double GetLiftJointRawPotValue(short joint);
		bool IsLiftJointAtPosition(short joint, double pos);
};