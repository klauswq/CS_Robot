/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/cfg/global.h>
/* BIOS Header files */
#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/PWM.h>

/* Example/Board Header files */
#include "Board.h"


extern uint8_t distance_R[4];
extern uint8_t distance_L[4];
extern float speed_R;
extern float speed_L;
float setpoint=7.7;
int Rotation_R=0;
int Rotation_L=0;
Uint32 ooo=0;
uint32_t pre_T;
uint32_t curr_T;
double dt;
double error_R;
double error_L;
double pre_error_R=0;
double pre_error_L=0;
double integ_R=0;
double integ_L=0;
double diff_R=0;
double diff_L=0;
double Ki_R,Kp_R,Kd_R;
double Ki_L,Kp_L,Kd_L;
int duty_change_R=0;
int duty_change_L=0;
uint16_t pwm_R=550;
uint16_t pwm_L=550;

double Setpoint=25;
double Input;
double Output;
double Kp=0.32, Ki=0.05, Kd=0.3;

double ini_speed_left = 300;
double ini_speed_right = 300;
int output_speed_left, output_speed_right;
double gap;

double Igap=0;
double previous_gap=0;
double gap_difference;
double gap_array[10]={0,0,0,0,0,0,0,0,0,0};
int n=0;

float distance_forward,distance_left,distance_right,distance_ground;

float new_distance_left;
float old_distance_left;
float new_distance_forward;
float recored_a_left_distance;


void RHMotorChannelAFallingFxn()
{
    Rotation_R++;

}

void LHMotorChannelAFallingFxn()
{
    Rotation_L++;
}

