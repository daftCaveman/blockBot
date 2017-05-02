
//Libraries 
#include <Servo.h>

//Global constant and variable declaration
//These constants are setting the port addresses on the Arduino for ping sensors
const int L_pingPin = 4;
const int mainPingEchoPin = 12;
const int mainPingTrigPin = 13;
const int rightPingEchoPin = 7;
const int rightPingTrigPin = 8;

//declaring servo names 
Servo L_SERVO;
Servo R_SERVO;

//Setup function to set inputs, outputs, and pin ports
void setup()
{
  L_SERVO.attach(5);
  R_SERVO.attach(6);
  Serial.begin(9600);  //Start serial monitor to print values from inputs
}

//** Main loop function **
void loop ()
{
    positionCheck();
    
}//** end Main loop function **

//********sensor functions**********
void positionCheck()
{
    mainPing();
    rightPing(); 
    leftPing();   
}

//Function using main ping sensor   to determine distance
void mainPing()
{
    //Variables needed for main ping to determine distance
    long duration;
    int distance;
    
    //declaring utility
    pinMode(mainPingTrigPin, OUTPUT);
    pinMode(mainPingEchoPin, INPUT);
  
    //Clears the trigPin
    digitalWrite(mainPingTrigPin, LOW);
    delayMicroseconds(2);

    //Sets the trigPin on HIGH state for 10 microseconds
    digitalWrite(mainPingTrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(mainPingTrigPin, LOW);

    //Reads the echoPin, returns the sound wave travel in microseconds
    duration = pulseIn(mainPingEchoPin, HIGH);

    //calculating distance
    distance = duration * 0.034/2;

    //output distance
    Serial.print("Main ping: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(100);
}//end mainPing function

//Function will use the left ping sensor to determine distance
void leftPing()
{
  //variable declaration
  long duration, cm;//**add inches if using inch standard measure

  //the PING))) is triggered by a HIGH pulse of 2 or more microseconds.  Give a short LOW pulse beforehand to ensure a clean HIGH pulse.
  pinMode(L_pingPin, OUTPUT);
  digitalWrite(L_pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(L_pingPin, HIGH);
  delayMicroseconds(5);  
  digitalWrite(L_pingPin, LOW);

  //The same pin is used to read the signal from the PING))): a HIGH pulse whose duration is the time (in microseconds) from the sending of the ping to the reception of its echo off of an object.
  pinMode(L_pingPin, INPUT);
  duration = pulseIn(L_pingPin, HIGH);

  /*//convert the time into distance
  inches = microsecondsToInches(duration);
  */
  cm = microsecondsToCentimeters(duration);

  //output data
  Serial.print("Left Ping = ");
  /*Serial.print(inches);
  Serial.print("in, ");
  */
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}//end leftPing function

//Function will use the right 4 wire ping sensor to determine distance
void rightPing()
{
  //Variables needed for main ping to determine distance
    long duration;
    int distance;
    
    //declaring utility
    pinMode(rightPingTrigPin, OUTPUT);
    pinMode(rightPingEchoPin, INPUT);
  
    //Clears the trigPin
    digitalWrite(rightPingTrigPin, LOW);
    delayMicroseconds(2);

    //Sets the trigPin on HIGH state for 10 microseconds
    digitalWrite(rightPingTrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(rightPingTrigPin, LOW);

    //Reads the echoPin, returns the sound wave travel in microseconds
    duration = pulseIn(rightPingEchoPin, HIGH);

    //calculating distance
    distance = duration * 0.034/2;

    //output distance
    Serial.print("Right ping: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(100);
    
}//end rightPing function


//Distance conversion for inches
long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

//Distance conversion for centimeters
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}


//********Movement Functions*******
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


