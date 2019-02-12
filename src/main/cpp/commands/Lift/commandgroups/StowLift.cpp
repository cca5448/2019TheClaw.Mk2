#include "commands/Lift/commandgroups/StowLift.h"
#include "Robot.h"
#include "RobotMap.h"

//include all single commands needed for the group
//old way
//#include "commands/Lift/MoveLiftJointToPosition.h"
//new way using pid controllers
#include "commands/Lift/MoveLiftJoint1ToPosition.h"
//#include "commands/Lift/MoveLiftJoint2ToPosition.h"
//#include "commands/Lift/MoveLiftJoint3ToPosition.h"
//#include "commands/Lift/MoveLiftJoint4ToPosition.h"

StowLift::StowLift(){
    //old way
    //AddParallel(new MoveLiftJointToPosition(1,0.0));
    //AddParallel(new MoveLiftJointToPosition(2,0.0));
    //AddParallel(new MoveLiftJointToPosition(3,0.0));
    //AddParallel(new MoveLiftJointToPosition(4,0.0));

    //new way
    AddParallel(new MoveLiftJoint1ToPosition(LIFT_POS_STOW_1));
    //AddParallel(new MoveLiftJoint2ToPosition(LIFT_POS_STOW_2));
    //AddParallel(new MoveLiftJoint3ToPosition(LIFT_POS_STOW_3));
    //AddParallel(new MoveLiftJoint4ToPosition(LIFT_POS_STOW_4));
}