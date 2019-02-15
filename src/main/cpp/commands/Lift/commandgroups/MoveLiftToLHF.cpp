#include "commands/Lift/commandgroups/MoveLiftToLHF.h"
#include "Robot.h"
#include "RobotMap.h"

//include all single commands needed for the group
#include "commands/Lift/MoveLiftJoint1ToPosition.h"
#include "commands/Lift/MoveLiftJoint2ToPosition.h"
#include "commands/Lift/MoveLiftJoint3ToPosition.h"
#include "commands/Lift/MoveLiftJoint4ToPosition.h"


MoveLiftToLHF::MoveLiftToLHF(){
    frc::SmartDashboard::PutString("Last Action","Lift: Move to Low-Hatch Front");
    AddParallel(new MoveLiftJoint1ToPosition(LIFT_POS_LHF_1));
    AddParallel(new MoveLiftJoint2ToPosition(LIFT_POS_LHF_2));
    AddParallel(new MoveLiftJoint3ToPosition(LIFT_POS_LHF_3));
    AddParallel(new MoveLiftJoint4ToPosition(LIFT_POS_LHF_4));
}