#include <Arduino.h>
// Libraries used: AccelStepper library for controlling stepper motors.
// Project description: This code is designed to control a stepper motor at a sidereal rate, which is approximately 1.1605e-5 revolutions per second.
// The motor is geared down by a factor of 10, and the code calculates the necessary steps per second to achieve this rate.
// The stepper motor is controlled using the AccelStepper library, which allows for smooth acceleration and deceleration.
// The code sets up the motor to run at a constant speed corresponding to the sidereal rate.
// The motor is connected to pins 2 and 3 of the Arduino board, which are used for direction and step control respectively.
// The code runs in a loop, continuously moving the motor at the calculated sidereal rate.
// The motor is expected to rotate at a rate that matches the sidereal day, which is approximately 86164.091 seconds.
// This code is suitable for applications such as astronomical tracking, where precise movement of the motor is required to follow celestial objects.
// The code is structured to be efficient and straightforward, focusing on the essential functionality needed for sidereal tracking.


// Include config file for pin assignments and other configurations
#include <config.h>
// Include the AccelStepper library for controlling stepper motors
#include <AccelStepper.h>

// 1 rev / 86,164.091 sec ≈ 0.000011605 RPS
const float siderealRate = 1.1605e-5;


AccelStepper stepper(MOTOR_INTERFACE_TYPE, STEP_PIN, DIR_PIN);

void serialSetup() {
  Serial.begin(SERIAL_BAUDRATE);

  Serial.println("Serial connection established.");
}

void setup() {
  // put your setup code here, to run once:
  stepper.setMaxSpeed(round(SIDEREAL_STEPS_PER_SEC)); // max steps/sec
  stepper.setSpeed(-SIDEREAL_STEPS_PER_SEC); // negative for counterclockwise rotation

  serialSetup();
  Serial.println("Star Tracker RA Motor Control Initialized.");

  Serial.print("setMaxSpeed: ");
  Serial.println(round(SIDEREAL_STEPS_PER_SEC));
  Serial.print("setSpeed: ");
  Serial.println(-SIDEREAL_STEPS_PER_SEC);
  Serial.print("Total steps per motor revolution: ");
  Serial.println(MOTOR_STEPS_PER_REV);
  Serial.print("Total microsteps per motor revolution: ");
  Serial.println(MOTOR_STEPS_PER_REV * MOTOR_DRIVER_MICROSTEPS);
  Serial.print("Total steps per gear box revolution: ");
  Serial.println(MOTOR_TOTAL_STEPS_PER_REV);


  // Uncomment the line below if you want to wait for a second before starting
  // This can be useful for debugging or ensuring everything is set up correctly
  delay(1000); // Wait for a second before starting
}


void loop() {
  // put your main code here, to run repeatedly:

  // Move counterclockwise at sidereal rate
  stepper.runSpeed(); // run at constant speed
  // The runSpeed() function will keep the motor moving at the set speed
  // It does not block, allowing other code to run if needed


}
