#include "subsystems/LiftJoint1.h"
#include "RobotMap.h"

LiftJoint1::LiftJoint1() : frc::PIDSubsystem("LiftJoint1", LIFT_JOINT_KP, LIFT_JOINT_KI, LIFT_JOINT_KD){
	GetPIDController()->SetContinuous(false);
	LiftJoint1_Pot = std::make_shared<frc::AnalogPotentiometer>(LIFT_POT_1);
	LiftJoint1_Motor = std::make_shared<WPI_TalonSRX>(LIFT_MOT_1);

	SetSetpoint(LIFT_POS_STOW_1);
	Enable();
}

void LiftJoint1::InitDefaultCommand(){
}

void LiftJoint1::UsePIDOutput(double output) {
	LiftJoint1_Motor->PIDWrite(output);
}

double LiftJoint1::ReturnPIDInput() {
	return LiftJoint1_Pot->PIDGet();
}

void LiftJoint1::SetLiftJointSetpoint(double pos) {
	SetSetpoint(pos);
}
