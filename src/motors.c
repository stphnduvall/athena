#include "constants.h"
#include "util.h"

// Drive
void setDrive(char left, char right) {
  motorSetAdj(DRIVE_L, left);
  motorSetAdj(DRIVE_R, right);
}
// DR4B
void setLift(int liftSpeed) {
  motorSetAdj(LIFT_L1, liftSpeed);
  motorSetAdj(LIFT_L2, liftSpeed);
  motorSetAdj(LIFT_R1, liftSpeed);
  motorSetAdj(LIFT_R2, liftSpeed);
}

// Mogo
void setMogo(int mogoSpeed) {
  motorSetAdj(MOGO_L, mogoSpeed);
  motorSetAdj(MOGO_R, mogoSpeed);
}