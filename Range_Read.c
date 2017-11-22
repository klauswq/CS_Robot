
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>
#include "Board.h"
#include <stdio.h>

#define I2C_Switch_ADR 0x70
#define I2C_VL6180X_ADR 0x29
uint8_t para;
uint8_t distance_R[4];
uint8_t distance_L[4];


void Init(I2C_Handle handle){
    VL6180X_W(handle,0x0207, 0x01);
    VL6180X_W(handle,0x0208, 0x01);
    VL6180X_W(handle,0x0096, 0x00);
    VL6180X_W(handle,0x0097, 0xfd);
    VL6180X_W(handle,0x00e3, 0x00);
    VL6180X_W(handle,0x00e4, 0x04);
    VL6180X_W(handle,0x00e5, 0x02);
    VL6180X_W(handle,0x00e6, 0x01);
    VL6180X_W(handle,0x00e7, 0x03);
    VL6180X_W(handle,0x00f5, 0x02);
    VL6180X_W(handle,0x00d9, 0x05);
    VL6180X_W(handle,0x00db, 0xce);
    VL6180X_W(handle,0x00dc, 0x03);
    VL6180X_W(handle,0x00dd, 0xf8);
    VL6180X_W(handle,0x009f, 0x00);
    VL6180X_W(handle,0x00a3, 0x3c);
    VL6180X_W(handle,0x00b7, 0x00);
    VL6180X_W(handle,0x00bb, 0x3c);
    VL6180X_W(handle,0x00b2, 0x09);
    VL6180X_W(handle,0x00ca, 0x09);
    VL6180X_W(handle,0x0198, 0x01);
    VL6180X_W(handle,0x01b0, 0x17);
    VL6180X_W(handle,0x01ad, 0x00);
    VL6180X_W(handle,0x00ff, 0x05);
    VL6180X_W(handle,0x0100, 0x05);
    VL6180X_W(handle,0x0199, 0x05);
    VL6180X_W(handle,0x01a6, 0x1b);
    VL6180X_W(handle,0x01ac, 0x3e);
    VL6180X_W(handle,0x01a7, 0x1f);
    VL6180X_W(handle,0x0030, 0x00);
    VL6180X_W(handle,0x0011, 0x10); // Enables polling for ‘New Sample ready’
    // when measurement completes
    VL6180X_W(handle,0x010a, 0x30); // Set the averaging sample period
    // (compromise between lower noise and
    // increased execution time)
    VL6180X_W(handle,0x003f, 0x46); // Sets the light and dark gain (upper
    // nibble). Dark gain should not be
    // changed.
    VL6180X_W(handle,0x0031, 0xFF); // sets the # of range measurements after
    // which auto calibration of system is
    // performed
    VL6180X_W(handle,0x0040, 0x63); // Set ALS integration time to 100ms
    VL6180X_W(handle,0x002e, 0x01); // perform a single temperature calibration
    // of the ranging sensor
    //Optional: Public registers - See data sheet for more detail
    VL6180X_W(handle,0x001b, 0x09); // Set default ranging inter-measurement
    // period to 100ms
    VL6180X_W(handle,0x003e, 0x31); // Set default ALS inter-measurement period
    // to 500ms
    VL6180X_W(handle,0x0014, 0x24); // Configures interrupt on ‘New Sample
    // Ready threshold event
}
/*int VL6180X_Init() {
 char reset;
 reset = ReadByte(0x016);
 if (reset == 1)
 { // check to see has it be Initialised already
 ///////////////////////////////////////////////////////////////////
 // Added latest settings here - see Section 8
 ///////////////////////////////////////////////////////////////////
 WriteByte(0x016, 0x00); //change fresh out of set status to 0
 }
 return 0;
 }*/
/*void Switch_cfg(){
 I2C_Handle      I2C_R;
 I2C_Handle      I2C_L;
 I2C_Params      i2cParams_r;
 I2C_Params      i2cParams_l;
 //I2C_Transaction i2cTransaction;

 I2C_Params_init(&i2cParams_r);
 I2C_Params_init(&i2cParams_l);
 i2cParams_r.bitRate = I2C_400kHz;
 i2cParams_l.bitRate = I2C_400kHz;
 I2C_R = I2C_open(Board_I2C1, &i2cParams_r);
 I2C_L = I2C_open(Board_I2C2, &i2cParams_l);

 if(I2C_R==NULL)
 System_abort("Error Initializing I2C_R.\n");
 else
 printf("I2C_R initialization done!\n");

 if(I2C_L==NULL)
 System_abort("Error Initializing I2C_L.\n");
 else
 printf("I2C_L initialization done!\n");
 }*/

