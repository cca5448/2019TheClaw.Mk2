#include <math.h>
#include "OI.h"
#include "RobotMap.h"
#include <frc/WPILib.h>

//claw
#include "commands/Claw/ClawCaptureCargo.h"
#include "commands/Claw/ClawCaptureHatch.h"
#include "commands/Claw/ClawEmerHatchRelease.h"
#include "commands/Claw/ClawFullClose.h"
#include "commands/Claw/ClawFullOpen.h"
#include "commands/Claw/ClawStop.h"
//lift
#include "commands/Lift/MoveLiftUp.h"
#include "commands/Lift/MoveLiftDown.h"
//wrist
#include "commands/Wrist/MoveWristUp.h"
#include "commands/Wrist/MoveWristDown.h"
#include "commands/Wrist/MoveWristStow.h"

OI::OI()
{
	//constants are from RobotMap.h
	//joysticks
	drive_stick.reset(new frc::Joystick(JOY_DRIVE));
	steer_stick.reset(new frc::Joystick(JOY_STEER));
	lift_stick.reset(new frc::Joystick(JOY_LIFT));
	r_buttons.reset(new frc::Joystick(JOY_RIGHT));
	l_buttons.reset(new frc::Joystick(JOY_LEFT));

	//left button definitions
	//lift
	button_lift_up.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_UP));
	button_lift_down.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_DOWN));
	//wrist
	button_wrist_up.reset(new frc::JoystickButton(l_buttons.get(),BTN_WRIST_UP));
	button_wrist_down.reset(new frc::JoystickButton(l_buttons.get(),BTN_WRIST_DOWN));
	button_wrist_stow.reset(new frc::JoystickButton(l_buttons.get(),BTN_WRIST_STOW));
	//other
	button_cam_aa.reset(new frc::JoystickButton(l_buttons.get(),BTN_CAM_AA));

	//right button definitions
	//claw
	button_claw_cc.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_CC));
	button_claw_ch.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_CH));
	button_claw_fc.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_FC));
	button_claw_fo.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_FO));
	button_claw_ehr.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_EHR));
	button_claw_stop.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_STOP));
	//lighting
	button_light_mu.reset(new frc::JoystickButton(r_buttons.get(),BTN_LIGHT_MODEUP));
	button_light_md.reset(new frc::JoystickButton(r_buttons.get(),BTN_LIGHT_MODEDN));

	//assign commands to buttons
	//lift
	button_lift_up->WhileHeld(new MoveLiftUp());
	button_lift_down->WhileHeld(new MoveLiftDown());
	//wrist
	button_wrist_up->WhenPressed(new MoveWristUp());
	button_wrist_down->WhenPressed(new MoveWristDown());
	button_wrist_stow->WhenPressed(new MoveWristStow());
	//claw
	button_claw_cc->WhenPressed(new ClawCaptureCargo());
	button_claw_ch->WhenPressed(new ClawCaptureHatch());
	button_claw_fc->WhenPressed(new ClawFullClose());
	button_claw_fo->WhenPressed(new ClawFullOpen());
	button_claw_ehr->WhenPressed(new ClawEmerHatchRelease());
	button_claw_stop->WhenPressed(new ClawStop());
	//climber
	//button_end_dn->WhenPressed(new ClimberDown());
	//button_end_dnall->WhenPressed(new ClimberDownAll());
	//button_end_up->WhenPressed(new ClimberUp());
	//other
	//button_cam_aa->WhenPressed(new AimAssist());
	//button_light_md->WhenPressed(new LightModeDown());
	//button_light_mu->WhenPressed(new LightModeUp());
}

