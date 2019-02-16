#include "commands/Lift/MoveLiftJoint4ToPosition.h"
#include "Robot.h"

MoveLiftJoint4ToPosition::MoveLiftJoint4ToPosition(double pos){
	Requires(Robot::liftjoint4.get());
	m_TARGET_POS = pos;
}

void MoveLiftJoint4ToPosition::Initialize(){
    printf("Lift: Move Joint 4 to %.2f\n",m_TARGET_POS);
	Robot::liftjoint4->Enable();
	Robot::liftjoint4->SetSetpoint(m_TARGET_POS);
}

void MoveLiftJoint4ToPosition::Execute(){
}

bool MoveLiftJoint4ToPosition::IsFinished(){
	return Robot::liftjoint4->OnTarget();
	//return true;
}

void MoveLiftJoint4ToPosition::End(){
}

void MoveLiftJoint4ToPosition::Interrupted(){
	End();
}

