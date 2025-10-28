using namespace vex;

extern brain Brain;
extern motor FrontRightMotor;
extern motor BackRightMotor;
extern motor_group RightDriveSmart;
extern motor FrontLeftMotor;
extern motor BackLeftMotor;
extern motor_group LeftDriveSmart;
extern drivetrain Drivetrain;
extern controller Controller;

extern motor ElevatorMotor;
extern motor ElevatorMotor2;
extern motor_group ElevatorMotorGroup;
extern motor IntakeMotor;
extern motor IntakeMotor2;
extern motor_group IntakeMotorGroup;

extern optical Optical;
extern inertial InertialSensor; 
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);