#include "Commands/Climber/StartClimberDown.h"
#include "Robot.h"

StartClimberRev::StartClimberRev()
{
	//Requires(Robot::climber.get());
}

void StartClimberRev::Initialize()
{
//	SmartDashboard::PutString("Feeder Running","initrev");
}

void StartClimberRev::Execute()
{
	StartClimberRev();
	//SmartDashboard::PutString("Climber Running","rev");
}

bool StartClimberRev::IsFinished()
{
	//example on how to run until counter is set
	// https://wpilib.screenstepslive.com/s/3120/m/7912/l/599687-using-limit-switches-to-control-behavior
	return true;
}

void StartClimberRev::End()
{
}

void StartClimberRev::Interrupted()
{
	End();
}
