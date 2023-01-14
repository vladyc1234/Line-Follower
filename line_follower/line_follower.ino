#include <QTRSensors.h>

const int m11Pin = 7;

const int m12Pin = 6;

const int m21Pin = 5;

const int m22Pin = 4;

const int m1Enable = 11;

const int m2Enable = 10;



int m1Speed = 0;

int m2Speed = 0;



// increase kp’s value and see what happens

float kp = 1;

float ki = 0.001;

float kd = 0;



int p = 1;

int i = 0;

int d = 0;



int error = 0;

int lastError = 0;

int step = 0;



int maxSpeed = 255;

int minSpeed = -200;


const int baseSpeed = 255;



QTRSensors qtr;



const int sensorCount = 6;

int sensorValues[sensorCount];

int sensors[sensorCount] = {0, 0, 0, 0, 0, 0};



void setup() {



  // pinMode setup

  pinMode(m11Pin, OUTPUT);

  pinMode(m12Pin, OUTPUT);

  pinMode(m21Pin, OUTPUT);

  pinMode(m22Pin, OUTPUT);

  pinMode(m1Enable, OUTPUT);

  pinMode(m2Enable, OUTPUT);


  Serial.begin(9600);


  qtr.setTypeAnalog();

  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, sensorCount);

  delay(500);

  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

  // calibrate the sensor. For maximum grade the line follower should do the movement itself, without human interaction.

  int ok = 0,state = 1;
  int speed = 200;
  while (ok < 10)
  {
    qtr.calibrate();
    qtr.read(sensorValues);
    if (state == 1)
    {
      if (sensorValues[0] < 700)
      {
        setMotorSpeed(speed,-1*speed);
      }
      else
      {
        state = 2;
      }
    }
    if (state == 2)
    {
      if (sensorValues[5] < 700)
      {
        setMotorSpeed(-1*speed,speed);
      }
      else
      {
        state =  1;
        ok++;
      }
    }
  }

  digitalWrite(LED_BUILTIN, LOW);
}


void loop() {

  pidControl();

  m1Speed = constrain(m1Speed, minSpeed, maxSpeed);

  m2Speed = constrain(m2Speed, minSpeed, maxSpeed);

  setMotorSpeed(m1Speed, m2Speed);
}

void pidControl() {

  int error = map(qtr.readLineBlack(sensorValues), 0, 5000, -30, 30);

  p = error;
  i = i + error;
  d = error - lastError;
  
  if ( error > -6 && error < 6)
  {
    kp = 5;
    kd = 16;
    ki = 0.01;
    maxSpeed = 250;
    minSpeed = -150;
  }
  if ((error < -5 && error > -11) || (error > 5 && error < 11))
  {
    kp = 13;
    kd = 18;
    ki = 0.01;
    minSpeed = -170;
    maxSpeed = 230;
  }
  if ((error < -10 && error > -21) || (error > 10 && error < 21))
  {
    kp = 17;
    kd = 20;
    ki = 0.01;
    maxSpeed = 225;
    minSpeed = -210;
  }
  if (error < -20 || error > 20)
  {
    kp = 20;
    kd = 24;
    ki = 0.01;
    maxSpeed = 215;
    minSpeed = -245;
  }

  int motorSpeed = kp * p + ki * i + kd * d; // = error in this case

  m1Speed = baseSpeed;

  m2Speed = baseSpeed;

  if (error < 0) {

    m1Speed += motorSpeed;

  }

  else if (error > 0) {

    m2Speed -= motorSpeed;

  }

  step++;

  if(step == 2)
  {
    lastError = error;
    step = 0;
  }

}



// each arguments takes values between -255 and 255. The negative valuesrepresent the motor speed in reverse.

void setMotorSpeed(int motor1Speed, int motor2Speed) {

  // remove comment if any of the motors are going in reverse

  // motor1Speed = -motor1Speed;

  // motor2Speed = -motor2Speed;

  if (motor1Speed == 0) {

    digitalWrite(m11Pin, LOW);

    digitalWrite(m12Pin, LOW);

    analogWrite(m1Enable, motor1Speed);

  }

  else {

    if (motor1Speed > 0) {

      digitalWrite(m11Pin, HIGH);

      digitalWrite(m12Pin, LOW);

      analogWrite(m1Enable, motor1Speed);

    }

    if (motor1Speed < 0) {

      digitalWrite(m11Pin, LOW);

      digitalWrite(m12Pin, HIGH);

      analogWrite(m1Enable, -motor1Speed);

    }

  }

  if (motor2Speed == 0) {

    digitalWrite(m21Pin, LOW);

    digitalWrite(m22Pin, LOW);

    analogWrite(m2Enable, motor2Speed);

  }

  else {

    if (motor2Speed > 0) {

      digitalWrite(m21Pin, HIGH);

      digitalWrite(m22Pin, LOW);

      analogWrite(m2Enable, motor2Speed);

    }

    if (motor2Speed < 0) {

      digitalWrite(m21Pin, LOW);

      digitalWrite(m22Pin, HIGH);

      analogWrite(m2Enable, -motor2Speed);

    }

  }

}