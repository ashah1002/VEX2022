
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

// define your global instances of motors and other devices here

// PRE-AUTONOMOUS CODE

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

// AUTONOMOUS CODE

void autonomous(void) {
  // GOAL: My autonomous code below should drive the robot forward 6 feet, pick up a mobile goal, and then drive back.
  Forklift.setVelocity(100,percent);
 
  Brain.Screen.print("Hello World!");
  Forklift.spinFor(reverse,20,turns);

  //Drivetrain.driveFor(forward,60, inches);
  //Intake.spin(forward);
  //Drivetrain.turnFor(left, 180, degrees);
  //Drivetrain.driveFor(forward, 60, inches);
  //Forklift.spinFor(reverse, 90, degrees);
  //Intake.stop();
  //Drivetrain.turnFor(left, 180, degrees);
}

// DRIVER CONTROL

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    Brain.Screen.print("Finished");
    Drivetrain.setDriveVelocity(100,percent);
    Intake.setVelocity(100,percent);
    MiddleWheel.setVelocity(100,percent);
    Forklift.setVelocity(100,percent);

    wait(20, msec);                
  }
}

//
// Set up competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  //autonomous(); // I just added this in, it might make the autonomous part actually run

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
