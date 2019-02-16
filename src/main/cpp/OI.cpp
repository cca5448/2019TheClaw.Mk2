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
//climber
//#include "commands/Climber/StartClimberUp.h"
//#include "commands/Climber/StartClimberDown.h"
//#include "commands/Climber/StopClimber.h"
//lift
#include "commands/Lift/commandgroups/MoveLiftToHCF.h"
#include "commands/Lift/commandgroups/MoveLiftToHHF.h"
#include "commands/Lift/commandgroups/MoveLiftToMCF.h"
#include "commands/Lift/commandgroups/MoveLiftToMHF.h"
#include "commands/Lift/commandgroups/MoveLiftToLCF.h"
#include "commands/Lift/commandgroups/MoveLiftToLHF.h"
/*
#include "commands/Lift/commandgroups/MoveLiftToHCB.h"
#include "commands/Lift/commandgroups/MoveLiftToHHB.h"
#include "commands/Lift/commandgroups/MoveLiftToMCB.h"
#include "commands/Lift/commandgroups/MoveLiftToMHB.h"
#include "commands/Lift/commandgroups/MoveLiftToLCB.h"
#include "commands/Lift/commandgroups/MoveLiftToLHB.h"
*/
#include "commands/Lift/commandgroups/StowLift.h"

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
	//front
	button_lift_hc_front.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_HCF));
	button_lift_hh_front.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_HHF));
	button_lift_mc_front.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_MCF));
	button_lift_mh_front.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_MHF));
	button_lift_lc_front.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_LCF));
	button_lift_lh_front.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_LHF));
	//back
	button_lift_hc_back.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_HCB));
	button_lift_hh_back.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_HHB));
	button_lift_mc_back.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_MCB));
	button_lift_mh_back.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_MHB));
	button_lift_lc_back.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_LCB));
	button_lift_lh_back.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_LHB));
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
	//climber
	button_end_dn.reset(new frc::JoystickButton(r_buttons.get(),BTN_ENDGAME_DN));
	button_end_dnall.reset(new frc::JoystickButton(r_buttons.get(),BTN_ENDGAME_DNALL));
	button_end_up.reset(new frc::JoystickButton(r_buttons.get(),BTN_ENDGAME_UP));
	//lighting
	button_light_mu.reset(new frc::JoystickButton(r_buttons.get(),BTN_LIGHT_MODEUP));
	button_light_md.reset(new frc::JoystickButton(r_buttons.get(),BTN_LIGHT_MODEDN));

	//assign commands to buttons
	//lift front
	button_lift_hc_front->WhenPressed(new MoveLiftToHCF());
	button_lift_hh_front->WhenPressed(new MoveLiftToHHF());
	button_lift_mc_front->WhenPressed(new MoveLiftToMCF());
	button_lift_mh_front->WhenPressed(new MoveLiftToMHF());
	button_lift_lc_front->WhenPressed(new MoveLiftToLCF());
	button_lift_lh_front->WhenPressed(new MoveLiftToLHF());
	//lift back
	//button_lift_hc_back->WhenPressed(new MoveLiftToHCB());
	//button_lift_hh_back->WhenPressed(new MoveLiftToHHB());
	//button_lift_mc_back->WhenPressed(new MoveLiftToMCB());
	//button_lift_mh_back->WhenPressed(new MoveLiftToMHB());
	//button_lift_lc_back->WhenPressed(new MoveLiftToLCB());
	//button_lift_lh_back->WhenPressed(new MoveLiftToLHB());
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

