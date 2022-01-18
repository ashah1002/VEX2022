// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 3            
// Intake               motor         7               
// MiddleWheel          motor         9               
// Controller1          controller                    
// Forklift             motor_group   4, 5            
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
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

// WHAT CHANGED:
// This is similar to my first program, but there are some differences. The forklift 
// motors are now rotating in different directions, because last time they moved in the
// same direction and it didn't work for some reason. The program now calls autonomous()
// after pre_auton() is called. I set all of the motor speeds to 100% at the beginning
// of the autonomous and driver control. In autonomous, the forklift motors should now
// rotate 90 degrees (not 1 turn). In driver control, the intake motor should always
// be spinning.

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/



void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  Brain.Screen.print("Hi there!");
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  // My autonomous code below should drive the robot forward 6 feet, pick up a mobile goal, and then drive back.
  Brain.Screen.print("Hello World!");
  
  Drivetrain.setDriveVelocity(100,percent);
  Intake.setVelocity(100,percent);
  MiddleWheel.setVelocity(100,percent);
  Forklift.setVelocity(100,percent);
  
  Drivetrain.driveFor(forward,72, inches);
  Forklift.spinFor(forward, 90, degrees);
  Intake.spin(forward);
  Drivetrain.turnFor(left, 180, degrees);
  Drivetrain.driveFor(forward, 72, inches);
  Forklift.spinFor(reverse, 90, degrees);
  Intake.stop();
  Drivetrain.turnFor(left, 180, degrees);
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    Brain.Screen.print("What's up?");

    Drivetrain.setDriveVelocity(100,percent);
    Intake.setVelocity(100,percent);
    MiddleWheel.setVelocity(100,percent);
    Forklift.setVelocity(100,percent);

    Intake.spin(forward); 

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  autonomous(); // I just added this in, it might make the autonomous part actually run

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
