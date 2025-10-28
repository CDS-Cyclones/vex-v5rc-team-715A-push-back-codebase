/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
bool blueDetected = false;
bool redDetected = false;
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
  Brain.Screen.print("Calibrating Inertial...");
  InertialSensor.calibrate(2);
  BackLeftMotor.setBrake(brake);
  BackRightMotor.setBrake(brake);
  FrontLeftMotor.setBrake(brake);
  FrontRightMotor.setBrake(brake);
  LeftDriveSmart.setStopping(brake);
  RightDriveSmart.setStopping(brake);
  Brain.Screen.clearScreen();


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
      // Drivetrain.driveFor(300, mm);
      Drivetrain.setDriveVelocity(50, percentUnits::pct);
      Drivetrain.setTurnVelocity(50, percentUnits::pct);
      Drivetrain.turnFor(90, degrees);
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


    // Vision & Heading Display
    double hue = Optical.hue();
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(Optical.color());
  if(Optical.color() >= 16700000 && Optical.color() <= 16720000){
      Brain.Screen.setCursor(2,1);
      Brain.Screen.print("Red Detected");
      redDetected = true;
      blueDetected = false;
  }
  else if(Optical.color() == 255 || Optical.color() == 65535){
      Brain.Screen.setCursor(2,1);
      Brain.Screen.print("Blue Detected");
      blueDetected = true;
      redDetected = false;
  }
  else{
    redDetected = false;
    blueDetected = false;
  }
  Brain.Screen.setCursor(4,1);
  Brain.Screen.print("Heading: %.2f", InertialSensor.heading());
  wait(200,msec);

    Brain.Screen.clearScreen();

    // Drive & Control
    Drivetrain.arcade(Controller.Axis1.position(), Controller.Axis3.position());    
    if(Controller.ButtonR1.pressing()){
      IntakeMotorGroup.spin(forward, 100, percentUnits::pct);
    }
    else if(Controller.ButtonR2.pressing()){
      IntakeMotorGroup.spin(reverse, 100, percentUnits::pct);
    }
    else{
      IntakeMotorGroup.stop();
    }

    if(Controller.ButtonL1.pressing()){
      ElevatorMotorGroup.spin(forward, 100, percentUnits::pct);
    }
    else if(Controller.ButtonL2.pressing()){
      ElevatorMotorGroup.spin(reverse, 100, percentUnits::pct);
    }
    else{
      ElevatorMotorGroup.stop();
    }

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
