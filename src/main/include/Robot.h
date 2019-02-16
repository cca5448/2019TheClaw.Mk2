#pragma once

//include the things needed here at the robot level
#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

//include any commands used here in robot level code

//OI is the operator interface
#include "OI.h"

//include all the subsystem classes
#include "subsystems/Claw.h"
//#include "subsystems/Climber.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/LiftJoint1.h"
#include "subsystems/LiftJoint2.h"
#include "subsystems/LiftJoint3.h"
#include "subsystems/LiftJoint4.h"
#include "subsystems/Sensors.h"
#include "subsystems/Vision.h"

class Robot : public frc::TimedRobot {
 public:
  static std::shared_ptr<Claw> claw;
  //static std::shared_ptr<Climber> climber;
  static std::shared_ptr<Drivetrain> drivetrain;
  static std::shared_ptr<LiftJoint1> liftjoint1;
  static std::shared_ptr<LiftJoint2> liftjoint2;
  static std::shared_ptr<LiftJoint3> liftjoint3;
  static std::shared_ptr<LiftJoint4> liftjoint4;
  static std::shared_ptr<Sensors> sensors;
  static std::shared_ptr<Vision> vision;
  
  static std::unique_ptr<OI> oi;

  void RobotInit() override;
  void UpdateDashPeriodic();
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  //frc::Command* m_autonomousCommand = nullptr;
  //ExampleCommand m_defaultAuto;
  //MyAutoCommand m_myAuto;
  //frc::SendableChooser<frc::Command*> m_chooser;
};
