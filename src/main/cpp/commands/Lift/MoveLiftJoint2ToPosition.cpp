#include "commands/Lift/MoveLiftJoint2ToPosition.h"
#include "Robot.h"

MoveLiftJoint2ToPosition::MoveLiftJoint2ToPosition(double pos){
	Requires(Robot::liftjoint2.get());
	m_TARGET_POS = pos;
}

void MoveLiftJoint2ToPosition::Initialize(){
    printf("Lift: Move Joint 2 to %.2f\n",m_TARGET_POS);
	Robot::liftjoint2->Enable();
	Robot::liftjoint2->SetSetpoint(m_TARGET_POS);
}

void MoveLiftJoint2ToPosition::Execute(){
}

bool MoveLiftJoint2ToPosition::IsFinished(){
	return Robot::liftjoint2->OnTarget();
	//return true;
}

void MoveLiftJoint2ToPosition::End(){
}

void MoveLiftJoint2ToPosition::Interrupted(){
	End();
}

