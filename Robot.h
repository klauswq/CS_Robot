#ifndef __ROBOT_H
#define __ROBOT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "MSP_EXP432P401R.h"

// Extensions to the board definitions
#define Robot_Sharp96x96_CS			MSP_EXP432P401R_P4_3
#define Robot_Sharp96x96_CS_ON		(1)
#define Robot_Sharp96x96_CS_OFF		(0)
#define Robot_Sharp96x96_DISP		MSP_EXP432P401R_P4_1
#define Robot_Sharp96x96_DISP_ON	(1)
#define Robot_Sharp96x96_DISP_OFF	(0)

#define Robot_Motor_ON				(1)
#define Robot_Motor_OFF				(0)
#define Robot_MotorEN				MSP_EXP432P401R_P3_0 	// Port3.0

#define Robot_MotorRIN1f            MSP_EXP432P401R_P6_1
#define Robot_MotorRIN1r            MSP_EXP432P401R_P4_0
#define Robot_MotorRIN2f            MSP_EXP432P401R_P4_2
#define Robot_MotorRIN2r            MSP_EXP432P401R_P4_4
#define Robot_MotorLIN1f            MSP_EXP432P401R_P4_5
#define Robot_MotorLIN1r            MSP_EXP432P401R_P4_7
#define Robot_MotorLIN2f            MSP_EXP432P401R_P5_4
#define Robot_MotorLIN2r            MSP_EXP432P401R_P5_5

#define Robot_Sensor_ON				(1)
#define Robot_Sensor_OFF			(0)

#define Robot_Left_Sensor_PE		MSP_EXP432P401R_P5_2 	// output
#define Robot_Left_Sensor_INT		MSP_EXP432P401R_P5_0 	// input
#define Robot_Right_Sensor_PE		MSP_EXP432P401R_P4_6 	// output
#define Robot_Right_Sensor_INT		MSP_EXP432P401R_P6_0 	// input

#define Robot_Bottom_Sensor1		MSP_EXP432P401R_P2_3	// Connector J3 Pin 2 - set as input for now
#define Robot_Bottom_Sensor2		MSP_EXP432P401R_P5_6	// Connector J3 Pin 4 - set as input for now

/* Board specific I2C addresses */
#define PCA9545A_ADDR         		(0x70)
#define GP2Y0E02B_ADDR				(0x80 >> 1)

#ifdef __cplusplus
}
#endif

#endif /* __ROBOT_H */
