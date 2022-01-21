
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
// Drivetrain           drivetrain    1, 3            
// Intake               motor         7               
// MiddleWheel          motor         9               
// Controller1          controller                    
// Forklift             motor_group   4, 5            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition 
competition Competition;

// PRE-AUTONOMOUS CODE

void pre_auton(void) {vexcodeInit();}

void autodrive(void) {

  Drivetrain.setDriveVelocity(100,percent);
  Intake.setVelocity(100,percent);
  MiddleWheel.setVelocity(100,percent);
  Forklift.setVelocity(100,percent);
  
  //Basic Autonomous Code 
  //Plan: Drop Forklift, Go to Goal, Pick up Goal, Turn, Turn on Intake, Go Forward and Collect Rings
  Brain.Screen.print("Autonomous");
  Forklift.spinFor(forward,160,degrees);
  Drivetrain.driveFor(forward,60, inches);
  Forklift.spinFor(reverse,160,degrees);
  Drivetrain.turnFor(right,90,degrees);
  Intake.spin(reverse);
  Drivetrain.driveFor(forward,10,inches);
  Intake.stop();
}

// DRIVER CONTROL

void usercontrol(void) {
  while (1) { 

    Brain.Screen.print("Driver in Control");
    // Switched Driver Control Code to the controller method which works better
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
