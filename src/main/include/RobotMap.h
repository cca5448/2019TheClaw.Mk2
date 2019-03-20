//This contains the variables for the robot. Anything that is configurables goes here

#pragma once

//Tuneables - Move this to network tables
const float JOYSTICK_DEADZONE = 0.25; //dead zone
const float JOYSTICK_RAMP_POWER = 1.0; //speed ramp power - this is for ramping dead zone
const float JOYSTICK_DEADZONE_TURN = 0.4; //dead zone for turn
const float JOYSTICK_RAMP_POWER_TURN = 0.9; //speed ramp power for turn
const double WRIST_KP = 1.0; //PID P proportional constant for wrist
const double WRIST_KI = 0.0; //PID I integral constant for wrist
const double WRIST_KD = 0.0; //PID D derivative constant for wrist
const double WRIST_TOLERANCE = 0.01; //PID Tolerance for wrist
const double CLAW_POT_VAL_TOLERANCE = 0.003; //Pot tolerance for claw
const double CLAW_MOT_SPEED = 0.50; //0.0-0.5 speed of claw servo

//DRIVER STATION
//Joysticks
const unsigned short JOY_LEFT           = 0; //Left joystick USB ID
const unsigned short JOY_RIGHT          = 1; //Right joystick USB ID
const unsigned short JOY_DRIVE          = JOY_LEFT; //Drive joystick
const unsigned short JOY_STEER          = JOY_RIGHT; //Steering joystick
const unsigned short JOY_LIFT           = JOY_RIGHT; //Lift adjustment joystick
const unsigned short JOY_ENDGAME_STRAFE = JOY_RIGHT; //Endgame strafe joystick
const unsigned short JOY_DRIVE_AXIS_THROTTLE    = 1; //Throttle Axis
const unsigned short JOY_DRIVE_AXIS_STRAFE      = 0; //Strafe Axis
const unsigned short JOY_LIFT_AXIS_LIFT         = 1; //Lift Adjust Axis
const unsigned short JOY_STEER_AXIS_TURN        = 0; //Turn Axis
const unsigned short JOY_ENDGAME_AXIS_STRAFE    = 0; //Strafe Axis during endgame (re-use turn axis)

//Buttons (Left Joystick)
const unsigned short BTN_LIFT_UP        = 5; //Lift Up
const unsigned short BTN_LIFT_DOWN      = 4; //Lift Down
const unsigned short BTN_WRIST_UP       = 6; //Wrist Up
const unsigned short BTN_WRIST_DOWN     = 3; //Wrist Down
const unsigned short BTN_WRIST_STOW     = 14; //Wrist stow (button 8+6)
const unsigned short BTN_CAM_AA         = 9; //Aim Assist
//Buttons (Right Joystick)
const unsigned short BTN_CLAW_FO        = 5; //Claw to full open
const unsigned short BTN_CLAW_CC        = 6; //Claw to capture cargo
const unsigned short BTN_CLAW_FC        = 4; //Claw to full closed
const unsigned short BTN_CLAW_CH        = 3; //Claw to capture hatch
const unsigned short BTN_CLAW_EHR       = 12; //Claw to emergence hatch release (full close + safe zone)
const unsigned short BTN_CLAW_STOP      = 8; //Claw stop wherever it is
const unsigned short BTN_LIGHT_MODEUP   = 1; //Increment lighting mode
const unsigned short BTN_LIGHT_MODEDN   = 9; //Decrement lighting mode

//DRIVETRAIN
//Drivetrain Motor Controllers CAN IDs - Victor SPX
const unsigned short DRIVE_MOT_LF			= 1; //Left Front
const unsigned short DRIVE_MOT_LR			= 2; //Left Rear
const unsigned short DRIVE_MOT_RF			= 3; //Right Front
const unsigned short DRIVE_MOT_RR			= 4; //Right Rear

//LIFT SYSTEM
const unsigned short LIFT_MOT       = 7; //Talon SRX CAN ID for Lift Motor
const unsigned short LIFT_SPEED     = 1.0; //Lift motor speed

//WRIST SYSTEM
const unsigned short WRIST_MOT      = 7; //Talon SRX CAN ID for Wrist Motor
const unsigned short WRIST_POT      = 1; //Potentiometer for wrist joint
const double WRIST_MAX              = 0.75; //max wrist up
const double WRIST_MIN              = 0.25; //min wrist down
const double WRIST_POS_STOW         = 0.75; //stow position for wrist
const double WRIST_POS_UP           = 0.55; //up position for wrist
const double WRIST_POS_DOWN         = 0.35; //down position for wrist

//MANIPULATOR
//Claw System Servo PWM IDs - Rev Smart Servo
const unsigned short CLAW_MOT       = 0; //Claw Servo PWM ID
const unsigned short CLAW_POT       = 0; //Claw Pot Analog ID
const double CLAW_POT_OFFSET        = 0.0; //Claw Pot offset
//Claw Sensor Pot Position Values
const double CLAW_POT_VAL_EHR       = 0.240; //Emergency Hatch Release
const double CLAW_POT_VAL_FC        = 0.258; //Full Closed
const double CLAW_POT_VAL_CH        = 0.334; //Capture Hatch
const double CLAW_POT_VAL_CC        = 0.506; //Capture Cargo
const double CLAW_POT_VAL_FO        = 0.686; //Full Open
 