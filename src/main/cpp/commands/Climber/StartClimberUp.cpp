#include "commands/Climber/StartClimberUp.h"
#include "Robot.h"

StartClimberFwd::StartClimberFwd()
{
	//Requires(Robot::climber.get());
}

void StartClimberFwd::Initialize()
{
//	SmartDashboard::PutString("Feeder Running","initfwd");
}

void StartClimberFwd::Execute()
{
	StartClimberFwd();
	//printf("StartClimberFwd");
	//SmartDashboard::PutString("Climber Running","fwd");
}

bool StartClimberFwd::IsFinished()
{
	return true;
}

void StartClimberFwd::End()
{
}

void StartClimberFwd::Interrupted()
{
	End();
}
