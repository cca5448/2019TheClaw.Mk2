#pragma once

#include <frc/WPILib.h>
#include <frc/commands/PIDSubsystem.h>
#include <ctre/Phoenix.h>

class LiftJoint1 : public frc::PIDSubsystem
{
    public:
		std::shared_ptr<WPI_TalonSRX> LiftJoint1_Motor;
		std::shared_ptr<frc::AnalogPotentiometer> LiftJoint1_Pot;

		LiftJoint1();
		void InitDefaultCommand() override;
		double ReturnPIDInput();
		void UsePIDOutput(double output);
};
