/*
 * HelloMotor
 *
 * The motor speed follows the position of a potentiometer
 * on analog input 0.
 *
 * Test rig setup:
 * A0 - input from potentiometer or other input scale device
 * D4 - Motor A - control 1 (AIN1)
 * D5 - Motor A - control 2 (AIN2)
 * D8 - Motor A - PWM speed control (PWMA)
 *
 */

// Set motor configuration and initial conditions



// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);
}

void loop() {
  // get the sensor value
  int val = analogRead(3);

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val - previous);

  // remember the previous value of the sensor
  previous = val;
}
