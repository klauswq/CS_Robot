/*
 * motor.h
 *
 *  Created on: 2017年10月25日
 *      Author: wangqi
 */

#ifndef MOTOR_H_
#define MOTOR_H_

void pwmMotorFxn(UArg arg0, UArg arg1);
void RHMotorChannelAFallingFxn();
//void RHMotorChannelARisingFxn();
//void RHMotorChannelBFallingFxn();
//void RHMotorChannelBRisingFxn();
void LHMotorChannelAFallingFxn();
//void LHMotorChannelARisingFxn();
//void LHMotorChannelBFallingFxn();
//void LHMotorChannelBRisingFxn();
void  go_straight(float distance);
void pid();
void turn90();
#endif /* MOTOR_H_ */

