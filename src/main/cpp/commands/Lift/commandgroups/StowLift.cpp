#include "commands/Lift/commandgroups/StowLift.h"
#include "Robot.h"

//include all single commands needed for the group
#include "commands/Lift/MoveLiftJointToPosition.h"

StowLift::StowLift(){
    AddParallel(new MoveLiftJointToPosition(1,0.0));
    AddParallel(new MoveLiftJointToPosition(2,0.0));
    AddParallel(new MoveLiftJointToPosition(3,0.0));
    AddParallel(new MoveLiftJointToPosition(4,0.0));
}