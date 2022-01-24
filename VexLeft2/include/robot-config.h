using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern motor_group Forklift;
extern motor Intake;
extern motor MiddleWheel;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );