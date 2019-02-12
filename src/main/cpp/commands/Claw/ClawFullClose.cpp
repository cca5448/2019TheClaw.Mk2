#include "commands/Claw/ClawFullClose.h"
#include "Robot.h"

ClawFullClose::ClawFullClose()
{
	Requires(Robot::claw.get());
}

void ClawFullClose::Initialize()
{
    Robot::claw->MoveClawToFullClose();
}

void ClawFullClose::Execute()
{
}

bool ClawFullClose::IsFinished()
{
	return false; //this needs to read the pot and end when target reached
}

void ClawFullClose::End()
{
}

void ClawFullClose::Interrupted()
{
	End();
}

