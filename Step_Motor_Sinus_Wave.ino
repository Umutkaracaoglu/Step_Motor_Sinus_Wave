#include <AccelStepper.h>
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 9
#define stepPin 8
#define motorInterfaceType 1
char alinan;
// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
void setup() {
  Serial.begin(9600);
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(1500);
  
  attachInterrupt(0, interrupt_1, CHANGE);
  attachInterrupt(1, interrupt_2, CHANGE);
}
void loop() {
  stepper.setMaxSpeed(1500);
  Serial.println("loopa girildi");
  if (Serial.available() > 0){
    
    Hizlanma_Yavaslama();
  }

}

void Hizlanma_Yavaslama(){
  stepper.setMaxSpeed(1500);
  stepper.setAcceleration(150);
  
  // Set the target position:
  stepper.moveTo(2000);
  // Run to target position with set speed and acceleration/deceleration:
  stepper.runToPosition();
  delay(50);
  Serial.println("2000-4000");
  stepper.setAcceleration(150);
  stepper.moveTo(4000);
  stepper.runToPosition();
  delay(50);
  stepper.setAcceleration(150);
  Serial.println("6000-8000");
  stepper.moveTo(6000);
  stepper.runToPosition();
  delay(50);
  
  stepper.setAcceleration(150);
  // Move back to zero:
  stepper.moveTo(0);
  stepper.runToPosition();
  delay(1000);
  
}

void interrupt_1 (){
  stepper.setAcceleration(1000);
  Serial.println("interrupt_1'e girildi");
  stepper.stop();
  Serial.println("interruptan cikildi");
}
void interrupt_2 (){
  Serial.println("interrupt_2'e girildi");
  stepper.setAcceleration(1000);
  stepper.stop();
  if (Serial.available() > 0){
  }  

}
