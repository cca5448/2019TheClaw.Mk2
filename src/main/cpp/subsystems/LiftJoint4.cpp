#include "subsystems/LiftJoint4.h"
#include "RobotMap.h"

LiftJoint4::LiftJoint4() : frc::PIDSubsystem("LiftJoint4", LIFT_JOINT_KP, LIFT_JOINT_KI, LIFT_JOINT_KD){
	SetAbsoluteTolerance(LIFT_JOINT_TOLERANCE);
	GetPIDController()->SetContinuous(false);
	LiftJoint4_Pot = std::make_shared<frc::AnalogPotentiometer>(LIFT_POT_4);
	LiftJoint4_Motor = std::make_shared<WPI_TalonSRX>(LIFT_MOT_4);

	SetSetpoint(LIFT_POS_STOW_4);
	Enable();
}

void LiftJoint4::InitDefaultCommand(){
}

void LiftJoint4::UsePIDOutput(double output) {
	LiftJoint4_Motor->PIDWrite(output);
}

double LiftJoint4::ReturnPIDInput() {
	return LiftJoint4_Pot->PIDGet();
}
