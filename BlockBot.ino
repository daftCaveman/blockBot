/*  Hartnell College Robotics Club Project
 *  BlockBot -- Started 1/7/17 -- In Progress
 *  
 *  This program is for a robot that will be able to navigate an 
 *  enclosed circular area about 12 feet in diameter, detect the 
 *  movement patterns of a big swinging pendulum about 1 1/2 feet 
 *  in diameter to avoid collision, and re-set 3 inch tall cylindrical
 *  blocks that are knocked over by the pendulum. After available blocks
 *  are picked up, BlockBot will go into sleep mode for charging, until
 *  the pendulum is at a different orientation.  Then the remaining
 *  blocks will be picked up.
 *  
 *  equipment:  (** =>  means needed)
 *  1 Arduino uno microcontroller
 *  1 Parallax shield with breadboard as test platform
 *  1 Osepp Sensor Shield to handle amount of servos/sensors
 *  3 ultrasonic sensors for navigation
 *  2 servos for movement
 *  4 servos for gripper manipulation
 *  **2 infrared sensors needed to detect block orientation 
 *  **1 infrared sensor to detect movement of pendulum
 *  5 'AA' batteries for power
 *  **2 2 watt solar panels for re-charging batteries
 *  
 *  Phases of construction:
 *  -Navigation - robot needs to be able to move in at least one
 *    complete circle, staying equidistant between blocks and wall
 *    using sensors.
 *  -Re-setting Blocks - Sensors will determine downed block orientation
 *    and spin gripper in order to pick up block and re-set the block
 *    so it is standing.
 *  -Charging Power - After determining orientation of pendulum the robot
 *    will pick up blocks on either side of its path.  After doing so,
 *    the robot will determine the brightest location and go into sleep mode
 *    for at least 4 hours for charging.  After 4 hours, the robot will 
 *    become active again and survey the pendulum orientation.  By then, the
 *    other blocks that were knocked down can be picked up
 */

//Libraries 
#include <Servo.h>

//Global constant and variable declaration
//These constants are setting the port addresses on the Arduino for ultrasonic sensor
const int trigPin = 13;
const int echoPin = 12;

//Needed for determining distance from ultrasonic sensors
long duration;
int distance = 30;

//declaring servo names
Servo L_SERVO;
Servo R_SERVO;

//Setup function to set inputs, outputs, and pin ports
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  L_SERVO.attach(5);
  R_SERVO.attach(6);
  Serial.begin(9600);  //Start serial monitor to print values from inputs
}

//Main loop function that repeats until powered down
void loop ()
{
  while (distance >= 30)
  {
    //Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    //Sets the trigPin on HIGH state for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Reads the echoPin, returns the sound wave travel in microseconds
    duration = pulseIn(echoPin, HIGH);

    //calculating distance
    distance = duration * 0.034/2;

    //output distance
    Serial.print("Distance: ");
    Serial.println(distance);
    
    forward();
    delay(2000);
  }
  if (distance < 31)
  {
    reverse();
    delay(2000); 
    turnRight();
    delay(2000);
  }
  distance = 30;
    //turnLeft();
    //delay(2000);
    //stopRobot();  
    //delay(2000);
    
}//end Main loop function

//Function will move robot forward by spinning drive wheels in two different directions
//because of setup of the 2 servos
void forward()
{
  L_SERVO.write(0);
  R_SERVO.write(180);
}

//Function will move robot backward by spinning the servos opposite the 'forward' function
void reverse()
{
  L_SERVO.write(180);
  R_SERVO.write(0);
}

//Function will rotate the robot towards the right 
void turnRight()
{
  L_SERVO.write(180);
  R_SERVO.write(180);
}

//Function will rotate the robot towards the left
void turnLeft()
{
  L_SERVO.write(0);
  R_SERVO.write(0);
}

//Function will stop the robot from moving
void stopRobot()
{
  L_SERVO.write(90);
  R_SERVO.write(90);
}

/*---------------------------------------------------
//Servo sensorServo;
Servo myservo1;
Servo myservo2;

int pos = 0;    // variable to store the servo position

int L_ENCODER = 0;   //for checking left servo wheel rotation
int R_ENCODER = 0;   //for checking right servo wheel rotation

int leftEncoderVal = 0;
int rightEncoderVal = 0;
//const int pingPin = 7;

void setup() {
  Serial.begin(9600);
  myservo1.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(6); 
  //sensorServo.attach(10);
}

void loop() {
//  long duration, inches, cm;
  
  
  leftEncoderVal = analogRead(L_ENCODER);
  rightEncoderVal = analogRead(R_ENCODER);
  Serial.println(L_ENCODER);
  Serial.println(R_ENCODER);
  delay(100);
/*
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);               // tell servo to go to position in variable 'pos'
    myservo2.write(pos);                // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos >= 180; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);               // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  } 
  
}//end loop function
*/
