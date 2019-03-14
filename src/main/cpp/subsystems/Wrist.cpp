#include "subsystems/Wrist.h"
#include "RobotMap.h"

Wrist::Wrist() : frc::PIDSubsystem("Wrist", WRIST_KP, WRIST_KI, WRIST_KD){
	SetAbsoluteTolerance(WRIST_TOLERANCE);
	GetPIDController()->SetContinuous(false);
	Wrist_Pot = std::make_shared<frc::AnalogPotentiometer>(WRIST_POT);
	Wrist_Motor = std::make_shared<WPI_TalonSRX>(WRIST_MOT);

	SetSetpoint(WRIST_POS_STOW);
	Enable();
}

void Wrist::InitDefaultCommand(){
}

void Wrist::UsePIDOutput(double output) {
	Wrist_Motor->PIDWrite(output);
}

double Wrist::ReturnPIDInput() {
	return Wrist_Pot->PIDGet();
}

int Wrist::GetScaledPIDInput() {
	return Wrist_Pot->PIDGet() * 100;
}
