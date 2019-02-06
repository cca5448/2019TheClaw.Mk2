#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class Claw : public frc::Subsystem
{
	private:
        frc::Servo * claw_motor;
        frc::AnalogPotentiometer * claw_pot;

	public:
		Claw();
		void InitDefaultCommand() override;
		void ClawFullClose();
		void ClawCaptureHatch();
		void ClawFullOpen();
		void ClawCaptureCargo();
		void ClawEmergencyHatchRelease();
		double GetClawPotValue();
};
