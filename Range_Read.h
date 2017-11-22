/*
 * Range_Read.h
 *
 *  Created on: 2017年10月16日
 *      Author: wangqi
 */

#ifndef RANGE_READ_H_
#define RANGE_READ_H_
void Switch_cfg();
void Switch_Open(uint8_t channel, I2C_Handle handle);
void VL6180X_W(I2C_Handle handle, uint16_t addr, uint8_t data);
void VL6180X_R(I2C_Handle handle, uint16_t addr, uint8_t *data, size_t length);
void Range_DetectFxn(UArg arg0, UArg arg1);
#endif /* RANGE_READ_H_ */
