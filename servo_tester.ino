/* 
 *  Lil Self-Driving Car Action
 *  
 *  -> myservo.write(position) to move the wheels
 */

#include <Servo.h>
#include <AFMotor.h>

/**************** VALUES TO CHANGE *************/
/** POSITIONS **/
const int MAX_LEFT = 60;
const int MAX_RIGHT = 110;
const int CENTER = 80;

/** TIMES **/
const int TIME_COMPLETE = 3000;
const int TIMEA = 5000;
/************************************************/

/* Servo */
const int pin = 9;    // servo pin position

/* Motor */
int motorSpeed = 255; // motor speed (0 - 255)

/* Sevo and Motor Objects */
Servo myservo;
AF_DCMotor motor(1, MOTOR12_64KHZ);

void setup() {
  myservo.attach(pin);  
  
  Serial.begin(9600); // 9600 baud

  motor.setSpeed(motorSpeed);

  /* center wheels */
  myservo.write(CENTER);
}

void loop() {

  /* wait 1 second */
  delay(1000);
  
  motor.run(FORWARD);

  delay(TIMEA);
  
  turnRight(CENTER, MAX_RIGHT);

  delay(TIMEA);

  turnLeft(MAX_RIGHT, CENTER);
  
  motor.run(RELEASE);

  while(true) { /* KILL */ }
  
}


void turnRight(int p, int f) {
  for(int i = p; i <= f; i++) {
    myservo.write(i);
    delay(50);
  }
}

void turnLeft(int p, int f) {
  for(int i = p; i >= f; i--) {
    myservo.write(i);
    delay(50);
  }
}

