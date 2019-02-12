//#include <math.h>
#include "OI.h"
#include "RobotMap.h"
#include <frc/WPILib.h>

//#include "Commands/Climber/StartClimberUp.h"
//#include "Commands/Climber/StartClimberDown.h"
//#include "Commands/Climber/StopClimber.h"
//#include "Commands/Shooter/StartShooter.h"
//#include "Commands/Shooter/StopShooter.h"
//#include "Commands/Shooter/AdvanceShooter.h"
//#include "Commands/Shooter/AdvanceShooterStop.h"

double OI::DeadZone(double axisVal)
{
	//if the axisVal is in the deadzone defined in robotmap.h, return 0.0 instead
	if (axisVal >= -JOYSTICK_DEADZONE && axisVal <= JOYSTICK_DEADZONE) {
		return 0.0;
	}
	return axisVal;
}

double OI::SteeringDeadZone(double uval)
{
	double f_absval, f_offset, f_uval, f_pow;
    //if we are less than 0, then save an inversion for the end
	double invert = 1.0;
	if (uval < 0) invert = -1.0;
	//get the abs of the value for maths
	f_absval = fabs(uval);

	f_offset = 1-JOYSTICK_DEADZONE;
	f_uval = f_absval-1;
	//divide by the offset (1-deadzone)
	f_uval /= f_offset;
	//add 1
	f_uval += 1.0;

	//now make it either positive or negative depending on what came in
	f_uval *= invert;
	return f_uval;
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

double OI::InputShape(double userValue)
{
	//This maps the axis value to a 0-255 number, where 127 is neutral
	double iUserValue;
	iUserValue = (double)userValue * 127;
	iUserValue += 127;
	//iUserValue = inputShape[iUserValue];
	//SmartDashboard::PutNumber("iUserValue",iUserValue);
	userValue = iUserValue - 127;
	userValue /= 127;
	return userValue;
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
	//intake_in_btn = new frc::JoystickButton(l_buttons,BTN_INTAKE_IN);
	//intake_stop_btn = new frc::JoystickButton(l_buttons,BTN_INTAKE_STOP);
	//intake_out_btn = new frc::JoystickButton(l_buttons,BTN_INTAKE_OUT);
	//auton_next = new frc::JoystickButton(l_buttons,BTN_AUTON_NEXT);
	//auton_prev = new frc::JoystickButton(l_buttons,BTN_AUTON_PREV);

	//right button definitions
	//climber_up = new frc::JoystickButton(r_buttons,BTN_CLIMB_UP);
	//climber_down = new frc::JoystickButton(r_buttons,BTN_CLIMB_DOWN);
	//climber_stop = new frc::JoystickButton(r_buttons,BTN_CLIMB_STOP);
	//camera_toggle = new frc::JoystickButton(r_buttons,BTN_CAM_TOGGLE);
	//shooter_toggle_btn = new frc::JoystickButton(r_buttons,BTN_SHOOTER_UP);
	//shooter_stop_btn = new frc::JoystickButton(r_buttons,BTN_SHOOTER_STOP);
	//shooter_start_btn = new frc::JoystickButton(r_buttons,BTN_SHOOTER_START);
	//shooter_adv_btn = new frc::JoystickButton(r_buttons,BTN_SHOOTER_ADV);


	//auton_next->ToggleWhenPressed(new NextAuton()); //Next Auton Mode
	//auton_prev->ToggleWhenPressed(new PrevAuton()); //Prev Auton Mode
	//camera_toggle->ToggleWhenPressed(new CameraToggle());

	//climber buttons
	//climber_up->ToggleWhenPressed(new StartClimberUp());
	//climber_down->ToggleWhenPressed(new StartClimberDown());
	//climber_stop->ToggleWhenPressed(new StopClimber());
//samplebutton = new frc::JoystickButton(r_buttons,1);
//samplebutton->WhenPressed(new command());
//samplebutton->WhenReleased(new command());
//samplebutton->ToggleWhenPressed(new command());
	//shooter button actions
	//shooter_toggle_btn->WhenPressed(new ToggleShooter());
	//shooter_stop_btn->WhenPressed(new StopShooter());
	//shooter_start_btn->WhenPressed(new StartShooter());
	//shooter_adv_btn->WhenPressed(new AdvanceShooter());
	//shooter_adv_btn->WhenReleased(new AdvanceShooterStop());
}

double OI::GetThrottleAxis(){
	//method will return the drive throttle axis
	return -1 * (RampingDeadZone(drive_stick->GetRawAxis(JOY_DRIVE_AXIS_THROTTLE)));
	//return drive_stick->GetRawAxis(JOY_DRIVE_AXIS_THROTTLE);
}
double OI::GetStrafeAxis(){
	//method will return the strafe axis
	return 1 * (RampingDeadZone(drive_stick->GetRawAxis(JOY_DRIVE_AXIS_STRAFE)));
	//return drive_stick->GetRawAxis(JOY_DRIVE_AXIS_STRAFE);
}
double OI::GetTurnAxis(){
	//method will return the turn axis
	return 1 * (DeadZone(steer_stick->GetRawAxis(JOY_STEER_AXIS_TURN)));
	//return steer_stick->GetRawAxis(JOY_STEER_AXIS_TURN);
}
double OI::GetLiftAxis(){
	//method will return the lift adjust axis
	return -1 * (DeadZone(lift_stick->GetRawAxis(JOY_LIFT_AXIS_LIFT)));
	//return lift_stick->GetRawAxis(JOY_LIFT_AXIS_LIFT);
}

