#include "commands/Claw/ClawCaptureCargo.h"
#include "Robot.h"

ClawCaptureCargo::ClawCaptureCargo()
{
	Requires(Robot::claw.get());
}

void ClawCaptureCargo::Initialize()
{
    Robot::claw->MoveClawToCaptureCargo();
}

void ClawCaptureCargo::Execute()
{
}

bool ClawCaptureCargo::IsFinished()
{
	return false; //this needs to read the pot and end when target reached
}

void ClawCaptureCargo::End()
{
}

void ClawCaptureCargo::Interrupted()
{
	End();
}

