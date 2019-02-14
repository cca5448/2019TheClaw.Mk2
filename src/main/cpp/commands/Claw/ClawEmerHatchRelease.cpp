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
	printf("Target: %.2f  Current: %.2f\n", target, Robot::claw->GetClawPotValue());
	return (Robot::claw->GetClawPotValue() >= (target - CLAW_POT_VAL_TOLERANCE) and Robot::claw->GetClawPotValue() <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawEmerHatchRelease::End(){
	Robot::claw->StopClaw();
}

void ClawEmerHatchRelease::Interrupted(){
	End();
}

