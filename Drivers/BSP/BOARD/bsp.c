/*******************************************************************************
* Title                 :   ESP BLE AT Driver
* Filename              :   espble.c
* Author                :   LINCE
* Origin Date           :   10/07/25
* Version               :   1.0.0
* Compiler              :   gcc
* Target                :   Generic
* Notes                 :   None
*
*
*******************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version      Author          Description
*  10/07/25   1.0.0       LINCE           Initial Release.
*
*******************************************************************************/
/**
  ******************************************************************************
  * @file    espble.c
  * @author  LINCE
  * @date    10/07/25
  * @brief   This file contains template for c file including the doxygen style
  * 			documentations.
  *
  * <br><b> - HISTORY OF CHANGES - </b>
  *
  * <table align="left" style="width:800px">
  * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
  * <tr><td> 14/01/2024 </td><td> 1.0.0            </td><td> SKP      </td><td> Module Created </td></tr>
  * </table><br><br>
  * <hr>
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright(c)  @TachlogPvtLtd.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */


#include "bsp.h"
#include "esp_ble.h"

extern UART_HandleTypeDef huart1;

uint8_t iDataRxUartbyte = 0;


void startReceiveData(void)
{
	HAL_UART_Receive_IT(&huart1, &iDataRxUartbyte, 1);
}




HAL_StatusTypeDef sendCmdEsp(uint8_t * commands , uint16_t size)
{
	return (HAL_UART_Transmit(&huart1, commands, size, 1000));
}

