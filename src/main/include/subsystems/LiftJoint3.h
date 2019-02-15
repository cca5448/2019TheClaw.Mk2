#pragma once

#include <frc/WPILib.h>
#include <frc/commands/PIDSubsystem.h>
#include <ctre/Phoenix.h>

class LiftJoint3 : public frc::PIDSubsystem
{
    public:
		std::shared_ptr<WPI_TalonSRX> LiftJoint3_Motor;
		std::shared_ptr<frc::AnalogPotentiometer> LiftJoint3_Pot;

		LiftJoint3();
		void InitDefaultCommand() override;
		double ReturnPIDInput();
		int GetScaledPIDInput();
		void UsePIDOutput(double output);
};
