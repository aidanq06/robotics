/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Wed Sep 22 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBack             motor         20              
// rightBack            motor         11              
// leftFront            motor         19              
// rightFront           motor         12              
// Controller1          controller                    
// clawLifter           motor         13              
// clawOpener           motor         14              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

vex::competition Competition;

void controls(void) {
  while(1){

    /*
    claw opener/lifter
    */
    if(Controller1.ButtonL1.pressing())
    {
      clawOpener.spin(directionType::fwd);
    }
    else if(Controller1.ButtonR1.pressing())
    {
      clawOpener.spin(directionType::rev);
    }
    else if(Controller1.ButtonL2.pressing())
    {
      clawLifter.spin(directionType::fwd);
    }
    else if(Controller1.ButtonR2.pressing())
    {
      clawLifter.spin(directionType::rev);
    }
    else
    {
      clawLifter.stop();
      clawOpener.stop();
    }

    /*
    leftBack = 20
    leftFront = 19
    */

    leftBack.spin(directionType::fwd,Controller1.Axis3.position(),percentUnits::pct);
    leftFront.spin(directionType::fwd,Controller1.Axis3.position(),percentUnits::pct);

    /* 
    rightBack = 11
    rightFront = 12
    */
    
    rightBack.spin(directionType::fwd,Controller1.Axis2.position(),percentUnits::pct);
    rightFront.spin(directionType::fwd,Controller1.Axis2.position(),percentUnits::pct);


    


  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Competition.drivercontrol(controls);
}

