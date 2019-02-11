#include "commands/Lift/commandgroups/MoveLiftToHC.h"
#include "Robot.h"

//include all single commands needed for the group
#include "commands/Lift/MoveLiftJointToPosition.h"

MoveLiftToHC::MoveLiftToHC(){
    frc::AddParallel(new MoveLiftJointToPosition(1,0.25));
    frc::AddParallel(new MoveLiftJointToPosition(2,0.5));
    frc::AddParallel(new MoveLiftJointToPosition(3,0.75));
    frc::AddParallel(new MoveLiftJointToPosition(4,1.0));
}