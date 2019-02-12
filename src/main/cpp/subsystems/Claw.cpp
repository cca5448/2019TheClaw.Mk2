#include "subsystems/Claw.h"
#include "RobotMap.h"

Claw::Claw() : frc::Subsystem("Claw"){
	claw_motor.reset(new frc::Servo(CLAW_MOT_1));
    claw_pot.reset(new frc::AnalogPotentiometer(CLAW_POT_1,3600,CLAW_POT_OFFSET_1));
}

void Claw::InitDefaultCommand(){
	//SetDefaultCommand(new Climb());
}

void Claw::MoveClawToFullClose(){
    //Close claw until claw pot value is less than recorded close value
}

void Claw::MoveClawToCaptureHatch(){
    //Open the claw until claw pot value is at or more than recorded capture value
}

void Claw::MoveClawToFullOpen(){
    //Open the claw until claw pot value is at the max value
}

void Claw::MoveClawToCaptureCargo(){
    //Close the claw until claw pot value is at or below the recorded capture value
}

void Claw::MoveClawToEmerHatchRelease(){
    //Close the claw until claw pot value is at or less than recorded min value
}

double Claw::GetClawPotValue(){
    //Read the analogpot value and return the corrected value
    return claw_pot->Get();
}


