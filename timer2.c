/*
 * timer2.c
 *
 *  Created on: 2017��10��28��
 *      Author: Administrator
 */

#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>
/* Board Header files */
#include "Board.h"
#include "buttons.h"
#include <stdio.h>
#include <Range_Read.h>
#include <motor.h>
#include <Robot.h>

extern int Rotation_R;
extern int Rotation_L;
float speed_R;
float speed_L;

void timer2Fxn()
{
    speed_R=Rotation_R*0.5759586532;//1/750*pi*5.5/0.1*0.02304
    speed_L=Rotation_L*0.5759586532;// speed_L=Rotation_L;
    Rotation_R=0;
    Rotation_L=0;
}


