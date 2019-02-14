#include "commands/Claw/ClawCaptureHatch.h"
#include "Robot.h"
#include "RobotMap.h"

ClawCaptureHatch::ClawCaptureHatch(){
	Requires(Robot::claw.get());
}

void ClawCaptureHatch::Initialize(){
    Robot::claw->MoveClawToCaptureHatch();
}

void ClawCaptureHatch::Execute(){
}

bool ClawCaptureHatch::IsFinished(){
	static double target = CLAW_POT_VAL_CH;
	static double current = Robot::claw->GetClawPotValue();
	return (current >= (target - CLAW_POT_VAL_TOLERANCE) and current <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawCaptureHatch::End(){
	Robot::claw->StopClaw();
}

void ClawCaptureHatch::Interrupted(){
	End();
}

