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

int potPin = 0;
int switchPin = 7;

int enablePin = 8;
int in2Pin = 9;
int in1Pin = 10;
int pwm1Pin = 11;

void setup() {

 Serial.begin(115200);
 Serial.println("HelloMotor");

  pinMode(enablePin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);

  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(pwm1Pin, OUTPUT);

  digitalWrite(enablePin, 1);

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
  analogWrite(pwm1Pin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}

