/*
 *  ======== main.c ========
 */
/* XDCtools Header files */
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
#define TASKSTACKSIZE       2048
Task_Struct task0Struct;
Char task0Stack[TASKSTACKSIZE];
Task_Handle task;

Task_Struct tsk1Struct;
UInt8 tsk1Stack[TASKSTACKSIZE];
Task_Handle task1;//motor
/*
 *  ======== global system state variables ========
 */
uint8_t	state = 1;
//extern para;



/*
 *  ======== main ========
 */
int main(void)
{   /* Call board init functions */
    Board_initGeneral();
    Board_initGPIO();
    Board_initPWM();
    Board_initI2C();
    Task_Params taskParams;
    Task_Params tskParams;//motor

    GPIO_setCallback(Board_BUTTON0, gpioButtonFxn0);
    GPIO_enableInt(Board_BUTTON0);
    GPIO_setCallback(Board_BUTTON1, gpioButtonFxn1);
    GPIO_enableInt(Board_BUTTON1);

    // Switch on the LEDs
    //
   /* GPIO_write(Board_LED0, Board_LED_ON);	// LH LED
    GPIO_write(Board_LED1, Board_LED_ON);	// RH LED, Red
    GPIO_write(Board_LED2, Board_LED_ON);	// RH LED, Green
    GPIO_write(Board_LED3, Board_LED_ON);	// RH LED, Blue*/
    /*printf("Starting the example\nSystem provider is set to SysMin. "
                      "Halt the target to view any SysMin contents in ROV.\n");*/
    GPIO_write(MSP_EXP432P401R_P5_2, 1);
    GPIO_write(MSP_EXP432P401R_P4_6, 1);
    GPIO_write(MSP_EXP432P401R_P3_0, 1);//motor nsleep open

    GPIO_setCallback(MSP_EXP432P401R_P6_1, RHMotorChannelAFallingFxn);
    GPIO_enableInt(MSP_EXP432P401R_P6_1);

    /*GPIO_setCallback(MSP_EXP432P401R_P4_0, RHMotorChannelARisingFxn);
    GPIO_enableInt(MSP_EXP432P401R_P4_0);

    GPIO_setCallback(Robot_MotorRIN2f, RHMotorChannelBFallingFxn);
    GPIO_enableInt(Robot_MotorRIN2f);

    GPIO_setCallback(Robot_MotorRIN2r, RHMotorChannelBRisingFxn);
    GPIO_enableInt(Robot_MotorRIN2r);*/

    GPIO_setCallback(Robot_MotorLIN1f, LHMotorChannelAFallingFxn);
    GPIO_enableInt(Robot_MotorLIN1f);

    /*GPIO_setCallback(Robot_MotorLIN1r, LHMotorChannelARisingFxn);
    GPIO_enableInt(Robot_MotorLIN1r);

    GPIO_setCallback(Robot_MotorLIN2f, LHMotorChannelBFallingFxn);
    GPIO_enableInt(Robot_MotorLIN2f);

    GPIO_setCallback(Robot_MotorLIN2r, LHMotorChannelBRisingFxn);
    GPIO_enableInt(Robot_MotorLIN2r);*/


    Task_Params_init(&taskParams);
    taskParams.stackSize = TASKSTACKSIZE;
    taskParams.stack = &task0Stack;
    Task_construct(&task0Struct, (Task_FuncPtr)Range_DetectFxn, &taskParams, NULL);


    Task_Params_init(&tskParams);
    tskParams.stackSize = TASKSTACKSIZE;
    tskParams.stack = &tsk1Stack;
    tskParams.arg0 = 200;
    Task_construct(&tsk1Struct, (Task_FuncPtr) pwmMotorFxn, &tskParams, NULL);


    task = Task_handle(&task0Struct);
    task1 = Task_handle(&tsk1Struct);

    /* SysMin will only print to the console when you call flush or exit */

    System_flush();

    /* Start BIOS */
    BIOS_start();
    //I2C_cfg();

    return (0);
}
