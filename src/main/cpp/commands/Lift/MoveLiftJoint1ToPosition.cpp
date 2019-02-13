#include "commands/Lift/MoveLiftJoint1ToPosition.h"
#include "Robot.h"

MoveLiftJoint1ToPosition::MoveLiftJoint1ToPosition(double pos)
{
	Requires(Robot::liftjoint1.get());
	m_TARGET_POS = pos;
}

void MoveLiftJoint1ToPosition::Initialize()
{
	Robot::liftjoint1->Enable();
	Robot::liftjoint1->SetSetpoint(m_TARGET_POS);
}

void MoveLiftJoint1ToPosition::Execute()
{
}

bool MoveLiftJoint1ToPosition::IsFinished()
{
	return Robot::liftjoint1->OnTarget();
	//return false;
}

void MoveLiftJoint1ToPosition::End()
{
}

void MoveLiftJoint1ToPosition::Interrupted()
{
	End();
}

