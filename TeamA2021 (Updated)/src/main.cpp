/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\royalrobotics                                    */
/*    Created:      Tue Sep 28 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeft            motor         1               
// backLeft             motor         12              
// frontRight           motor         10              
// backRight            motor         18              
// clawLifter           motor         5               
// clawOpener           motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void autonomous(void) {
  Brain.Screen.print("start");
  backLeft.spin(forward, 200, rpm);
  frontLeft.spin(forward, 200, rpm);
  backRight.spin(forward, 200, rpm);
  frontRight.spin(forward, 200, rpm);
  
  wait(.2,sec);

  frontLeft.stop();
  backLeft.stop();
  backRight.stop();
  frontRight.stop();

  clawLifter.spin(reverse,200, rpm);
  wait(.5,sec);
  clawLifter.stop();
  
  backLeft.spin(forward, 200, rpm);
  frontLeft.spin(forward, 200, rpm);
  backRight.spin(forward, 200, rpm);
  frontRight.spin(forward, 200, rpm);
  
  wait(.2,sec);

  frontLeft.stop();
  backLeft.stop();
  backRight.stop();
  frontRight.stop();

  clawOpener.spin(reverse,200,rpm);
  wait(1,sec);

  backLeft.spin(reverse, 200, rpm);
  frontLeft.spin(reverse, 200, rpm);
  backRight.spin(reverse, 200, rpm);
  frontRight.spin(reverse, 200, rpm);

  wait(.5,sec);
  

  frontLeft.stop();
  backLeft.stop();
  backRight.stop();
  frontRight.stop();

  clawLifter.spin(forward,200, rpm);
  wait(.5,sec);
  clawLifter.stop();

  clawOpener.spin(forward,200,rpm);
  wait(1,sec);
  clawOpener.stop();
  }

void controls(void) 
{
  /*
  change the ports
  */
  while(1)
  {
  backLeft.spin(directionType::fwd,Controller1.Axis3.position(),percentUnits::pct);
  frontLeft.spin(directionType::fwd,Controller1.Axis3.position(),percentUnits::pct);

  /* 
  rightBack = 11
  rightFront = 12
  */
  
  backRight.spin(directionType::fwd,Controller1.Axis2.position(),percentUnits::pct);
  frontRight.spin(directionType::fwd,Controller1.Axis2.position(),percentUnits::pct);

  clawLifter.spin(forward, 200*(Controller1.ButtonL2.pressing() - Controller1.ButtonR2.pressing()), rpm);
  clawOpener.spin(forward, -200*(Controller1.ButtonL1.pressing() - Controller1.ButtonR1.pressing()), rpm);

  }
}

vex::competition Competition;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Competition.drivercontrol(controls);
  Competition.autonomous(autonomous);
}
