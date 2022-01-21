
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
// Controller1          controller                    
// Forklift             motor_group   4, 5            
// Intake               motor         7               
// MiddleWheel          motor         9               
// Drivetrain           drivetrain    1, 3            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// PRE-AUTONOMOUS CODE

void pre_auton(void) {vexcodeInit();}

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
  Intake.stop()
}
  
void usercontrol(void) {
  while (1) {

    Brain.Screen.print("Driver in Control"); // Replaced code w/ the controller menu being set-up
  
    wait(20, msec);                
  }
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
