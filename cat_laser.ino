// Guide: https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/
// http://www.arduinotutorialonline.com/2017/12/how-to-use-dc-motor-with-arduino-nano.html

// Motor Constants
int motor1_ena = 3;
int motor1_in1 = 4;
int motor1_in2 = 5;
bool swapped = false;
int randomVal = 3000;
int motorSpeed = 100;

// Laser Constants
int laserPin = 10;

// Button Constants
int buttonInPin = 7; // pushbutton input pin
int buttonVal = 0; // variable for reading the pin status

int runTime = 600000;

void setup() {
  Serial.begin(9600);
  pinMode(motor1_ena, OUTPUT);
  pinMode(motor1_in1, OUTPUT);
  pinMode(motor1_in2, OUTPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(buttonInPin, INPUT);

  digitalWrite(motor1_in1, HIGH);
  digitalWrite(motor1_in2, LOW);

  analogWrite(motor1_ena, motorSpeed);
  laserON();
}

void loop() {
  // cycle start
  if(buttonPressed()) {
    //do standard loop function for 15 minutes
    standardLoopFunction();
    Serial.println("button pressed");
  }
  // cycle end
}

void standardLoopFunction() {
  int loopLength = 900000;
  long starttime = millis();
  long endtime = starttime;

  while((endtime - starttime) <= loopLength) {
    endtime = millis();
    randomVal = random(500, 3000);
    movement();
    delay(randomVal);  
  }  
}

bool buttonPressed() {
  buttonVal = digitalRead(buttonInPin);
  return buttonVal == LOW;
}

void movement() {
  swapMotors();
  if (randomVal < 1500) {
    stopMotor();
  } else {
    restartMotor();
  }  
}

void stopMotor() {
  analogWrite(motor1_ena, 0);  
}

void restartMotor() {
  analogWrite(motor1_ena, motorSpeed);  
}

void swapMotors() {
  if (swapped) {
    digitalWrite(motor1_in1, HIGH);
    digitalWrite(motor1_in2, LOW);  
  } else {
    digitalWrite(motor1_in1, LOW);
    digitalWrite(motor1_in2, HIGH);  
  }
  swapped = !swapped;
}

void laserON() {
  digitalWrite(laserPin, HIGH);    
}

void laserOFF() {
  digitalWrite(laserPin, LOW);  
}
