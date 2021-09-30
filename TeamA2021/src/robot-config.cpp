#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftBack = motor(PORT20, ratio18_1, false);
motor rightBack = motor(PORT11, ratio18_1, true);
motor leftFront = motor(PORT19, ratio18_1, false);
motor rightFront = motor(PORT12, ratio18_1, true);
controller Controller1 = controller(primary);
motor clawLifter = motor(PORT13, ratio36_1, false);
motor clawOpener = motor(PORT14, ratio36_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}