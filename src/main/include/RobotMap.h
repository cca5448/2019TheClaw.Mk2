//This contains the variables for the robot. Anything that is configurables goes here

#pragma once

//Adjustables
const float JOYSTICK_DEADZONE = 0.25; //dead zone
const float JOYSTICK_RAMP_POWER = 1.1; //speed ramp power - this is for proportionalAxis
const float CLIMB_MOT_SPEED_CLIMB = 0.5; //speed of climber climb motor
const float CLIMB_MOT_SPEED_DRIVE = 0.5; //speed of climber drive motor
const double LIFT_JOINT_KP = 5.0; //PID P proportional constant for lift joints
const double LIFT_JOINT_KI = 0.0; //PID I integral constant for lift joints
const double LIFT_JOINT_KD = 0.0; //PID D derivative constant for lift joints
const double LIFT_JOINT_TOLERANCE = 0.05; //PID Tolerance for lift joints

//DRIVER STATION
//Joysticks
const unsigned short JOY_LEFT           = 0; //Left joystick USB ID
const unsigned short JOY_RIGHT          = 1; //Right joystick USB ID
const unsigned short JOY_DRIVE          = JOY_LEFT; //Drive joystick
const unsigned short JOY_STEER          = JOY_RIGHT; //Steering joystick
const unsigned short JOY_LIFT           = JOY_RIGHT; //Lift adjustment joystick
const unsigned short JOY_ENDGAME_STRAFE = JOY_RIGHT; //Endgame strafe joystick
const unsigned short JOY_DRIVE_AXIS_THROTTLE    = 0; //Throttle Axis
const unsigned short JOY_DRIVE_AXIS_STRAFE      = 1; //Strafe Axis
const unsigned short JOY_LIFT_AXIS_LIFT         = 1; //Lift Adjust Axis
const unsigned short JOY_STEER_AXIS_TURN        = 0; //Turn Axis
const unsigned short JOY_ENDGAME_AXIS_STRAFE    = 0; //Strafe Axis during endgame (re-use turn axis)
//Buttons (Left Joystick)
const unsigned short BTN_LIFT_LH_F      = 5; //Lift to low hatch on front
const unsigned short BTN_LIFT_MH_F      = 6; //Lift to mid hatch on front
const unsigned short BTN_LIFT_HH_F      = 7; //Lift to high hatch on front
const unsigned short BTN_LIFT_LC_F      = 4; //Lift to low cargo on front
const unsigned short BTN_LIFT_MC_F      = 3; //Lift to mid cargo on front
const unsigned short BTN_LIFT_HC_F      = 2; //Lift to high cargo on front
const unsigned short BTN_LIFT_LH_B      = 13; //Lift to low hatch on front
const unsigned short BTN_LIFT_MH_B      = 14; //Lift to mid hatch on front
const unsigned short BTN_LIFT_HH_B      = 15; //Lift to high hatch on front
const unsigned short BTN_LIFT_LC_B      = 12; //Lift to low cargo on front
const unsigned short BTN_LIFT_MC_B      = 11; //Lift to mid cargo on front
const unsigned short BTN_LIFT_HC_B      = 10; //Lift to high cargo on front
const unsigned short BTN_CAM_AA         = 9; //Aim Assist
//Buttons (Right Joystick)
const unsigned short BTN_CLAW_FO        = 5; //Claw to full open
const unsigned short BTN_CLAW_CC        = 6; //Claw to capture cargo
const unsigned short BTN_CLAW_FC        = 4; //Claw to full closed
const unsigned short BTN_CLAW_CH        = 3; //Claw to capture hatch
const unsigned short BTN_CLAW_EHR       = 12; //Claw to emergence hatch release (full close + safe zone)
const unsigned short BTN_ENDGAME_UP     = 7; //Extend platform climber both sides
const unsigned short BTN_ENDGAME_DN     = 2; //Retract platform climber close side
const unsigned short BTN_ENDGAME_DNALL  = 10; //Retract platform climber both sides
const unsigned short BTN_LIGHT_MODEUP   = 1; //Increment lighting mode
const unsigned short BTN_LIGHT_MODEDN   = 9; //Decrement lighting mode

//DRIVETRAIN
//Drivetrain Motor Controllers CAN IDs - Victor SPX
const unsigned short DRIVE_MOT_LF			= 1; //Left Front
const unsigned short DRIVE_MOT_LR			= 2; //Left Rear
const unsigned short DRIVE_MOT_RF			= 3; //Right Front
const unsigned short DRIVE_MOT_RR			= 4; //Right Rear

//LIFT SYSTEM
//Lift System Motor Controllers CAN IDs - Talon SRX
const unsigned short LIFT_MOT_1       = 1; //Lowest joint
const unsigned short LIFT_MOT_2       = 2; 
const unsigned short LIFT_MOT_3       = 3; 
const unsigned short LIFT_MOT_4       = 4; //Highest joint
//Lift System Sensor Pots Analog IDs - 10-turn 10k linear
const unsigned short LIFT_POT_1     = 1;
const unsigned short LIFT_POT_2     = 2;
const unsigned short LIFT_POT_3     = 3;
const unsigned short LIFT_POT_4     = 4;
//Lift System Sensor Pots offset in degrees
const double LIFT_POT_OFFSET_1      = 1800.0;
const double LIFT_POT_OFFSET_2      = 1800.0;
const double LIFT_POT_OFFSET_3      = 1800.0;
const double LIFT_POT_OFFSET_4      = 1800.0;
//Lift System Locations
const double LIFT_POS_STOW_1        = 1.0; //stow lift
const double LIFT_POS_LHF_1         = 1.1; //low hatch front
const double LIFT_POS_LCF_1         = 1.2; //low cargo front
const double LIFT_POS_MHF_1         = 2.1; //mid hatch front
const double LIFT_POS_MCF_1         = 2.2; //mid cargo front
const double LIFT_POS_HHF_1         = 3.1; //high hatch front
const double LIFT_POS_HCF_1         = 3.2; //high cargo front

//MANIPULATOR
//Claw System Servo PWM IDs - Rev Smart Servo
const unsigned short CLAW_MOT_1     = 1;
//Claw System Sensor Pots Analog IDs - 10-turn 10k linear
const unsigned short CLAW_POT_1     = 5;
//Claw System Sensor Pots offset in degrees
const double CLAW_POT_OFFSET_1      = 1800.0; //degrees to offset the pot
//Claw Sensor Pot Position Values
const double CLAW_POT_VAL_EHR         = 0; //Emergency Hatch Release
const double CLAW_POT_VAL_FC          = 0; //Full Closed
const double CLAW_POT_VAL_CH          = 0; //Capture Hatch
const double CLAW_POT_VAL_CC          = 0; //Capture Cargo
const double CLAW_POT_VAL_FO          = 0; //Full Open
 
//CLIMBER
//Motor CAN IDs - Talon SRX
const unsigned short CLIMB_MOT_LEFT     = 5;
const unsigned short CLIMB_MOT_RIGHT    = 6;
const unsigned short CLIMB_MOT_DRIVE    = 7;
//Limit Switch DIO IDs
const unsigned short CLIMB_LIMIT_LEFT_RETRACT       = 1;
const unsigned short CLIMB_LIMIT_LEFT_EXTEND        = 2;
const unsigned short CLIMB_LIMIT_RIGHT_RETRACT      = 3;
const unsigned short CLIMB_LIMIT_RIGHT_EXTEND       = 4;
//Distance Sensor DIO IDs
const unsigned short CLIMB_DISTANCE_SENSOR          = 5;
