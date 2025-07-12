#ifndef CONFIG_H
#define CONFIG_H

// Pin assignments
#define STEP_PIN        3
#define DIR_PIN         2

// Stepper motor parameters
#define MOTOR_INTERFACE_TYPE        AccelStepper::DRIVER // Use DRIVER interface for stepper motor
#define MOTOR_STEP_ANGLE_DEGREES    1.8 // Step angle in degrees
#define MOTOR_STEPS_PER_REV         (360 / MOTOR_STEP_ANGLE_DEGREES) // Steps per revolution for the motor
#define MOTOR_DRIVER_MICROSTEPS     8 // Microstepping factor for the motor driver (default 1/8 microstepping)
#define MOTOR_EXTERNAL_GEAR_RATIO   100 // External gear ratio (planetary gearbox 1:100)
#define MOTOR_TOTAL_STEPS_PER_REV \
    (MOTOR_STEPS_PER_REV * MOTOR_DRIVER_MICROSTEPS * MOTOR_EXTERNAL_GEAR_RATIO)

// Tracking parameters
#define SIDEREAL_DAY_IN_SECONDS     86164.0905 // Sidereal day in seconds
#define SIDEREAL_STEPS_PER_SEC \
    (MOTOR_TOTAL_STEPS_PER_REV / SIDEREAL_DAY_IN_SECONDS) // Steps per second for sidereal tracking


// Other configuration
#define SERIAL_BAUDRATE             9600

#endif // CONFIG_H
