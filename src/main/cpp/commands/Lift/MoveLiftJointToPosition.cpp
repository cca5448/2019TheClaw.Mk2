#include "commands/Lift/MoveLiftJointToPosition.h"
#include "Robot.h"

MoveLiftJointToPosition::MoveLiftJointToPosition(short joint, double pos)
{
	Requires(Robot::lift.get());
    m_TARGET_JOINT = joint;
	m_TARGET_POS = pos;
}

void MoveLiftJointToPosition::Initialize()
{
    Robot::lift->SetLiftJointToPosition(m_TARGET_JOINT,m_TARGET_POS);
}

void MoveLiftJointToPosition::Execute()
{
}

bool MoveLiftJointToPosition::IsFinished()
{
	return false; //this needs to read the pot and end when target reached
    //return (Robot::Lift->GetLiftJointPosition(m_TARGET_JOINT) >= m_TARGET_POS);
    //return (Robot::Lift->IsLiftJointAtPosition(m_TARGET_JOINT, m_TARGET_POS));
}

void MoveLiftJointToPosition::End()
{
}

void MoveLiftJointToPosition::Interrupted()
{
	End();
}

