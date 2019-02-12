#include "commands/Lift/MoveLiftJoint1ToPosition.h"
#include "Robot.h"

MoveLiftJoint1ToPosition::MoveLiftJoint1ToPosition(double pos)
{
	Requires(Robot::liftjoint1.get());
	m_TARGET_POS = pos;
}

void MoveLiftJoint1ToPosition::Initialize()
{
    Robot::liftjoint1->SetLiftJointSetpoint(m_TARGET_POS);
}

void MoveLiftJoint1ToPosition::Execute()
{
}

bool MoveLiftJoint1ToPosition::IsFinished()
{
	return false;
}

void MoveLiftJoint1ToPosition::End()
{
}

void MoveLiftJoint1ToPosition::Interrupted()
{
	End();
}

