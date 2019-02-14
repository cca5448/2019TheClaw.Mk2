#include "commands/Claw/ClawEmerHatchRelease.h"
#include "Robot.h"
#include "RobotMap.h"

ClawEmerHatchRelease::ClawEmerHatchRelease(){
	Requires(Robot::claw.get());
}

void ClawEmerHatchRelease::Initialize(){
    Robot::claw->MoveClawToEmerHatchRelease();
}

void ClawEmerHatchRelease::Execute(){
}

bool ClawEmerHatchRelease::IsFinished(){
	static double target = CLAW_POT_VAL_EHR;
	static double current = Robot::claw->GetClawPotValue();
	return (current >= (target - CLAW_POT_VAL_TOLERANCE) and current <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawEmerHatchRelease::End(){
	Robot::claw->StopClaw();
}

void ClawEmerHatchRelease::Interrupted(){
	End();
}

