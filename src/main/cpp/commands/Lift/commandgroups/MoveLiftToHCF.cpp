#include "commands/Lift/commandgroups/MoveLiftToHCF.h"
#include "RobotMap.h"

//include all single commands needed for the group
#include "commands/Lift/MoveLiftJoint1ToPosition.h"
#include "commands/Lift/MoveLiftJoint2ToPosition.h"
#include "commands/Lift/MoveLiftJoint3ToPosition.h"
#include "commands/Lift/MoveLiftJoint4ToPosition.h"

MoveLiftToHCF::MoveLiftToHCF(){
    AddParallel(new MoveLiftJoint1ToPosition(LIFT_POS_HCF_1));
    AddParallel(new MoveLiftJoint2ToPosition(LIFT_POS_HCF_2));
    AddParallel(new MoveLiftJoint3ToPosition(LIFT_POS_HCF_3));
    AddParallel(new MoveLiftJoint4ToPosition(LIFT_POS_HCF_4));
}