/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Team 1526D - BHS HexaDecimators                           */
/*    Created:      Monday, December 13, 2021                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 3            
// Forklift             motor_group   4, 5            
// Intake               motor         7               
// MiddleWheel          motor         9               
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
 
// PRE-AUTONOMOUS CODE
void pre_auton(void) {
  vexcodeInit();
  Forklift.setPosition(0,degrees);
}
 
void autodrive(void) {
  // Autonomous Code
  // Plan: Drop Forklift Down, Go to Goal, Pick Up Goal, Turn, Spin Intake, Pick up Rings
 
  Drivetrain.setDriveVelocity(100,percent); 
  Intake.setVelocity(100,percent);
  MiddleWheel.setVelocity(100,percent);
  Forklift.setVelocity(100,percent); 
 
  Brain.Screen.print("Start Autonomous");
  Forklift.spinFor(forward,downposition,degrees);
  Drivetrain.driveFor(forward,1400,mm);
  Forklift.spinFor(reverse,downchange,degrees);
  Drivetrain.turnFor(right, 90, degrees);
  Intake.spin(reverse);
  Drivetrain.driveFor(reverse,2000, mm);
  Intake.stop();
}
 
void fldown(void) {
  if(Forklift.rotation(deg) < downchange && down == false) {
    Forklift.spinFor(forward,downchange,degrees);
    down = true;
    wait(1,sec);
    down = false;
  }
}
 
void flup(void) {
  if(Forklift.rotation(deg) > downchange && Forklift.rotation(deg) > 70 && up == false) {
    Forklift.spinFor(reverse,downchange,degrees);
    up = true;
    wait(1,sec);
    up = false;
  }
}
 
 void usercontrol(void) {
  while (1) {
 
    Brain.Screen.print("Driver in Control"); // Replaced code w/ the controller menu being set-up
 
    if(up == false) {
      Controller1.ButtonL1.pressed(flup);
    }
    if(down == false) {
      Controller1.ButtonL2.pressed(fldown);
    }

 
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