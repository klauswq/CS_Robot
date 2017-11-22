/*
 * screenTask.c
 *
 *  Created on: 9 Oct 2016
 *      Author: shailes
 */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

/* Board Header files */
#include "Sharp96x96.h"
#include <stdio.h>

extern int duty_change_R;
extern int duty_change_L;
extern uint8_t distance_R[4];
extern uint8_t distance_L[4];

extern double gap;
extern int Rotation_R;
extern int Rotation_L;
extern uint16_t pwm_R;
extern float speed_R;
extern float speed_L;
extern double error_R;
extern double error_L;
extern int output_speed_left;
/*
 *  screenTaskFxn
 */

void screenTaskFxn (UArg arg0, UArg arg1)
{
    Graphics_Context g_sContext;

    char test1_string[20];
    char test2_string[20];

    const uint8_t LHS =  10;
    const uint8_t RHS = 210;
    uint8_t y;

    Sharp96x96_LCDInit();

    Graphics_initContext(&g_sContext, &g_sharp96x96LCD);
    Graphics_setForegroundColor(&g_sContext, ClrBlack);
    Graphics_setBackgroundColor(&g_sContext, ClrWhite);
    Graphics_setFont(&g_sContext, &g_sFontCm20b);
    Graphics_clearDisplay(&g_sContext);
    Graphics_flushBuffer(&g_sContext);

    while (1) {
        Graphics_clearBuffer(&g_sContext);
        y = 0;

        sprintf(test1_string, "Group 7");
        Graphics_drawString(&g_sContext, test1_string,
                            GRAPHICS_AUTO_STRING_LENGTH, LHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        y += 20;

        sprintf(test1_string, "Sensor_R[0] = %d", distance_R[0]);
        Graphics_drawString(&g_sContext, test1_string,
                            GRAPHICS_AUTO_STRING_LENGTH, LHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test2_string, "Sensor_L[0] = %d", distance_L[0]);
        Graphics_drawString(&g_sContext, test2_string,
                            GRAPHICS_AUTO_STRING_LENGTH, RHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        y += 20;

        sprintf(test1_string, "Sensor_R[1] = %d", distance_R[1]);
        Graphics_drawString(&g_sContext, test1_string,
                            GRAPHICS_AUTO_STRING_LENGTH, LHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test2_string, "Sensor_L[1] = %d", distance_L[1]);
        Graphics_drawString(&g_sContext, test2_string,
                            GRAPHICS_AUTO_STRING_LENGTH, RHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        y += 20;


        sprintf(test1_string, "Sensor_R[2] = %d", distance_R[2]);
        Graphics_drawString(&g_sContext, test1_string,
                            GRAPHICS_AUTO_STRING_LENGTH, LHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test2_string, "Sensor_L[2] = %d", distance_L[2]);
        Graphics_drawString(&g_sContext, test2_string,
                            GRAPHICS_AUTO_STRING_LENGTH, RHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        y += 20;

        sprintf(test1_string, "Sensor_R[3] = %d", distance_R[3]);
        Graphics_drawString(&g_sContext, test1_string,
                            GRAPHICS_AUTO_STRING_LENGTH, LHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test2_string, "Sensor_L[3] = %d", distance_L[3]);
        Graphics_drawString(&g_sContext, test2_string,
                            GRAPHICS_AUTO_STRING_LENGTH, RHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        y += 20;


        sprintf(test1_string, "Rotaion_R = %d", Rotation_R);
        Graphics_drawString(&g_sContext, test1_string,
        GRAPHICS_AUTO_STRING_LENGTH,
                            LHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test2_string, "Rotaion_L = %d", Rotation_L);
        Graphics_drawString(&g_sContext, test2_string,
        GRAPHICS_AUTO_STRING_LENGTH,
                            RHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        y += 20;

        sprintf(test1_string, "Speed = %.2f", speed_R);
        Graphics_drawString(&g_sContext, test1_string,
        GRAPHICS_AUTO_STRING_LENGTH,
                            LHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test2_string, "Speed = %.2f", speed_L);
        Graphics_drawString(&g_sContext, test2_string,
        GRAPHICS_AUTO_STRING_LENGTH,
                            RHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);

        y += 20;

        sprintf(test1_string, "change_R = %d", duty_change_R);
        Graphics_drawString(&g_sContext, test1_string,
        GRAPHICS_AUTO_STRING_LENGTH,
                            LHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test2_string, "change_L = %d", duty_change_L);
        Graphics_drawString(&g_sContext, test2_string,
        GRAPHICS_AUTO_STRING_LENGTH,
                            RHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);

        y += 20;

        sprintf(test1_string, "error_R = %.2lf", error_R);
        Graphics_drawString(&g_sContext, test1_string,
        GRAPHICS_AUTO_STRING_LENGTH,
                            LHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        sprintf(test2_string, "error_L = %.2lf", error_L);
        Graphics_drawString(&g_sContext, test2_string,
        GRAPHICS_AUTO_STRING_LENGTH,
                            RHS, y,
                            GRAPHICS_TRANSPARENT_TEXT);
        y += 20;
        /*
                sprintf(test1_string, "pwm_R = %lf", gap);
                Graphics_drawString(&g_sContext, test1_string,
                GRAPHICS_AUTO_STRING_LENGTH,
                                    LHS, y,
                                    GRAPHICS_TRANSPARENT_TEXT);

                sprintf(test2_string, "speedl = %d", output_speed_left);
                Graphics_drawString(&g_sContext, test2_string,
                GRAPHICS_AUTO_STRING_LENGTH,
                                    RHS, y,
                                    GRAPHICS_TRANSPARENT_TEXT);
        y += 20;
*/
        Graphics_flushBuffer(&g_sContext);
        Task_sleep((UInt)arg0);
    }
}

