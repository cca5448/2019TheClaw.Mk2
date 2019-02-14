#include "commands/Claw/ClawCaptureCargo.h"
#include "Robot.h"
#include "RobotMap.h"

ClawCaptureCargo::ClawCaptureCargo(){
	Requires(Robot::claw.get());
}

void ClawCaptureCargo::Initialize(){
    Robot::claw->MoveClawToCaptureCargo();
}

void ClawCaptureCargo::Execute(){
}

bool ClawCaptureCargo::IsFinished(){
	static double target = CLAW_POT_VAL_CC;
	static double current = Robot::claw->GetClawPotValue();
	return (current >= (target - CLAW_POT_VAL_TOLERANCE) and current <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawCaptureCargo::End(){
	Robot::claw->StopClaw();
}

void ClawCaptureCargo::Interrupted(){
	End();
}

