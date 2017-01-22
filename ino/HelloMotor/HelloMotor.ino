/*
 * HelloMotor
 *
 * Adafruit Arduino - Lesson 15. Bi-directional Motor
 *
 * Test rig setup:
 * A0  - input from potentiometer or other input scale device
 * D7  - fwd / rev
 * D8  - Motor A - PWM speed control (PWMA)
 * D9  - Motor A - control 2 (AIN2)
 * D10 - Motor A - control 1 (AIN1)
 * D11 - enable
 */

// Set motor configuration and initial conditions

int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int pwm1Pin = 8;
int switchPin = 7;
int potPin = 0;

void setup() {

 Serial.begin(115200);
 Serial.println("HelloMotor");

  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop()
{
  int speed = analogRead(potPin) / 4;
  boolean reverse = digitalRead(switchPin);
  setMotor(speed, reverse);
  Serial.print("speed: ");
  Serial.print(speed);
  Serial.print(", reverse: ");
  Serial.print(reverse);
  Serial.println("");
}

void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}
