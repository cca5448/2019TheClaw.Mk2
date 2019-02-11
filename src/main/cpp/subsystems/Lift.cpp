#include "subsystems/Lift.h"
#include "RobotMap.h"

Lift::Lift() : frc::Subsystem("Lift"){
	//climb_motor_left = new frc::VictorSP(CLIMB_MOT_LEFT);
}

void Lift::InitDefaultCommand(){
	//SetDefaultCommand(new Climb());
}

void Lift::SetLiftJointToPosition(short joint, double pos){
	//move joint to get to position
}

double Lift::GetLiftJointPosition(short joint){
	//get the raw pot value and apply offset, inversion, etc.
}

double Lift::GetLiftJointRawPotValue(short joint){
	//get the raw pot value
}

bool Lift::IsLiftJointAtPosition(short joint, double pos){
	//decide if the joint is within margin of error of position
}