void pwmMotorFxn(UArg arg0, UArg arg1)
{
    PWM_Handle pwm1;
    PWM_Handle pwm2 = NULL;
    PWM_Handle pwm3;
    PWM_Handle pwm4 = NULL;
    PWM_Params params;
    uint16_t   pwmPeriod = 3000;      // Period and duty in microseconds

    PWM_Params_init(&params);
    params.dutyUnits = PWM_DUTY_US;
    params.dutyValue = 0;
    params.periodUnits = PWM_PERIOD_US;
    params.periodValue = pwmPeriod;

    pwm1 = PWM_open(Board_PWM0, &params);
    if (pwm1 == NULL) {
        System_abort("Board_PWM0 did not open");
    }
    PWM_start(pwm1);

    pwm2 = PWM_open(Board_PWM1, &params);
    if (pwm2 == NULL) {
         System_abort("Board_PWM1 did not open");
        }
     PWM_start(pwm2);

     pwm3 = PWM_open(Board_PWM2, &params);
     if (pwm3 == NULL) {
         System_abort("Board_PWM0 did not open");
     }
     PWM_start(pwm3);

     pwm4 = PWM_open(Board_PWM3, &params);
     if (pwm4 == NULL) {
         System_abort("Board_PWM0 did not open");
     }
     PWM_start(pwm4);
     pre_T=Clock_getTicks();

    PWM_setDuty(pwm1, 0);

    if (pwm2)
    {
        PWM_setDuty(pwm2, 430);//430 500
    }

    PWM_setDuty(pwm3, 0);

    if (pwm4)
    {
        PWM_setDuty(pwm4, 430);//430 500
    }
    Task_sleep(40);

    /* Loop forever incrementing the PWM duty */
    while (1) {
        int i=2;

        switch (i)

        {
        case 1:
            Kp_R=6;Ki_R=0.1;Kd_R=0.1;
            Kp_L=6;Ki_L=0.1;Kd_L=0.1;
        curr_T=Clock_getTicks();
        dt=curr_T-pre_T;
        dt=dt/1000;
        error_R=setpoint-speed_R;
        error_L=setpoint-speed_L;
        integ_R=integ_R+error_R*dt;
        integ_L=integ_L+error_L*dt;
        diff_R=(error_R-pre_error_R)/dt;
        diff_L=(error_L-pre_error_L)/dt;
        duty_change_R=(Kp_R*(error_R+Ki_R*integ_R+Kd_R*diff_R));
        duty_change_L=(Kp_L*(error_L+Ki_L*integ_L+Kd_L*diff_L));
        pwm_R+=(int)(duty_change_R+0.5);
        pwm_L+=(int)(duty_change_L+0.5);
        PWM_setDuty(pwm1, 0);
        PWM_setDuty(pwm3, 0);
        PWM_setDuty(pwm2, pwm_R);
        PWM_setDuty(pwm4, pwm_L);
        pre_error_R=error_R;
        pre_error_L=error_L;

        pre_T=curr_T;
        Task_sleep(40);
        break;

        case 2:
            pwm_R=560;
            pwm_L=550;

            Kp_R=0.5;Ki_R=0;Kd_R=0;
            Kp_L=0.8;Ki_L=0;Kd_L=0;
            setpoint=120;

            curr_T=Clock_getTicks();
            dt=curr_T-pre_T;
            dt=dt/1000;
            speed_R=(double)distance_R[1];
            speed_L=(double)distance_L[2];
            error_R=setpoint-speed_R;
            error_L=setpoint-speed_L;

            integ_R=integ_R+error_R*dt;

            diff_R=(error_R-pre_error_R)/dt;

            integ_L=integ_L+error_L*dt;

            diff_L=(error_L-pre_error_L)/dt;

            duty_change_R=(Kp_R*(error_R+Ki_R*integ_R+Kd_R*diff_R));
            duty_change_L=(Kp_L*(error_L+Ki_L*integ_L+Kd_R*diff_L));
            /*pwm_R-=(int)(duty_change_L+0.5);
            pwm_L-=(int)(duty_change_R+0.5);*/


             if (pwm_R<0){pwm_R=1;}
             if (pwm_R>1000){pwm_R=1000;}
             if (pwm_L<0){pwm_L=1;}
             if (pwm_L>1000){pwm_L=1000;}

            if (distance_L[3] <= 150)
            {

                pwm_R -= (int) (duty_change_L + 0.5);
                pwm_L += (int) (duty_change_L + 0.5);
                PWM_setDuty(pwm1, 0);
                PWM_setDuty(pwm3, 0);
                PWM_setDuty(pwm2, pwm_R);
                PWM_setDuty(pwm4, pwm_L);
                if ((distance_R[2] <= 180) && (distance_L[1] <= 180))
                {
                    PWM_setDuty(pwm1, 0);
                    PWM_setDuty(pwm3, 0);
                    PWM_setDuty(pwm2, 100);
                    PWM_setDuty(pwm4, 500);
                    Task_sleep(1000);
                }
                else
                {
                    pwm_R -= (int) (duty_change_L + 0.5);
                    pwm_L += (int) (duty_change_L + 0.5);
                    PWM_setDuty(pwm1, 0);
                    PWM_setDuty(pwm3, 0);
                    PWM_setDuty(pwm2, pwm_R);
                    PWM_setDuty(pwm4, pwm_L);
                    Task_sleep(50);
                }

            }

            if (distance_R[0] <= 150)
            {

                pwm_R += (int) (duty_change_R + 0.5);
                pwm_L -= (int) (duty_change_R + 0.5);
                PWM_setDuty(pwm1, 0);
                PWM_setDuty(pwm3, 0);
                PWM_setDuty(pwm2, pwm_R);
                PWM_setDuty(pwm4, pwm_L);
                if ((distance_R[2] <= 180) && (distance_L[1] <= 180))
                {
                    PWM_setDuty(pwm1, 0);
                    PWM_setDuty(pwm3, 0);
                    PWM_setDuty(pwm2, 500);
                    PWM_setDuty(pwm4, 100);
                    Task_sleep(1000);
                }
                else
                {
                    pwm_R += (int) (duty_change_R + 0.5);
                    pwm_L -= (int) (duty_change_R + 0.5);
                    PWM_setDuty(pwm1, 0);
                    PWM_setDuty(pwm3, 0);
                    PWM_setDuty(pwm2, pwm_R);
                    PWM_setDuty(pwm4, pwm_L);
                    Task_sleep(50);
                }

            }
            if ((distance_R[2] <= 150) && (distance_L[1] <= 150))
            {
                if ((distance_R[0] > 150) && (distance_L[3] > 150))
                {
                    PWM_setDuty(pwm1, 0);
                    PWM_setDuty(pwm3, 0);
                    PWM_setDuty(pwm2, 500);
                    PWM_setDuty(pwm4, 100);
                    Task_sleep(1000);
                }
            }
            //gaillllll
           /* else if ((distance_R[2] > 250) && (distance_L[1] > 250))
            {
                if (distance_R[0] >= 250)
                {
                    PWM_setDuty(pwm1, 0);
                    PWM_setDuty(pwm3, 0);
                    PWM_setDuty(pwm2, 100);
                    PWM_setDuty(pwm4, 500);
                    Task_sleep(700);
                }
                else if (distance_L[3] >= 250)
                {

                    pwm_R -= (int) (duty_change_L + 0.5);
                    pwm_L += (int) (duty_change_L + 0.5);
                    PWM_setDuty(pwm1, 0);
                    PWM_setDuty(pwm3, 0);
                    PWM_setDuty(pwm2, 500);
                    PWM_setDuty(pwm4, 100);
                    Task_sleep(700);
                }
                if(distance_L[3]>250)
                {
                    PWM_setDuty(pwm1, 0);
                    PWM_setDuty(pwm3, 0);
                    PWM_setDuty(pwm2, 500);
                    PWM_setDuty(pwm4, 100);
                    Task_sleep(1000);
                }

            }*/
           /* else if((distance_R[2]<=200)&&(distance_L[1]<=200))
            {
                if(distance_L[3]<=150)
                    {
                    PWM_setDuty(pwm1, 0);
                    PWM_setDuty(pwm3, 0);
                    PWM_setDuty(pwm2, 500);
                    PWM_setDuty(pwm4, 100);
                    }
                else {
                PWM_setDuty(pwm1, 0);
                PWM_setDuty(pwm3, 0);
                PWM_setDuty(pwm2, 100);
                PWM_setDuty(pwm4, 500);
                }
                Task_sleep(1000);

            }*/


            else
            {
                PWM_setDuty(pwm1, 0);
                PWM_setDuty(pwm3, 0);
                PWM_setDuty(pwm2, 550);
                PWM_setDuty(pwm4, 530);
            }
            pre_error_R=error_R;
            pre_error_L=error_L;

            pre_T=curr_T;
            Task_sleep(40);
            break;
           // Input=(double)distance_L[2];


        default:
        i=4;
        /*PWM_setDuty(pwm1, 0);

        if (pwm2) {
            PWM_setDuty(pwm2, 1500);
        }

        PWM_setDuty(pwm3, 0);

        if (pwm2) {
            PWM_setDuty(pwm4, 1500);
        }
        Task_sleep((UInt) arg0);*/

        /*if((distance_R[2]<=100)||(distance_L[1]<=100))
        {
            PWM_setDuty(pwm1, 3000);
            PWM_setDuty(pwm2, 3000);
            PWM_setDuty(pwm3, 3000);
            PWM_setDuty(pwm4, 3000);
            break;
        }*/

        }

    }
}



