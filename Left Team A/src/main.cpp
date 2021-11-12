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
// clawLifter1          motor         9               
// clawOpener           motor         14              
// clawLifter2          motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void move(float duration,std::string direction)
{
  if (direction == "forward") {

    frontLeft.spin(forward,60,rpm);
    backLeft.spin(forward, 60, rpm);
    backRight.spin(forward, 60, rpm);
    frontRight.spin(forward,60, rpm);

    wait(duration,sec);

    frontLeft.stop();
    backLeft.stop();
    backRight.stop();
    frontRight.stop();
  }

  if (direction == "backward"){
    frontLeft.spin(reverse,100,rpm);
    backLeft.spin(reverse,100,rpm);
    backRight.spin(reverse,100,rpm);
    frontRight.spin(reverse,100,rpm);

    wait(duration,sec);

    frontLeft.stop();
    backLeft.stop();
    backRight.stop();
    frontRight.stop();
  }

  if (direction == "left"){
    frontLeft.spin(forward,110,rpm);
    backLeft.spin(forward, 110, rpm);

    wait(duration,sec);

    frontLeft.stop();
    backLeft.stop();
  }
  
  if (direction == "right"){
    frontRight.spin(forward,110,rpm);
    backRight.spin(forward, 110, rpm);

    wait(duration,sec);

    frontRight.stop();
    backRight.stop();
  }

}

void autonomous(void) {
  
  Brain.Screen.print("start");

  // lifts claw
  clawLifter1.spin(reverse,100,rpm);
  clawLifter2.spin(reverse,100,rpm);
  wait(0.5,sec);
  clawLifter1.stop();
  clawLifter2.stop();

  // closes claw
  clawOpener.spin(reverse,50,rpm);
  wait(0.75,sec);

  // small break

  wait(0.5, sec);

  // lifts claw
  clawLifter1.spin(forward,100,rpm);
  clawLifter2.spin(forward,100,rpm);
  wait(0.8,sec);
  clawLifter1.stop();
  clawLifter2.stop();

  // moves backward
  move(0.25,"forward");

  // opens claw
  clawOpener.spin(forward,100,rpm);
  wait(0.25,sec);
  clawOpener.stop();


  /* without touching red

  // closes claw
  clawOpener.spin(reverse,100,rpm);
  wait(0.25,sec);
  clawOpener.stop();

  // lifts claw
  clawLifter1.spin(forward,100,rpm);
  clawLifter2.spin(forward,100,rpm);
  wait(0.8,sec);
  clawLifter1.stop();
  clawLifter2.stop();

  // moves backward
  move(1.5,"forward");

  // opens claw
  clawOpener.spin(forward,100,rpm);
  wait(0.25,sec);
  clawOpener.stop();

  */
  }



void controls(void) 
{
  while(1)
  {
  backLeft.spin(directionType::fwd,Controller1.Axis3.position(),percentUnits::pct);
  frontLeft.spin(directionType::fwd,Controller1.Axis3.position(),percentUnits::pct);
  
  backRight.spin(directionType::fwd,Controller1.Axis2.position(),percentUnits::pct);
  frontRight.spin(directionType::fwd,Controller1.Axis2.position(),percentUnits::pct);

  clawLifter1.spin(forward, 100*(Controller1.ButtonL2.pressing() - Controller1.ButtonR2.pressing()), rpm);
  clawLifter2.spin(forward, 100*(Controller1.ButtonL2.pressing() - Controller1.ButtonR2.pressing()), rpm);
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
