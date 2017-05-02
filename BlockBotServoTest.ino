//Libraries 
#include <Servo.h>

//Global constant and variable declaration
//These constants are setting the port addresses on the Arduino for ping sensors
Servo clawServo;

//*********Setup function to set inputs, outputs, and pin ports************
void setup()
{
  clawServo.attach(5);
  Serial.begin(9600);  //Start serial monitor to print values from inputs
  
}//end setup function

//****** Main loop function *******
void loop ()
{
    gripperTest();
    
    
}//******* end Main loop function ****************************************************


//**********Arm Movement Functions********
//This function will call the openGripper and closeGripper functions
void gripperTest()
{
  openGripper();
  closeGripper();

}//end gripperTest function

//This function will test the servo that rotates the gripper
void wristTest()
{
  Wrist_SERVO.write(45);
  delay(1000);
  Wrist_SERVO.write(135);
  delay(1000);
  
}//end wristTest function

//Gripper function to open
void openGripper()
{
  clawServo.write(30);
  delay(1000);
  clawServo.write(170);
  delay(5000);
  
}//end openGripper function

//Gripper function to close
void closeGripper()
{
  Gripper_SERVO.write(30);
  delay(1000);
  
}//end closeGripper function


/*
 * //declaring servo names
Servo Gripper_SERVO;
Servo Wrist_SERVO;
Servo L_SERVO;
Servo R_SERVO;

//*********Setup function to set inputs, outputs, and pin ports************
void setup()
{
  Gripper_SERVO.attach(5);
  Wrist_SERVO.attach(6);
  Serial.begin(9600);  //Start serial monitor to print values from inputs
  
}//end setup function

//****** Main loop function *******
void loop ()
{
    gripperTest();
    wristTest();
    
}//******* end Main loop function ****************************************************


//**********Arm Movement Functions********
//This function will call the openGripper and closeGripper functions
void gripperTest()
{
  openGripper();
  closeGripper();

}//end gripperTest function

//This function will test the servo that rotates the gripper
void wristTest()
{
  Wrist_SERVO.write(45);
  delay(1000);
  Wrist_SERVO.write(135);
  delay(1000);
  
}//end wristTest function

//Gripper function to open
void openGripper()
{
  Gripper_SERVO.write(150);
  delay(1000);
  
}//end openGripper function

//Gripper function to close
void closeGripper()
{
  Gripper_SERVO.write(30);
  delay(1000);
  
}//end closeGripper function

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



*/
 