void Switch_Open(uint8_t channel, I2C_Handle handle){
    I2C_Transaction i2cTransaction;
    uint8_t         txBuffer[1];
    txBuffer[0] = 0xFF & channel;
    i2cTransaction.slaveAddress = I2C_Switch_ADR;
    i2cTransaction.writeBuf = txBuffer;
    i2cTransaction.writeCount = 1;
    i2cTransaction.readBuf = NULL;
    i2cTransaction.readCount = 0;


    if(I2C_transfer(handle, &i2cTransaction))
        System_printf("Switch  Channel %d is on\n",channel);
    else
        System_printf("Switch Channel has problem!\n");
}


void VL6180X_W(I2C_Handle handle, uint16_t addr, uint8_t data){
    I2C_Transaction i2cTransaction;
    uint8_t         txBuffer[3];
    txBuffer[0] = addr >> 8;
    txBuffer[1] = addr & 0xFF;
    txBuffer[2] = data;

    i2cTransaction.slaveAddress = I2C_VL6180X_ADR;
    i2cTransaction.writeBuf = txBuffer;
    i2cTransaction.writeCount = 3;
    i2cTransaction.readBuf = NULL;
    i2cTransaction.readCount = 0;

    if(!I2C_transfer(handle, &i2cTransaction))
        System_abort("VL6180X Writing is wrong!\n");
}


uint8_t VL6180X_R(I2C_Handle handle, uint16_t addr, size_t length){
    I2C_Transaction i2cTransaction;
    uint8_t txBuffer[2];
    uint8_t rxBuffer[1];
    txBuffer[0] = addr >>8;
    txBuffer[1] = addr & 0xFF;

    i2cTransaction.slaveAddress = I2C_VL6180X_ADR;
    i2cTransaction.writeBuf = txBuffer;
    i2cTransaction.writeCount = 3;
    i2cTransaction.readBuf = rxBuffer;
    i2cTransaction.readCount = length;

    if(!I2C_transfer(handle, &i2cTransaction))
        System_abort("VL6180X Reading is wrong!\n");
    return rxBuffer[0];
}

void Range_DetectFxn(UArg arg0, UArg arg1){

    int i = 0;
    //I2C_Handle      i2c_r;
    //I2C_Handle      i2c_l;
    //Switch_cfg();

    I2C_Handle      I2C_R;
    I2C_Handle      I2C_L;
    I2C_Params      i2cParams_r;
    I2C_Params      i2cParams_l;
    //I2C_Transaction i2cTransaction;
    //Init(I2C_R);
    //Init(I2C_L);
    I2C_Params_init(&i2cParams_r);
    I2C_Params_init(&i2cParams_l);
    i2cParams_r.bitRate = I2C_400kHz;
    i2cParams_l.bitRate = I2C_400kHz;
    I2C_R = I2C_open(Board_I2C1, &i2cParams_r);
    I2C_L = I2C_open(Board_I2C2, &i2cParams_l);

    if(I2C_R==NULL)
        System_abort("Error Initializing I2C_R.\n");
    else
        printf("I2C_R initialization done!\n");

    if(I2C_L==NULL)
        System_abort("Error Initializing I2C_L.\n");
    else
        printf("I2C_L initialization done!\n");
    uint8_t channel_No = 0x01;


    //uint8_t rxBuffer[4];

    //I2C_Transaction i2cTransaction;
    //uint8_t         txBuffer[1];


    while(1){
        for(i=0;i<4;i++){ //right set of sensors
            Switch_Open(channel_No, I2C_R);
            Switch_Open(channel_No, I2C_L);

            //I2C configuration
            Init(I2C_R);
            Init(I2C_L);
            VL6180X_W(I2C_R, 0x0014, 0x04);// SYSTEM__INTERRUPT_CONFIG_GPIO, range reading: new sample ready
            VL6180X_W(I2C_R, 0x0018, 0x01);// SYSRANGE__START, single-shot range mode start signal
            VL6180X_W(I2C_L, 0x0014, 0x04); // SYSTEM__INTERRUPT_CONFIG_GPIO, range reading: new sample ready
            VL6180X_W(I2C_L, 0x0018, 0x01); // SYSRANGE__START, single-shot range mode start signal
            while ((VL6180X_R(I2C_R, 0x004f,1) & 0x04 == 0)&&(VL6180X_R(I2C_L, 0x004f,1) & 0x04 == 0))
                Task_sleep(30);
            distance_R[i]=VL6180X_R(I2C_R, 0x0062,1); // 0x0062 is the address of sensor data register
            distance_L[i]=VL6180X_R(I2C_L, 0x0062,1); // 0x0062 is the address of sensor data register
            printf("The data detected by RHS sensor %d is %d and the data detected by LHS sensor %d is %d\n", i, distance_R[i], i, distance_L[i]);
            //para = rxBuffer[i];
            VL6180X_W(I2C_R, 0x0015, 0x07);// clear all the interrupt bit.
            VL6180X_W(I2C_L, 0x0015, 0x07);
            System_flush();
            if(channel_No<8)
                channel_No=channel_No<<1;
            else
                channel_No=0x01;

        }

    }
    I2C_close(I2C_R);
    I2C_close(I2C_L);
    System_flush();
}









