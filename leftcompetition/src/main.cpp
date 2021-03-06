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
// Forklift             motor_group   4, 5            
// MiddleWheel          motor         9               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

int upposition = 130;
int downposition = 835;
int downchange = downposition-upposition;
int up = false;
int down = false;
int intakestate = 0;
 
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
  Forklift.setPosition(0,degrees);

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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
  Drivetrain.setDriveVelocity(100,percent); 
  Intake.setVelocity(100,percent);
  MiddleWheel.setVelocity(100,percent);
  Forklift.setVelocity(100,percent); 
 
  Brain.Screen.print("Start Autonomous");
  Forklift.spinFor(forward,downposition,degrees);
  Drivetrain.driveFor(forward,1410,mm);
  Forklift.spinFor(reverse,downchange,degrees);
  Drivetrain.driveFor(reverse,1210, mm);
  // ..........................................................................
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

    if(Controller1.ButtonL1.pressing()) {
      if(up == false) {
        if(Forklift.rotation(deg) > downchange && Forklift.rotation(deg) > 70 && up == false) {
          Forklift.spinFor(reverse,downchange,degrees);
          up = true;
          wait(1,sec);
          up = false;
        }
      }
    }

    if(Controller1.ButtonL2.pressing()){
      if(down == false) {
        if(Forklift.rotation(deg) < downchange && down == false) {
          Forklift.spinFor(forward,downchange,degrees);
          down = true;
          wait(1,sec);
          down = false;
        }
      }
    }

    Brain.Screen.print("Driver in Control"); // Replaced code w/ the controller menu being set-up
 

    // ........................................................................

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

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
