#include <Servo.h>                        // Include the <Servo.h> libary, which is specifically designed
                                          // to control servos
 
int servoPin = 5;                         // Servo pin number
Servo servo;                              // Define a special kind of abstract object of type "Servo"
                                          // This allows us to control the servo using the functions in the
                                          // <Servo.h> library
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;

int degree = 0;

// Setup function
void setup() {         
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input                        
  servo.attach(servoPin);                 // Attach the servo to the servoPin
  Serial.begin(9600); // Starts the serial communication
}

// Main function (executed continuously)
void loop() {                 
  digitalWrite(trigPin, LOW);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
                 
  duration = pulseIn(echoPin, HIGH);
// Calculating the distance
  distance= duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);


  if (distance >= 0 && distance <= 10) {
    if (degree > 0) {
      degree -= 2;
      servo.write(degree);
    }                      
  } else if (distance > 10 && distance <= 20) {
    if (degree < 90) {
      degree += 2;
      servo.write(degree);
    }
    if (degree > 90) {
      degree -= 2;
      servo.write(degree);
    }
  } else if (distance > 20) {
    if (degree < 180) {
      degree += 2;
      servo.write(degree);
    }                         
  }
  
  Serial.println(degree);


}
