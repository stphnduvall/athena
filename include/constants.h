#include <API.h>

// Motor Ports
#define MOGO_L 1
#define DRIVE_L 2
#define LIFT_L1 3
#define LIFT_L2 4
#define LIFT_R1 5
#define LIFT_R2 6
#define ROLLER_4BAR 7
#define ROLLER_CLAW 8
#define DRIVE_R 9
#define MOGO_R 10

// Motor Reversed
#define REV_MOTOR_1 1
#define REV_MOTOR_2 1
#define REV_MOTOR_3 1
#define REV_MOTOR_4 1
#define REV_MOTOR_5 -1
#define REV_MOTOR_6 -1
#define REV_MOTOR_7 1
#define REV_MOTOR_8 1
#define REV_MOTOR_9 -1
#define REV_MOTOR_10 -1

// Shaft encoder and potentiometer ports
#define ENCODER_LTOP 1
#define ENCODER_LBOT 2
#define ENCODER_RTOP 3
#define ENCODER_RBOT 4
#define POT_LIFTL 1
#define POT_LIFTR 2
#define POT_MOGO 3
#define POT_AUTON 4
Encoder left;
Encoder right;

// Usefull Things
#define BUTTON_MOTOR_SPEED 120;