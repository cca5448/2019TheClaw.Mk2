#include "commands/Wrist/MoveWristUp.h"
#include "Robot.h"
#include "RobotMap.h"

MoveWristUp::MoveWristUp(){
	Requires(Robot::wrist.get());
	m_TARGET_POS = WRIST_POS_UP;
}

void MoveWristUp::Initialize(){
    printf("Wrist: Move Wrist to %.2f\n",m_TARGET_POS);
	Robot::wrist->Enable();
	Robot::wrist->SetSetpoint(m_TARGET_POS);
}

void MoveWristUp::Execute(){
}

bool MoveWristUp::IsFinished(){
	return Robot::wrist->OnTarget();
	//return true;
}

void MoveWristUp::End(){
}

void MoveWristUp::Interrupted(){
	End();
}

