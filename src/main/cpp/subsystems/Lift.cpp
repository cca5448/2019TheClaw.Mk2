#include "subsystems/Lift.h"
#include "RobotMap.h"

Lift::Lift() : frc::Subsystem("Lift"){
	//climb_motor_left = new frc::VictorSP(CLIMB_MOT_LEFT);
}

void Lift::InitDefaultCommand(){
	//SetDefaultCommand(new Climb());
}
