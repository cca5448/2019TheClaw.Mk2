#include "subsystems/Claw.h"
#include "RobotMap.h"
#include <frc/smartdashboard/SmartDashboard.h>

Claw::Claw() : frc::Subsystem("Claw"){
	claw_motor.reset(new frc::Servo(CLAW_MOT_1));
    claw_pot.reset(new frc::AnalogPotentiometer(CLAW_POT_1,1.0,CLAW_POT_OFFSET_1));
}

void Claw::InitDefaultCommand(){
    StopClaw();
}

void Claw::StopClaw(){
    //Stop claw
    frc::SmartDashboard::PutString("Last Action","");
    claw_motor->Set(.5);
}

double Claw::GetClawMotorSpeed(){
    claw_motor->Get();
}

void Claw::MoveClawToFullClose(){
    //Close claw until claw pot value is less than recorded close value
    frc::SmartDashboard::PutString("Last Action","Move claw to Full Close");
    //do {
        static double pos = CLAW_POT_VAL_FC;
        if (claw_pot->Get() < pos) {
            claw_motor->Set((0.5 - CLAW_MOT_SPEED));
        } else {
            claw_motor->Set((0.5 + CLAW_MOT_SPEED));
        }
    
    //} while (claw_pot->Get() <= (CLAW_POT_VAL_FC - CLAW_POT_VAL_TOLERANCE) or claw_pot->Get() >= (CLAW_POT_VAL_FC + CLAW_POT_VAL_TOLERANCE));
    //claw_motor->Set(.5);
}

void Claw::MoveClawToCaptureHatch(){
    //Open the claw until claw pot value is at or more than recorded capture value
    frc::SmartDashboard::PutString("Last Action","Move claw to Capture Hatch");
        static double pos = CLAW_POT_VAL_CH;
        if (claw_pot->Get() < pos) {
            claw_motor->Set((0.5 - CLAW_MOT_SPEED));
        } else {
            claw_motor->Set((0.5 + CLAW_MOT_SPEED));
        }
}

void Claw::MoveClawToFullOpen(){
    //Open the claw until claw pot value is at the max value
    frc::SmartDashboard::PutString("Last Action","Move claw to Full Open");
        static double pos = CLAW_POT_VAL_FO;
        if (claw_pot->Get() < pos) {
            claw_motor->Set((0.5 - CLAW_MOT_SPEED));
        } else {
            claw_motor->Set((0.5 + CLAW_MOT_SPEED));
        }
}

void Claw::MoveClawToCaptureCargo(){
    //Close the claw until claw pot value is at or below the recorded capture value
    frc::SmartDashboard::PutString("Last Action","Move claw to Capture Cargo");
        static double pos = CLAW_POT_VAL_CC;
        if (claw_pot->Get() < pos) {
            claw_motor->Set((0.5 - CLAW_MOT_SPEED));
        } else {
            claw_motor->Set((0.5 + CLAW_MOT_SPEED));
        }
}

void Claw::MoveClawToEmerHatchRelease(){
    //Close the claw until claw pot value is at or less than recorded min value
    frc::SmartDashboard::PutString("Last Action","Move claw to Emer Hatch Release");
        static double pos = CLAW_POT_VAL_EHR;
        if (claw_pot->Get() < pos) {
            claw_motor->Set((0.5 - CLAW_MOT_SPEED));
        } else {
            claw_motor->Set((0.5 + CLAW_MOT_SPEED));
        }
}

double Claw::GetClawPotValue(){
    //Read the analogpot value and return the corrected value
    return claw_pot->Get();
}
