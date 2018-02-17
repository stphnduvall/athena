#include <API.h>

void autonomous() {

  encoderReset(left); encoderReset(right);
  
  // 10 point auton
  if(analogRead(POT_MOGO) <= 1900) {
    motorSet(LIFT_L1,  70);
    motorSet(LIFT_L2,  70);
    motorSet(LIFT_R1, - 70);
    motorSet(LIFT_R2, - 70);

    delay(350);

    motorSet(LIFT_L1, 0);
    motorSet(LIFT_L2, 0);
    motorSet(LIFT_R1, 0);
    motorSet(LIFT_R2, 0);

    while(analogRead(POT_MOGO) > 1820) {
      motorSet(MOGO_L,  70);
      motorSet(MOGO_R, - 70);
    }

    delay(100);

    motorSet(MOGO_L, 0);
    motorSet(MOGO_R, 0);

    drivePID(49);

    while(analogRead(POT_MOGO) < 4055) {
      motorSet(MOGO_L, - 70);
      motorSet(MOGO_R,  70);
    }

    motorSet(MOGO_L, 0);
    motorSet(MOGO_R, 0);

    drivePID(-45);

    motorSet(LIFT_L1, -70);
    motorSet(LIFT_L2, -70);
    motorSet(LIFT_R1,  70);
    motorSet(LIFT_R2,  70);

    delay(250);

    motorSet(LIFT_L1, 0);
    motorSet(LIFT_L2, 0);
    motorSet(LIFT_R1, 0);
    motorSet(LIFT_R2, 0);

    motorSet(ROLLER_CLAW, - 70);
    delay(400);
    motorSet(ROLLER_CLAW, 0);

    delay(250);

    turnPID(1, 135);

    delay(100);
    drivePID(6);
    delay(100);
    turnPID(1, 100);

    drivePID(5);

    motorSet(LIFT_L1,  70);
    motorSet(LIFT_L2,  70);
    motorSet(LIFT_R1, - 70);
    motorSet(LIFT_R2, - 70);

    delay(350);

    motorSet(LIFT_L1, 0);
    motorSet(LIFT_L2, 0);
    motorSet(LIFT_R1, 0);
    motorSet(LIFT_R2, 0);


    while(analogRead(POT_MOGO) > 1825) {
      motorSet(MOGO_L, 115);
      motorSet(MOGO_R, -115);
    }
    motorSet(MOGO_L, 0);
    motorSet(MOGO_R, 0);

    drivePID(-9);
  }
}
