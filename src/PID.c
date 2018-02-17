
/*
    This file is for all the PID loops that will be used for autonomous.
    Included: Lift Slave PID, Straight Driving PID, Turning PID.
*/
#include "pid.h"
#include <math.h>
//Variables
int setpoint; int degrees; int degreesL; int degreesR; int power; int error;
int integral = 0; int deriv; double kP = 0.875; double kD = 0.045; int prevError = 0;
int breakCount = 0;
//Lift PID (Master/Slave, Master = left, slave = right)
void liftPID(int liftSpeed, int target){
  int liftkP = 0;
  while(1){
    setpoint = analogRead(POT_LIFTL);
    degrees = analogRead(POT_LIFTR);
    error = setpoint - degrees;
    power = liftSpeed + error*liftkP;  //make kP really small - potents give huge values


    if(setpoint < target - 20){
      motorSet(LIFT_L1, liftSpeed);
      motorSet(LIFT_L2, liftSpeed);
      motorSet(LIFT_R1, power);
      motorSet(LIFT_R2, power);
    }
    else if(setpoint > target - 20 && setpoint < target + 20){
      motorSet(LIFT_L1, 0);
      motorSet(LIFT_L2, 0);
      motorSet(LIFT_R1, 0);
      motorSet(LIFT_R2, 0);
      break;
    }
  }
}

//Main straight driving PID (Basic PID)
void drivePID(int sp){
  encoderReset(left); encoderReset(right);
  setpoint = (sp * 360) / 4 / 3.14159265;
  while(1){

    degreesL = encoderGet(left); degreesR = encoderGet(right);
    degrees = degreesL + degreesR / 2;
    error = setpoint - degreesL;
    deriv = error - prevError;
    prevError = error;
    power = error * kP + deriv * kD;

    printf("Setpoint: %d Error: %d Power: %d \n", setpoint, error, power);

    if(setpoint > 0 && abs(error) >= abs(0.25 * setpoint)){
      motorSet(DRIVE_L,  70);
      motorSet(DRIVE_R, - 70);
    }
    else if(setpoint < 0 && abs(error) >= abs(0.25 * setpoint))
    {
      motorSet(DRIVE_L, - 70);
      motorSet(DRIVE_R,  70);
    }
    else if(abs(error) > 15){
      motorSet(DRIVE_L, power);
      motorSet(DRIVE_R, -power);
    }
    else if(abs(error) <= 15){
      breakCount++;
      if(breakCount >= 20){
        motorSet(DRIVE_L, 0);
        motorSet(DRIVE_R, 0);
        encoderReset(left); encoderReset(right);
        break;
      }
    }
    else{
      motorSet(DRIVE_L, 0);
      motorSet(DRIVE_R, 0);
    }
    delay(20);
  }
}

//Turning PID
void turnPID(int dir, int sp){   // dir = 0 or 1. 0 for left, 1 for right
  encoderReset(left); encoderReset(right);
  int spL; int spR; int errorL; int errorR;
  int prevErrorR = 0; int derivR; int powerR;
  breakCount = 0;
  double ticksPerDegree =  7250.0 / 1800.0;

  setpoint = sp * ticksPerDegree;

  if(dir){
    while(1){
      spL = setpoint - 100; spR = -setpoint;
      degreesL = encoderGet(left); degreesR = encoderGet(right);
      errorL = spL - degreesL; errorR = spR - degreesR;
      deriv = errorL - prevError; derivR = errorR - prevErrorR;
      prevError = errorL; prevErrorR = errorR;
      power = errorL * kP + deriv * 0; powerR = errorR * kP + derivR * 0;

      printf("LD: %d LP: %d LE: %d RD: %d RP: %d RE: %d SP: %d \n", degreesL, power, errorL,
            degreesR, powerR, errorR, setpoint);

      if(errorL > 0.25 * spL && errorR < 0.25 * spR){
        motorSet(DRIVE_L, 90);
        motorSet(DRIVE_R, 90);
      }
      else if(abs(errorL) > 30 || abs(errorR) > 30){
        motorSet(DRIVE_L, power );
        motorSet(DRIVE_R, -powerR);
      }
      else if(abs(errorL) <= 30 && abs(errorR) <= 30){
        breakCount++;
        if(breakCount >= 20){
          motorSet(DRIVE_L, 0);
          motorSet(DRIVE_R, 0);
          encoderReset(left); encoderReset(right);
          break;
        }
      }
      else{
        motorSet(DRIVE_L, 0);
        motorSet(DRIVE_R, 0);
      }
      delay(20);
    }
   }
   else if(!dir){
     while(1){
       spL = -setpoint; spR = setpoint;
       degreesL = encoderGet(left); degreesR = encoderGet(right);
       errorL = spL - degreesL; errorR = spR - degreesR;
       deriv = errorL - prevError; derivR = errorR - prevErrorR;
       prevError = errorL; prevErrorR = errorR;
       power = errorL * kP + deriv * kD; powerR = errorR * kP + derivR * kD;

       if(errorL > 0.25 * spL && errorR < 0.25 * spR){
         motorSet(DRIVE_L, -90);
         motorSet(DRIVE_R, -90);
       }
       else if(abs(errorL) > 5 || abs(errorR) > 5){
         motorSet(DRIVE_L, power);
         motorSet(DRIVE_R, -powerR);
       }
       else if(abs(errorL) < 5 && abs(errorR) < 5){
         breakCount++;
         if(breakCount >= 20){
           motorSet(DRIVE_L, 0);
           motorSet(DRIVE_R, 0);
           encoderReset(left); encoderReset(right);
           break;
         }
       }
       else{
         motorSet(DRIVE_L, 0);
         motorSet(DRIVE_R, 0);
       }
       delay(20);
     }
   }
}
