

#include "main.h"

void operatorControl() {



	bool btnPress = 1;
	int rightPower;
	int leftPower;
	while (1) {
		//Tank Drive
		rightPower = joystickGetAnalog(1, 2);
		leftPower = joystickGetAnalog(1, 3);
		if(abs(rightPower) > 15 || abs(leftPower) > 15)
		{
			motorSet(DRIVE_R, -rightPower);
			motorSet(DRIVE_L, leftPower);
		}
		else{
			motorSet(DRIVE_R, 0);
			motorSet(DRIVE_L, 0);
		}

		//Lift
		if(joystickGetDigital(1, 5, JOY_UP))
		{
			motorSet(LIFT_L1, 127);
			motorSet(LIFT_R1, -127);
			motorSet(LIFT_L2, 127);
			motorSet(LIFT_R2, -127);
		}
		else if(joystickGetDigital(1, 5, JOY_DOWN))
		{
			motorSet(LIFT_L1, -127);
			motorSet(LIFT_R1, 127);
			motorSet(LIFT_L2, -127);
			motorSet(LIFT_R2, 127);
		}
		else{
			motorSet(LIFT_L1, 0);
			motorSet(LIFT_R1, 0);
			motorSet(LIFT_L2, 0);
			motorSet(LIFT_R2, 0);
		}

		//Mogo
		if(joystickGetDigital(1, 7, JOY_LEFT))
		{
			motorSet(MOGO_L, 127);
			motorSet(MOGO_R, -127);
		}
		else if(joystickGetDigital(1, 7, JOY_DOWN))
		{
			motorSet(MOGO_L, -127);
			motorSet(MOGO_R, 127);
		}
		else{
			motorSet(MOGO_R, 0);
			motorSet(MOGO_L, 0);
		}

		//Rollers - 4bar
		if(joystickGetDigital(1, 6, JOY_UP))
		{
			motorSet(ROLLER_4BAR, -127);
		}
		else if(joystickGetDigital(1, 6, JOY_DOWN))
		{
			motorSet(ROLLER_4BAR, 127);
		}
		else{
			motorSet(ROLLER_4BAR, 0);
		}

		//Rollers - Intake
		if(!btnPress && joystickGetDigital(1, 8, JOY_LEFT))
		{
			btnPress = 1;
		}
		else if(btnPress && joystickGetDigital(1, 8, JOY_UP))
		{
			btnPress = 0;
		}

		if(joystickGetDigital(1, 8, JOY_DOWN))
		{
			motorSet(ROLLER_CLAW, 127);
		}
		else if(joystickGetDigital(1, 8, JOY_RIGHT))
		{
			motorSet(ROLLER_CLAW, -127);
		}
		else if(btnPress)
		{
			motorSet(ROLLER_CLAW, 25);
		}
		else{
			motorSet(ROLLER_CLAW, 0);
		}

		delay(20);
	}

}
