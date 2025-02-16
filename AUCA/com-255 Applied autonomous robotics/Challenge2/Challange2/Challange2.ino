#include <Servo.h>                        // Include the <Servo.h> libary, which is specifically designed
#include <SoftwareSerial.h>

const int leftPin = 9;
Servo servoL;
const int rightPin = 10;
Servo servoR;

const int leftLeverPin = 5;
Servo leverL;
const int rightLeverPin = 6;
Servo leverR;

const int trigPin = A4;
const int echoPin = A5;

long duration;
int distance;

int degree = 90;
int n = 2;

void setup() {
  delay(5000);
  servoL.attach(leftPin);
  servoR.attach(rightPin);

  leverL.attach(leftLeverPin);
  leverR.attach(rightLeverPin);
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600);
}

void loop () {  
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance <= 70) {
    servoL.write(180);
    servoR.write(0);
  } else {
    servoL.write(0);
    servoR.write(0);

    degree+=n;
    leverL.write(degree);
    
    if (degree > 180 || degree < 90) {
      n *= -1;
    }
  }
}
