#include "commands/Claw/ClawStop.h"
#include "Robot.h"
#include "RobotMap.h"

ClawStop::ClawStop(){
	Requires(Robot::claw.get());
}

void ClawStop::Initialize(){
    Robot::claw->StopClaw();
}

void ClawStop::Execute(){
}

bool ClawStop::IsFinished(){
	return true;
}

void ClawStop::End(){
	Robot::claw->StopClaw();
}

void ClawStop::Interrupted(){
	End();
}

