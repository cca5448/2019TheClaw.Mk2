#include "RobotMap.h"
#include "subsystems/Lift.h"

//#include "commands/Lift/LiftMover.h" //For reading joystick axis and taking action for lift... 

Lift::Lift() : frc::Subsystem("Lift"){
	liftmotor = std::make_shared<WPI_TalonSRX>(LIFT_MOT);

	//invert right side
	//liftmotor->SetInverted(true);
}

void Lift::InitDefaultCommand(){
	//SetDefaultCommand(new LiftMove());
}

void Lift::SetLiftSpeed(double throttle){
	liftmotor->Set(LIFT_SPEED);
}
