#pragma once

#include <frc/WPILib.h>
#include <frc/commands/PIDSubsystem.h>
#include <ctre/Phoenix.h>

class LiftJoint4 : public frc::PIDSubsystem
{
    public:
		std::shared_ptr<WPI_TalonSRX> LiftJoint4_Motor;
		std::shared_ptr<frc::AnalogPotentiometer> LiftJoint4_Pot;

		LiftJoint4();
		void InitDefaultCommand() override;
		double ReturnPIDInput();
		void UsePIDOutput(double output);
};
