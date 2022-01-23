
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Team 1526C - BHS HexaDecimators                           */
/*    Created:      Monday, December 13, 2021                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Forklift             motor_group   4, 5            
// Drivetrain           drivetrain    1, 3            
// Intake               motor         7               
// MiddleWheel          motor         9               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// PRE-AUTONOMOUS CODE

void pre_auton(void) {vexcodeInit();
  Forklift.setPosition(0, degrees);
}

void autodrive(void) {
  // Autonomous Code
  // Plan: Drop Forklift Down, Go to Goal, Pick Up Goal, Turn, Spin Intake, Pick up Rings
  
  Drivetrain.setDriveVelocity(100,percent);
  Intake.setVelocity(100,percent);
  MiddleWheel.setVelocity(100,percent);
  Forklift.setVelocity(100,percent);  
 
  Brain.Screen.print("Start Autonomous");
  Forklift.spinFor(forward,160,degrees);
  Drivetrain.driveFor(forward,60, inches);
  Forklift.spinFor(reverse,160,degrees);
  Drivetrain.turnFor(left, 90, degrees);
  Intake.spin(reverse);
  Drivetrain.driveFor(reverse,10, inches);
  Intake.stop();
  
}
  
void fldown(void) {
   Forklift.spinTo(85, degrees);
}

void flup(void) {
  Forklift.spinTo(25, degrees);
}

void usercontrol(void) {
  while (1) {

    // Brain.Screen.print("Driver in Control"); // Replaced code w/ the controller menu being set-up
    Controller1.ButtonL1.pressed(flup);
    Controller1.ButtonL2.pressed(fldown);
  
  }
  wait(20, msec);                
}

//
// Set up competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control.
  Competition.autonomous(autodrive);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  autodrive();
  usercontrol();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

