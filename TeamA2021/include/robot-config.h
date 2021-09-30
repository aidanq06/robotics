using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftBack;
extern motor rightBack;
extern motor leftFront;
extern motor rightFront;
extern controller Controller1;
extern motor clawLifter;
extern motor clawOpener;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );