#include "commands/Claw/ClawFullOpen.h"
#include "Robot.h"

ClawFullOpen::ClawFullOpen()
{
	Requires(Robot::claw.get());
}

void ClawFullOpen::Initialize()
{
    Robot::claw->MoveClawToFullOpen();
}

void ClawFullOpen::Execute()
{
}

bool ClawFullOpen::IsFinished()
{
	return false; //this needs to read the pot and end when target reached
}

void ClawFullOpen::End()
{
}

void ClawFullOpen::Interrupted()
{
	End();
}

