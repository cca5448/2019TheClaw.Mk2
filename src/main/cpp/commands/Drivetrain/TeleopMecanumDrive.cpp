#include "commands/Drivetrain/TeleopMecanumDrive.h"
#include "Robot.h"

TeleopMecanumDrive::TeleopMecanumDrive()
{
	Requires(Robot::drivetrain.get()); //requires the drivetrain subsystem
}

void TeleopMecanumDrive::Initialize()
{
}

void TeleopMecanumDrive::Execute()
{
	printf("m.");
	Robot::drivetrain->DriveMecanum(Robot::oi->GetThrottleAxis(), Robot::oi->GetStrafeAxis(), Robot::oi->GetTurnAxis(),true);
}

bool TeleopMecanumDrive::IsFinished()
{
	return false;
}

void TeleopMecanumDrive::End()
{
	Robot::drivetrain->DriveMecanum(0,0,0,false); //sets the speed to 0 so doesnt drive or continue driving
}

void TeleopMecanumDrive::Interrupted()
{
	End();
}

