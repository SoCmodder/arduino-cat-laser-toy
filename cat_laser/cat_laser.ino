// Guide: https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/
// http://www.arduinotutorialonline.com/2017/12/how-to-use-dc-motor-with-arduino-nano.html

// Motor Constants
int motor1_ena = 3;
int motor1_in1 = 4;
int motor1_in2 = 5;

int motorSpeed = 60;

// Laser Constants
int laserPin = 10;

bool motorDirection = true;

void setup() {
  Serial.begin(9600);
  pinMode(motor1_ena, OUTPUT);
  pinMode(motor1_in1, OUTPUT);
  pinMode(motor1_in2, OUTPUT);
  pinMode(laserPin, OUTPUT);

  analogWrite(motor1_ena, motorSpeed);

  motorForward();

  laserON();
}

void loop() {
  if (motorDirection) {
    motorForward(); 
  } else {
    motorReverse();
  }

  motorDirection = !motorDirection;
  int randomVal = random(2000, 8000);
  delay(randomVal);
}

void motorForward() {
  digitalWrite(motor1_in1, LOW);
  digitalWrite(motor1_in2, HIGH);  
}

void motorReverse() {
  digitalWrite(motor1_in1, HIGH);
  digitalWrite(motor1_in2, LOW);   
}

void laserON() {
  digitalWrite(laserPin, HIGH);    
}

void laserOFF() {
  digitalWrite(laserPin, LOW);  
}
