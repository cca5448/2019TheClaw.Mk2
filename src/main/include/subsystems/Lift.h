#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class Lift : public frc::Subsystem
{
	private:

    public:
		Lift();
		void InitDefaultCommand() override;
};