double OI::GetThrottleAxis(){
	//method will return the drive throttle axis
	return (RampingDeadZone(drive_stick->GetRawAxis(JOY_DRIVE_AXIS_THROTTLE)));
	//return drive_stick->GetRawAxis(JOY_DRIVE_AXIS_THROTTLE);
}
double OI::GetStrafeAxis(){
	//method will return the strafe axis
	return (RampingDeadZone(drive_stick->GetRawAxis(JOY_DRIVE_AXIS_STRAFE)));
	//return drive_stick->GetRawAxis(JOY_DRIVE_AXIS_STRAFE);
}
double OI::GetTurnAxis(){
	//method will return the turn axis
	return (SteeringDeadZone(steer_stick->GetRawAxis(JOY_STEER_AXIS_TURN)));
	//return steer_stick->GetRawAxis(JOY_STEER_AXIS_TURN);
}
double OI::GetLiftAxis(){
	//method will return the lift adjust axis
	return -(DeadZone(lift_stick->GetRawAxis(JOY_LIFT_AXIS_LIFT)));
	//return lift_stick->GetRawAxis(JOY_LIFT_AXIS_LIFT);
}

double OI::DeadZone(double uval)
{
	//if the uval is in the deadzone defined in robotmap.h, return 0.0 instead
	if (uval >= -JOYSTICK_DEADZONE && uval <= JOYSTICK_DEADZONE) {
		return 0.0;
	}
	return uval;
}

double OI::SteeringDeadZone(double uval)
{
	//This uses math to ramp the throttle starting at the deadzone edge, rather than
	//just starting at the value of the end of the deadzone
	double f_absval, f_offset, f_uval, f_pow;
	double invert = 1.0;
	if (uval < 0) invert = -1.0;
	f_absval = fabs(uval);
	//SmartDashboard::PutNumber("f_absval",f_absval);
	f_offset = 1+JOYSTICK_DEADZONE_TURN;
	//SmartDashboard::PutNumber("f_offset",f_offset);
	f_uval = f_absval;
	f_uval *= f_offset;
	//SmartDashboard::PutNumber("f_uval1",f_uval);
	f_uval -= JOYSTICK_DEADZONE_TURN;
	//SmartDashboard::PutNumber("f_uval2",f_uval);
	f_pow = f_offset * JOYSTICK_RAMP_POWER_TURN;
	//SmartDashboard::PutNumber("f_pow",f_pow);
	f_uval = pow(f_uval,f_pow);
	//SmartDashboard::PutNumber("f_uval3",f_uval);
	f_uval *= invert;
	//SmartDashboard::PutNumber("uval",f_uval);
	return f_uval;

	/*
	 * https://www.desmos.com/calculator
	 * y=(xn-a)^mn //formula for speed ramp
	 * m=1.5 //ramp power of 1.5 (normal 1.1-1.8)
	 * a=0.3 //deadzone of 0.3
	 * n=1+a (multiplier to account for dead zone)
	 */
}

double OI::RampingDeadZone(double uval)
{
	//This uses math to ramp the throttle starting at the deadzone edge, rather than
	//just starting at the value of the end of the deadzone
	double f_absval, f_offset, f_uval, f_pow;
	double invert = 1.0;
	if (uval < 0) invert = -1.0;
	f_absval = fabs(uval);
	//SmartDashboard::PutNumber("f_absval",f_absval);
	f_offset = 1+JOYSTICK_DEADZONE;
	//SmartDashboard::PutNumber("f_offset",f_offset);
	f_uval = f_absval;
	f_uval *= f_offset;
	//SmartDashboard::PutNumber("f_uval1",f_uval);
	f_uval -= JOYSTICK_DEADZONE;
	//SmartDashboard::PutNumber("f_uval2",f_uval);
	f_pow = f_offset * JOYSTICK_RAMP_POWER;
	//SmartDashboard::PutNumber("f_pow",f_pow);
	f_uval = pow(f_uval,f_pow);
	//SmartDashboard::PutNumber("f_uval3",f_uval);
	f_uval *= invert;
	//SmartDashboard::PutNumber("uval",f_uval);
	return f_uval;

	/*
	 * https://www.desmos.com/calculator
	 * y=(xn-a)^mn //formula for speed ramp
	 * m=1.5 //ramp power of 1.5 (normal 1.1-1.8)
	 * a=0.3 //deadzone of 0.3
	 * n=1+a (multiplier to account for dead zone)
	 */
}
