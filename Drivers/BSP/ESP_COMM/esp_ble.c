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

#include "esp_ble.h"
#include "bsp.h"


EN_CURRENT_ESP_AT_CMD currentTransmitterCmd = DEFINE_ZERO; /*variable to check which command is transmitted*/


ESP_HAL_CONFIG  esp_config = {
		sendCmdEsp
};

/**
  * @brief  intialize the ble in esp
  * @param  bleInit_mode : mode to initialize the uart
  * @retval return the transmission is success or not
  */
EN_ESP_BLE_STATUS bleInitialize (EN_ESP_BLE_INIT bleInit_mode)
{
	HAL_StatusTypeDef status = DEFINE_ZERO;
	switch(bleInit_mode)
	{
		case ESP_BLE_INIT_CLIENT: /*if initialize as a client*/
		{
			status = esp_config.sendCmdUart((uint8_t *)BLE_INIT_CLIENT, sizeof(BLE_INIT_CLIENT));
			currentTransmitterCmd = CMD_BLE_INIT_CLIENT;
			break;
		}
		case ESP_BLE_INIT_SERVER:  /*if initialize as a server*/
		{
			status = esp_config.sendCmdUart((uint8_t *)BLE_INIT_SERVER, sizeof(BLE_INIT_CLIENT));
			currentTransmitterCmd = CMD_BLE_INIT_CLIENT;
			break;
		}
		default:
		{
			return (ESP_BLE_ERROR);
			break;
		}
	}
	if(!status) return (ESP_BLE_ERROR);
	return (ESP_BLE_SUCCESS);
}


/**
  * @brief  deinitialize esp ble
  * @param  None
  * @retval return the transmission is success or not
  */
EN_ESP_BLE_STATUS ble_deinit(void)
{
	HAL_StatusTypeDef status = DEFINE_ZERO;
	/*de-initialize the esp ble*/
	status = esp_config.sendCmdUart((uint8_t *)BLE_DEINIT, sizeof(BLE_DEINIT));
	currentTransmitterCmd = CMD_BLE_DEINIT;
	if(!status) return (ESP_BLE_ERROR);
	return (ESP_BLE_SUCCESS);
}


/**
  * @brief  sending command to get the ble connection status
  * @param  None
  * @retval return the transmission is success or not
  */
EN_ESP_BLE_STATUS sendCmdBle_connectionStatus(void)
{
	HAL_StatusTypeDef status = DEFINE_ZERO;
	status = esp_config.sendCmdUart((uint8_t *)BLE_GET_CONNECTION_STATUS, sizeof(BLE_GET_CONNECTION_STATUS));
	currentTransmitterCmd = CMD_BLE_GET_CONNECTION_STATUS;
	if(!status) return (ESP_BLE_ERROR);
	return (ESP_BLE_SUCCESS);

}
