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
  
  // test again
  
  Brain.Screen.print("start");

  clawOpener.spin(reverse,100, rpm);
  wait(0.25,sec);
  clawOpener.stop();

  //closes onto circle thing

  backLeft.spin(forward, 100, rpm);
  frontLeft.spin(forward, 100, rpm);
  backRight.spin(forward, 100, rpm);
  frontRight.spin(forward, 100, rpm);

  wait(0.75,sec);

  frontLeft.stop();
  backLeft.stop();
  backRight.stop();
  frontRight.stop();

  // moves forward 

  clawLifter.spin(forward,100, rpm);
  wait(1.75,sec);
  clawLifter.stop();
  
  clawOpener.spin(reverse,100,rpm);
  wait(1.25,sec);
  clawOpener.stop();

  wait(1,sec);

  clawOpener.spin(reverse,100,rpm);
  wait(0.25,sec);
  clawOpener.stop();

  backLeft.spin(reverse, 100, rpm);
  frontLeft.spin(reverse, 100, rpm);
  backRight.spin(reverse, 100, rpm);
  frontRight.spin(reverse, 100, rpm);

  wait(2,sec);
  
  frontLeft.stop();
  backLeft.stop();
  backRight.stop();
  frontRight.stop();

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
