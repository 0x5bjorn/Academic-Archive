#include <Servo.h>                        // Include the <Servo.h> libary, which is specifically designed
#include <SoftwareSerial.h>

const int leftPin = 9;
Servo servoL;
const int rightPin = 10;
Servo servoR;

SoftwareSerial mySerial(0, 1);

// Setup function
void setup() {       
  
  servoL.attach(leftPin);
  servoR.attach(rightPin);

  mySerial.begin(9600);
  Serial.begin(9600);                   
}

String readFromModule() {
  String msg = "";
  
  while(mySerial.available()) {
    int c = mySerial.read();
    msg += (char) c;
  }

  return msg;
}

// Main function (executed continuously)
void loop() {  
  
  String msg;
  msg = readFromModule();

  while (msg.length() > 0) {
    char m = msg.charAt(0);
    msg.remove(0, 1);

    Serial.println(m);
    
    if(m == 'U') {
      servoL.write(180);
      servoR.write(0);
    } else if (m == 'u') {
      servoL.write(90);
      servoR.write(90);
    } else if( m == 'D') {
      servoL.write(0);
      servoR.write(180);
    } else if (m == 'd') {
      servoL.write(90);
      servoR.write(90);
    } else if( m == 'R') {
      servoL.write(180);
      servoR.write(180);
    } else if (m == 'r') {
      servoL.write(90);
      servoR.write(90);
    } else if( m == 'L') {
      servoL.write(0);
      servoR.write(0);
    } else if (m == 'l') {
      servoL.write(90);
      servoR.write(90);
    } else if (m == 'M') {
      
    } else if (m == 'm') {

    } else {
      servoL.write(90);
      servoR.write(90);
    }
  }
}
