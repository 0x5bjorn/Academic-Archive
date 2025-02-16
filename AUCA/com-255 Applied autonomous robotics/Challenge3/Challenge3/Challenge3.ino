#include <Servo.h>

#include <Ethernet.h>

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

const int sensorPin1 = A0;
const int sensorPin2 = A1;

int sensorReading1 = 0;
int sensorReading2 = 0;

long duration;
int distance;

int maxSensor = 0;
int dist1 = 0;
int dist2 = 0;
int degree = 90;
int n = 2;

int count = 0;
int r = 0;

void setup() {
  servoL.attach(leftPin);
  servoR.attach(rightPin);

  leverL.attach(leftLeverPin);
  leverR.attach(rightLeverPin);
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600);

  servoL.writeMicroseconds(1460);
  servoR.writeMicroseconds(1440);
  leverR.write(90);
}

void loop () {  

//  Serial.println("Starting loop");
  
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
//  Serial.print("Distance: ");
//  Serial.println(distance);

  if (sensorReading1 > maxSensor) {
    maxSensor = sensorReading1;
    r = random(0, 2);
  }
  
  sensorReading1 = analogRead(sensorPin1);
  sensorReading2 = analogRead(sensorPin2);

  Serial.print("Sensor1: ");
  Serial.println(sensorReading1);
  Serial.print("Sensor2: ");
  Serial.println(sensorReading2);
  Serial.print("Max: ");
  Serial.println(maxSensor);
   
  if (distance > 20) {
    if (sensorReading1 >= sensorReading2) {
      if (sensorReading1+20 > maxSensor && sensorReading1-20 < maxSensor) {
        servoL.write(180);
        servoR.write(0);
        delay(500);
        count = 0;
      } else {
        if (r == 0) {
          servoL.write(0);
          servoR.write(0);
        } else {
          servoL.write(180);
          servoR.write(180);   
        }
  
        if (count == 0) {
          maxSensor -= 150;
          count = 1;
        }
      }
    } else {
      if (r == 0) {
        servoL.write(0);
        servoR.write(0);
      } else {
        servoL.write(180);
        servoR.write(180);   
      }
      delay(500);

      maxSensor = 0;
      if (sensorReading2 > maxSensor) {
        maxSensor = sensorReading1;
        r = random(0, 2);
      }
    }
    
  } else {                            // obstacle detected
    Serial.println(distance);

    // machine freezes
    servoL.writeMicroseconds(1460);
    servoR.writeMicroseconds(1440);
    
    // distance sensor checks right side to see if there is obstacles
    leverR.write(0);
    delay(500);
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin, HIGH);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    dist1 = distance;
    delay(700);
    
    leverR.write(180);
    delay(500);
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin, HIGH);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    dist2 = distance;
    delay(700);

    Serial.println(dist1);
    Serial.println(dist2);

    leverR.write(90);

    if (dist1 > dist2) {
      Serial.println("Right");
      servoL.write(180);
      servoR.write(180);
      delay(500);
    } else {
      servoL.write(0);
      servoR.write(0);
      delay(500);
    }

    servoL.write(180);
    servoR.write(0);
    delay(1500);

    maxSensor = 0;
  }
  
//  Serial.print("Sensor reading = ");        // Print this text in the Serial Monitor
//  Serial.print(sensorReading);              // Print the sensor reading, followed by a newline character
//  Serial.print(", ");
//  Serial.println(1023 - sensorReading);
//  Serial.print("Max sensor: ");
//  Serial.println(maxSensor);
}
