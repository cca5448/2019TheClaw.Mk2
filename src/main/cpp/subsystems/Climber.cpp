#include "subsystems/Climber.h"
#include "RobotMap.h"

Climber::Climber() : frc::Subsystem("Climber"){
	climb_motor_left = new frc::VictorSP(CLIMB_MOT_LEFT);
	climb_motor_right = new frc::VictorSP(CLIMB_MOT_RIGHT);
	climb_motor_drive = new frc::VictorSP(CLIMB_MOT_DRIVE);
	climb_distance_sensor = new frc::Ultrasonic(CLIMB_DISTANCE_SENSOR,CLIMB_DISTANCE_SENSOR);
	climb_limit_left_extend = new frc::DigitalInput(CLIMB_LIMIT_LEFT_EXTEND);
	climb_limit_left_retract = new frc::DigitalInput(CLIMB_LIMIT_LEFT_RETRACT);
	climb_limit_right_extend = new frc::DigitalInput(CLIMB_LIMIT_RIGHT_EXTEND);
	climb_limit_right_retract = new frc::DigitalInput(CLIMB_LIMIT_RIGHT_RETRACT);
	counter_clle = new frc::Counter(climb_limit_left_extend);
	counter_cllr = new frc::Counter(climb_limit_left_retract);
	counter_clre = new frc::Counter(climb_limit_right_extend);
	counter_clrr = new frc::Counter(climb_limit_right_retract);
}

void Climber::InitDefaultCommand(){
	//SetDefaultCommand(new Climb());
}

void Climber::ClimberExtendLeft(){
	climb_motor_left->Set(CLIMB_MOT_SPEED_CLIMB);
}

void Climber::ClimberRetractLeft(){
	climb_motor_left->Set(-CLIMB_MOT_SPEED_CLIMB);
}

void Climber::ClimberExtendRight(){
	climb_motor_right->Set(CLIMB_MOT_SPEED_CLIMB);
}

void Climber::ClimberRetractRight(){
	climb_motor_right->Set(-CLIMB_MOT_SPEED_CLIMB);
}

void Climber::ClimberRetractBoth(){
	ClimberRetractLeft();
	ClimberRetractRight();
}

void Climber::StopClimber(){
	climb_motor_left->Set(0.0);
	climb_motor_right->Set(0.0);
}

double Climber::GetInchesToPlatform(){
	//todo: use sensor to get distance
	return 0.0;
}

void Climber::InitCounter(frc::Counter &ctr){
	ctr.Reset();
}

bool Climber::IsCounterSet(frc::Counter &ctr){
	return ctr.Get() > 0;
}
