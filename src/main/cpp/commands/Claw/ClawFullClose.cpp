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
	static double current = Robot::claw->GetClawPotValue();
	return (current >= (target - CLAW_POT_VAL_TOLERANCE) and current <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawFullClose::End(){
	Robot::claw->StopClaw();
}

void ClawFullClose::Interrupted(){
	End();
}

