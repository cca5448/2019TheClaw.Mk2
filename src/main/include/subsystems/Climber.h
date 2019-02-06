#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class Climber : public frc::Subsystem
{
	private:
		frc::VictorSP * climb_motor_left;
		frc::VictorSP * climb_motor_right;
		frc::VictorSP * climb_motor_drive;
		frc::Ultrasonic * climb_distance_sensor;
		frc::DigitalInput * climb_limit_left_extend;
		frc::DigitalInput * climb_limit_left_retract;
		frc::DigitalInput * climb_limit_right_extend;
		frc::DigitalInput * climb_limit_right_retract;
		frc::Counter * counter_clle;
		frc::Counter * counter_cllr;
		frc::Counter * counter_clre;
		frc::Counter * counter_clrr;

	public:
		Climber();
		void InitDefaultCommand() override;
		void ClimberExtendLeft();
		void ClimberRetractLeft();
		void ClimberExtendRight();
		void ClimberRetractRight();
		void ClimberRetractBoth();
		void StopClimber();
		double GetInchesToPlatform();
		bool IsClimberRunning();
		bool IsClimberExtended();
		bool IsClimberRetracted();
		void InitCounter(frc::Counter &ctr);
		bool IsCounterSet(frc::Counter &ctr);
};
