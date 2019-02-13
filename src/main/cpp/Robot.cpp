/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotMap.h"
#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>


std::shared_ptr<Claw> Robot::claw;
//std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<LiftJoint1> Robot::liftjoint1;
std::shared_ptr<LiftJoint2> Robot::liftjoint2;
std::shared_ptr<LiftJoint3> Robot::liftjoint3;
std::shared_ptr<LiftJoint4> Robot::liftjoint4;
std::shared_ptr<Sensors> Robot::sensors;
//OI after subsystems
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	//climber.reset(new Climber());
	drivetrain.reset(new Drivetrain());
  liftjoint1.reset(new LiftJoint1());
  liftjoint2.reset(new LiftJoint2());
  liftjoint3.reset(new LiftJoint3());
  liftjoint4.reset(new LiftJoint4());
  sensors.reset(new Sensors());
  //OI always after subsystems so the command requires dont grab nullptr
	oi.reset(new OI());

//  m_chooser.SetDefaultOption("Default Auto", &m_defaultAuto);
//  m_chooser.AddOption("My Auto", &m_myAuto);
//  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
  frc::Scheduler::GetInstance()->Run();
  //SmartDashboard::PutNumber("Lift 1 Pot", printf("%.2f\n",liftjoint1.get()->ReturnPIDInput()));
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
  // std::string autoSelected = frc::SmartDashboard::GetString(
  //     "Auto Selector", "Default");
  // if (autoSelected == "My Auto") {
  //   m_autonomousCommand = &m_myAuto;
  // } else {
  //   m_autonomousCommand = &m_defaultAuto;
  // }

  //m_autonomousCommand = m_chooser.GetSelected();

  //if (m_autonomousCommand != nullptr) {
  //  m_autonomousCommand->Start();
  //}
}

void Robot::AutonomousPeriodic() {
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  //if (m_autonomousCommand != nullptr) {
  //  m_autonomousCommand->Cancel();
  //  m_autonomousCommand = nullptr;
  //}
}

void Robot::TeleopPeriodic() {
  frc::Scheduler::GetInstance()->Run();
  SmartDashboard::PutNumber("Lift 1 Pot", liftjoint1.get()->ReturnPIDInput());
}

void Robot::TestPeriodic() {
  
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
