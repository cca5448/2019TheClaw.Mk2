#include "subsystems/LiftJoint2.h"
#include "RobotMap.h"

LiftJoint2::LiftJoint2() : frc::PIDSubsystem("LiftJoint2", LIFT_JOINT_KP, LIFT_JOINT_KI, LIFT_JOINT_KD){
	SetAbsoluteTolerance(LIFT_JOINT_TOLERANCE);
	GetPIDController()->SetContinuous(false);
	LiftJoint2_Pot = std::make_shared<frc::AnalogPotentiometer>(LIFT_POT_2);
	LiftJoint2_Motor = std::make_shared<WPI_TalonSRX>(LIFT_MOT_2);

	SetSetpoint(LIFT_POS_STOW_2);
	Enable();
}

void LiftJoint2::InitDefaultCommand(){
}

void LiftJoint2::UsePIDOutput(double output) {
	LiftJoint2_Motor->PIDWrite(output);
}

double LiftJoint2::ReturnPIDInput() {
	return LiftJoint2_Pot->PIDGet();
}

int LiftJoint2::GetScaledPIDInput() {
	return LiftJoint2_Pot->PIDGet() * 100;
}
