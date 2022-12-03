#include <Alfredo_NoU2.h>
#include <AlfredoConnect.h>
#include <BluetoothSerial.h>

//M = motor, F = front, B = back, L = left, R = right

// TODO set correct pins
NoU_Motor M_FL(1); 
NoU_Motor M_FR(2);
NoU_Motor M_BL(3);
NoU_Motor M_BR(4);

NoU_Motor intake(5);
NoU_Motor flyWheel(6);

NoU_Drivetrain drivetrain(&M_FL,&M_FR,&M_BL,&M_BR);

BluetoothSerial bluetooth;


void setup() {
  // put your setup code here, to run once:
  bluetooth.begin("Triple Threat"); // Sets Name
  AlfredoConnect.begin(bluetooth);
  bluetooth.println("Connected ig");
  bluetooth.println("I have no clue what I'm doing :D");
  bluetooth.println("\"this code should work\" Archer");
}

void loop() {
  //Vars for drivetrain
  float throttle = 0;
  float rotation = 0;

  //Forward and backwards
  if (AlfredoConnect.keyHeld(Key::W)){
    throttle = 1;
  }else if (AlfredoConnect.keyHeld(Key::S)){
    throttle = -1;
  }

  //Rotate left and right
  if (AlfredoConnect.keyHeld(Key::A)){
    rotation = -1;
  }else if (AlfredoConnect.keyHeld(Key::D)){
    rotation = 1;
  }

  //intake
  if(AlfredoConnect.keyHeld(Key::J)){
    intake.set(1);
  }
  else{
    intake.set(0);
  }

  //flywheel
  if(AlfredoConnect.keyHeld(Key::L)){
    flyWheel.set(1);
  }
  else{
    flyWheel.set(0);
  }

  //set motors
  drivetrain.curvatureDrive(throttle, rotation);

    
  AlfredoConnect.update();

}
