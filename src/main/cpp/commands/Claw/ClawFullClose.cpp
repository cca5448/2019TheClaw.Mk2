#include "commands/Claw/ClawFullClose.h"
#include "Robot.h"
#include "RobotMap.h"

ClawFullClose::ClawFullClose(){
	Requires(Robot::claw.get());
}

void ClawFullClose::Initialize(){
    Robot::claw->MoveClawToFullClose();
}

void ClawFullClose::Execute(){
}

bool ClawFullClose::IsFinished(){
	static double target = CLAW_POT_VAL_FC;
	printf("Target: %.2f  Current: %.2f\n", target, Robot::claw->GetClawPotValue());
	return (Robot::claw->GetClawPotValue() >= (target - CLAW_POT_VAL_TOLERANCE) and Robot::claw->GetClawPotValue() <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawFullClose::End(){
	Robot::claw->StopClaw();
}

void ClawFullClose::Interrupted(){
	End();
}

