#include "commands/Claw/ClawEmerHatchRelease.h"
#include "Robot.h"

ClawEmerHatchRelease::ClawEmerHatchRelease()
{
	Requires(Robot::claw.get());
}

void ClawEmerHatchRelease::Initialize()
{
    Robot::claw->MoveClawToEmerHatchRelease();
}

void ClawEmerHatchRelease::Execute()
{
}

bool ClawEmerHatchRelease::IsFinished()
{
	return false; //this needs to read the pot and end when target reached
}

void ClawEmerHatchRelease::End()
{
}

void ClawEmerHatchRelease::Interrupted()
{
	End();
}

