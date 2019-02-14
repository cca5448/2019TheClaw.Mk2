#pragma once

#include <frc/WPILib.h>

class OI
{
	public:
		OI();
		double GetThrottleAxis(); //returns the axis to drive the robot
		double GetStrafeAxis(); //returns the axis to strafe the robot
		double GetTurnAxis(); //returns the axis to turn the robot
		double GetLiftAxis(); //returns the axis for lift adjustment
	private:
		//private functions
		double DeadZone(double uval);
		double SteeringDeadZone(double uval);
		double RampingDeadZone(double uval);

		//create joystick objects
		std::shared_ptr<frc::Joystick> drive_stick;
		std::shared_ptr<frc::Joystick> steer_stick;
		std::shared_ptr<frc::Joystick> lift_stick;
		std::shared_ptr<frc::Joystick> l_buttons; //left set of buttons
		std::shared_ptr<frc::Joystick> r_buttons; //right set of buttons

		//create buttons for control
		//lift
		std::shared_ptr<frc::JoystickButton> button_lift_lh_front; //low hatch front
		std::shared_ptr<frc::JoystickButton> button_lift_mh_front; //mid hatch front
		std::shared_ptr<frc::JoystickButton> button_lift_hh_front; //high hatch front
		std::shared_ptr<frc::JoystickButton> button_lift_lc_front; //low cargo front
		std::shared_ptr<frc::JoystickButton> button_lift_mc_front; //mid cargo front
		std::shared_ptr<frc::JoystickButton> button_lift_hc_front; //high cargo front
		std::shared_ptr<frc::JoystickButton> button_lift_lh_back; //low hatch back
		std::shared_ptr<frc::JoystickButton> button_lift_mh_back; //mid hatch back
		std::shared_ptr<frc::JoystickButton> button_lift_hh_back; //high hatch back
		std::shared_ptr<frc::JoystickButton> button_lift_lc_back; //low cargo back
		std::shared_ptr<frc::JoystickButton> button_lift_mc_back; //mid cargo back
		std::shared_ptr<frc::JoystickButton> button_lift_hc_back; //high cargo back
		//claw
		std::shared_ptr<frc::JoystickButton> button_claw_fo; //full open
		std::shared_ptr<frc::JoystickButton> button_claw_cc; //capture cargo
		std::shared_ptr<frc::JoystickButton> button_claw_fc; //full closed
		std::shared_ptr<frc::JoystickButton> button_claw_ch; //capture hatch
		std::shared_ptr<frc::JoystickButton> button_claw_ehr; //emergency hatch release (full close + safe zone)
		std::shared_ptr<frc::JoystickButton> button_claw_stop; //stop
		//other
		std::shared_ptr<frc::JoystickButton> button_cam_aa; //aim assist
		std::shared_ptr<frc::JoystickButton> button_end_up; //extend both sides
		std::shared_ptr<frc::JoystickButton> button_end_dn; //retract close side
		std::shared_ptr<frc::JoystickButton> button_end_dnall; //retract both sides
		std::shared_ptr<frc::JoystickButton> button_light_mu; //light mode up
		std::shared_ptr<frc::JoystickButton> button_light_md; //light mode down
};

