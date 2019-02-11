#include "commands/Lift/commandgroups/StowLift.h"
#include "Robot.h"

//include all single commands needed for the group
#include "commands/Lift/MoveLiftJointToPosition.h"

StowLift::StowLift(){
    frc::AddParallel(new MoveLiftJointToPosition(1,0.0));
    frc::AddParallel(new MoveLiftJointToPosition(2,0.0));
    frc::AddParallel(new MoveLiftJointToPosition(3,0.0));
    frc::AddParallel(new MoveLiftJointToPosition(4,0.0));
}