#include "subsystems/Claw.h"
#include "RobotMap.h"

Claw::Claw() : frc::Subsystem("Claw"){
	claw_motor = new frc::Servo(CLAW_MOT_1);
    claw_pot = new frc::AnalogPotentiometer(CLAW_POT_1);
}

void Claw::InitDefaultCommand(){
	//SetDefaultCommand(new Climb());
}

void Claw::ClawFullClose(){
    //Close claw until claw pot value is less than recorded close value
}

void Claw::ClawCaptureHatch(){
    //Open the claw until claw pot value is at or more than recorded capture value
}

void Claw::ClawFullOpen(){
    //Open the claw until claw pot value is at the max value
}

void Claw::ClawCaptureCargo(){
    //Close the claw until claw pot value is at or below the recorded capture value
}

void Claw::ClawEmergencyHatchRelease(){
    //Close the claw until claw pot value is at or less than recorded min value
}

double GetClawPotValue(){
    //Read the analogpot value and return the corrected value
    return 0.0;
}


