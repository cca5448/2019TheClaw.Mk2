#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>
#include <frc/drive/MecanumDrive.h>


class Drivetrain : public frc::Subsystem
{
	private:
		WPI_VictorSPX* lf;
		WPI_VictorSPX* rf;
		WPI_VictorSPX* lr;
		WPI_VictorSPX* rr;
		frc::MecanumDrive* robotDrive;
		AHRS* gyro;

	public:
		Drivetrain();
		void InitDefaultCommand() override;
		void DriveMecanum(double throttle, double strafe, double turn, bool useGyro = 0);
		double GetGyroAngle();
};