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

BluetoothSerial bluetooth;


void setup() {
  // put your setup code here, to run once:
  bluetooth.begin("Triple Threat"); // Sets Name
  AlfredoConnect.begin(bluetooth);
  bluetooth.println("Connected ig");
  bluetooth.println("I have no clue what I'm doing :D");
}

void loop() {
  // put your main code here, to run repeatedly:


    //TANK DRIVE *can change*
    if (AlfredoConnect.keyHeld(Key::A)) {
        M_FL.set(1);
        M_BL.set(1);
    }
    else {
        M_FL.set(0);
        M_BL.set(0);
    }
    if (AlfredoConnect.keyHeld(Key::D)) {
        M_FR.set(1);
        M_BR.set(1);
    }
    else {
        M_FR.set(0);
        M_FR.set(0);
    }

    if (AlfredoConnect.keyHeld(Key::J)) {
        intake.set(1);
    }
    else {
        intake.set(0);
    }

    if (AlfredoConnect.keyHeld(Key::L)) {
        flyWheel.set(1);
    }
    else {
        flyWheel.set(0);
    }

    AlfredoConnect.update();

    /*
    back up code if my stuff no work

    float throttle = 0;
    float rotation = 0;

    // Set the throttle of the robot based on what key is pressed
    if (AlfredoConnect.keyHeld(Key::W)) {
        throttle = 1;
    }
    else if (AlfredoConnect.keyHeld(Key::S)) {
        throttle = -1;
    }

    // Set which direction the robot should turn based on what key is pressed
    if (AlfredoConnect.keyHeld(Key::A)) {
        rotation = -1;
    }
    else if (AlfredoConnect.keyHeld(Key::D)) {
        rotation = 1;
    }

    // Make the robot drive
    drivetrain.curvatureDrive(throttle, rotation);

    AlfredoConnect.update();
    */
}
