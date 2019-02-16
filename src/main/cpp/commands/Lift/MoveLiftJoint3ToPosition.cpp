#include "commands/Lift/MoveLiftJoint3ToPosition.h"
#include "Robot.h"

MoveLiftJoint3ToPosition::MoveLiftJoint3ToPosition(double pos){
	Requires(Robot::liftjoint3.get());
	m_TARGET_POS = pos;
}

void MoveLiftJoint3ToPosition::Initialize(){
    printf("Lift: Move Joint 3 to %.2f\n",m_TARGET_POS);
	Robot::liftjoint3->Enable();
	Robot::liftjoint3->SetSetpoint(m_TARGET_POS);
}

void MoveLiftJoint3ToPosition::Execute(){
}

bool MoveLiftJoint3ToPosition::IsFinished(){
	return Robot::liftjoint3->OnTarget();
	//return true;
}

void MoveLiftJoint3ToPosition::End(){
}

void MoveLiftJoint3ToPosition::Interrupted(){
	End();
}

