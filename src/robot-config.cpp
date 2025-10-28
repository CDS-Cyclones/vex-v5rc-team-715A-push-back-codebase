#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;


const distanceUnits DISTANCE_UNITS = mm;

const gearSetting DRIVETRAIN_MOTOR_GEAR_RATIO = ratio18_1;
const double WHEEL_CIRCUMFERENCE = 3.25 * atan(1) * 4;
const double TRACKWIDTH = 292.1;
const double INTERNAL_GEAR_RATIO = 1;
const double WHEELBASE = 40;


// Misc. device declarations
controller Controller = controller();
optical Optical = optical(PORT3);
inertial InertialSensor = inertial(PORT20);


//Right side declarations
const int32_t FRONT_RIGHT_MOTOR_PORT = PORT12;
const int32_t BACK_RIGHT_MOTOR_PORT = PORT11;
const bool FRONT_RIGHT_MOTOR_REVERSED = false;
const bool BACK_RIGHT_MOTOR_REVERSED = false;
motor FrontRightMotor = motor( FRONT_RIGHT_MOTOR_PORT, FRONT_RIGHT_MOTOR_REVERSED );
motor BackRightMotor = motor( BACK_RIGHT_MOTOR_PORT, BACK_RIGHT_MOTOR_REVERSED );
motor_group RightDriveSmart = motor_group( FrontRightMotor, BackRightMotor );

//Left side declarations
const int32_t FRONT_LEFT_MOTOR_PORT = PORT8;
const int32_t BACK_LEFT_MOTOR_PORT = PORT14;
const bool FRONT_LEFT_MOTOR_REVERSED = false;
const bool BACK_LEFT_MOTOR_REVERSED = false;
motor FrontLeftMotor = motor( FRONT_LEFT_MOTOR_PORT, FRONT_LEFT_MOTOR_REVERSED );
motor BackLeftMotor = motor( BACK_LEFT_MOTOR_PORT, BACK_LEFT_MOTOR_REVERSED );
motor_group LeftDriveSmart = motor_group( FrontLeftMotor, BackLeftMotor );

// Elevator Motor Definitions
const int32_t ELEVATOR_MOTOR_PORT = PORT13;
const int32_t ELEVATOR_MOTOR_2_PORT = PORT7;
const bool ELEVATOR_MOTOR_REVERSED = false;
const bool ELEVATOR_MOTOR_2_REVERSED = false;
motor ElevatorMotor = motor( ELEVATOR_MOTOR_PORT, ELEVATOR_MOTOR_REVERSED );
motor ElevatorMotor2 = motor( ELEVATOR_MOTOR_2_PORT, ELEVATOR_MOTOR_2_REVERSED );
motor_group ElevatorMotorGroup = motor_group( ElevatorMotor, ElevatorMotor2 );

// Intake motor Definitions
const int32_t INTAKE_MOTOR_PORT = PORT2;
const int32_t INTAKE_MOTOR_2_PORT = PORT4;
const bool INTAKE_MOTOR_REVERSED = true;
const bool INTAKE_MOTOR_2_REVERSED = false;
motor IntakeMotor = motor( INTAKE_MOTOR_PORT, INTAKE_MOTOR_REVERSED );
motor IntakeMotor2 = motor( INTAKE_MOTOR_2_PORT, INTAKE_MOTOR_2_REVERSED );
motor_group IntakeMotorGroup = motor_group( IntakeMotor, IntakeMotor2 );

drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, WHEEL_CIRCUMFERENCE, TRACKWIDTH, WHEELBASE, DISTANCE_UNITS, INTERNAL_GEAR_RATIO);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}