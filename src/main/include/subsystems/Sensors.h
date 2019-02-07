#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class Sensors : public frc::Subsystem
{
	private:

    public:
   		Sensors();
		void InitDefaultCommand() override;
};