#include "constants.h"
#include <API.h>

void motorSetAdj(unsigned char channel, int speed) {
  int adj[] = {
    REV_MOTOR_1,
    REV_MOTOR_2,
    REV_MOTOR_3,
    REV_MOTOR_4,
    REV_MOTOR_5,
    REV_MOTOR_6,
    REV_MOTOR_7,
    REV_MOTOR_8,
    REV_MOTOR_9,
    REV_MOTOR_10
  };
  motorSet(channel, speed * adj[channel - 1]);
}