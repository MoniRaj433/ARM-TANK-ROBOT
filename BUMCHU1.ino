#include <MeMegaPi.h>

// TANK MOTORS
// Define motor objects for each motor connected to the MegaPi board
MeMegaPiDCMotor RightMotor1(PORT1B); 
MeMegaPiDCMotor LeftMotor2(PORT2B);
MeMegaPiDCMotor ArmMotor3(PORT3B); 
MeMegaPiDCMotor GripperMotor1A(PORT1A);
MeUltrasonicSensor ultrasonicSensor(PORT7);

float distance = 0;

void setup() {
  Serial.begin(9600);
  
}
void loop() {
  // Get distance from the ultrasonic sensor
  distance = ultrasonicSensor.distanceCm();
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // Basic obstacle avoidance for the tank
  if (distance >= 80) {
    RightMotor1.run(-160);
    LeftMotor2.run(160); // Move tank forward if no obstacle
  }
    
    else if (distance < 20 && distance >= 40)  {
    RightMotor1.run(80);
    LeftMotor2.run(80);
    }
    
   else if(distance <= 20){
    RightMotor1.stop();
    LeftMotor2.stop();

   ArmMotor3.run(100);
   delay(1500);
   GripperMotor1A.run(-100);
   delay(2000);
   GripperMotor1A.stop();
   delay(2000);
   GripperMotor1A.run(100);
   delay(2000);
   ArmMotor3.run(-100);
   delay(1500);
   ArmMotor3.stop();
   delay(1500);
   RightMotor1.run(100);
   LeftMotor2.run(100); 
   delay(780); 
   RightMotor1.stop();
   LeftMotor2.stop(); 
   delay(500); 
   RightMotor1.run(-100);
   LeftMotor2.run(100); 
   delay(2000);
  }

delay(1000);
}


  
