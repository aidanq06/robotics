#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor frontLeft = motor(PORT1, ratio18_1, false);
motor backLeft = motor(PORT12, ratio18_1, false);
motor frontRight = motor(PORT10, ratio18_1, true);
motor backRight = motor(PORT18, ratio18_1, true);
motor clawLifter1 = motor(PORT9, ratio18_1, false);
motor clawOpener = motor(PORT14, ratio18_1, false);
motor clawLifter2 = motor(PORT8, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}