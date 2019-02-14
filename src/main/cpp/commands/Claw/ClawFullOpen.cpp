#include "commands/Claw/ClawFullOpen.h"
#include "Robot.h"
#include "RobotMap.h"

ClawFullOpen::ClawFullOpen(){
	Requires(Robot::claw.get());
}

void ClawFullOpen::Initialize(){
    Robot::claw->MoveClawToFullOpen();
}

void ClawFullOpen::Execute(){
}

bool ClawFullOpen::IsFinished(){
	static double target = CLAW_POT_VAL_FO;
	printf("Target: %.2f  Current: %.2f\n", target, Robot::claw->GetClawPotValue());
	return (Robot::claw->GetClawPotValue() >= (target - CLAW_POT_VAL_TOLERANCE) and Robot::claw->GetClawPotValue() <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawFullOpen::End(){
	Robot::claw->StopClaw();
}

void ClawFullOpen::Interrupted(){
	End();
}

