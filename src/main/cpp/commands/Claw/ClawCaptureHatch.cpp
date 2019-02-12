#include "commands/Claw/ClawCaptureHatch.h"
#include "Robot.h"

ClawCaptureHatch::ClawCaptureHatch()
{
	Requires(Robot::claw.get());
}

void ClawCaptureHatch::Initialize()
{
    Robot::claw->MoveClawToCaptureHatch();
}

void ClawCaptureHatch::Execute()
{
}

bool ClawCaptureHatch::IsFinished()
{
	return false; //this needs to read the pot and end when target reached
}

void ClawCaptureHatch::End()
{
}

void ClawCaptureHatch::Interrupted()
{
	End();
}

