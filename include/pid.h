#ifndef PID_H_
#define PID_H_

void liftPID(int liftSpeed, int target);
void drivePID(int sp);
void turnPID(int dir, int sp);

#endif //PID_H_