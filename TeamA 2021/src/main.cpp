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
// backLeft             motor         2               
// frontRight           motor         3               
// backRight            motor         4               
// clawLifter           motor         5               
// clawOpener           motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

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
}
