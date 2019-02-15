#pragma once

#include <frc/WPILib.h>
#include <frc/commands/PIDSubsystem.h>
#include <ctre/Phoenix.h>

class LiftJoint2 : public frc::PIDSubsystem
{
    public:
		std::shared_ptr<WPI_TalonSRX> LiftJoint2_Motor;
		std::shared_ptr<frc::AnalogPotentiometer> LiftJoint2_Pot;

		LiftJoint2();
		void InitDefaultCommand() override;
		double ReturnPIDInput();
		int GetScaledPIDInput();
		void UsePIDOutput(double output);
};
