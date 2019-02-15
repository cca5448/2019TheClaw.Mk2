#include "subsystems/LiftJoint3.h"
#include "RobotMap.h"

LiftJoint3::LiftJoint3() : frc::PIDSubsystem("LiftJoint3", LIFT_JOINT_KP, LIFT_JOINT_KI, LIFT_JOINT_KD){
	SetAbsoluteTolerance(LIFT_JOINT_TOLERANCE);
	GetPIDController()->SetContinuous(false);
	LiftJoint3_Pot = std::make_shared<frc::AnalogPotentiometer>(LIFT_POT_3,3600,LIFT_POT_OFFSET_3);
	LiftJoint3_Motor = std::make_shared<WPI_TalonSRX>(LIFT_MOT_3);

	SetSetpoint(LIFT_POS_STOW_3);
	Enable();
}

void LiftJoint3::InitDefaultCommand(){
}

void LiftJoint3::UsePIDOutput(double output) {
	LiftJoint3_Motor->PIDWrite(output);
}

double LiftJoint3::ReturnPIDInput() {
	return LiftJoint3_Pot->PIDGet();
}
