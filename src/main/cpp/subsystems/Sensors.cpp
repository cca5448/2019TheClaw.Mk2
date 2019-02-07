#include "subsystems/Sensors.h"
#include "RobotMap.h"

Sensors::Sensors() : frc::Subsystem("Sensors"){
	//climb_motor_left = new frc::VictorSP(CLIMB_MOT_LEFT);
}

void Sensors::InitDefaultCommand(){
	//SetDefaultCommand(new Climb());
}
