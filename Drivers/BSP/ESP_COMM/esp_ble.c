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
#include <stdio.h>
#include <string.h>

EN_CURRENT_ESP_AT_CMD currentTransmitterCmd = DEFINE_ZERO; /*variable to check which command is transmitted*/
char espReceivedBuffer[200] = {0};

ESP_HAL_CONFIG  esp_config = {
		sendCmdEsp
};

/**
  * @brief  intialize the ble in esp
  * @param  bleInit_mode : mode to initialize the uart
  * @retval return the transmission is success or not
  */
ST_ESP_RETURN bleInitialize (EN_ESP_BLE_INIT bleInit_mode)
{
	ST_ESP_RETURN espReturn = {DEFINE_ZERO};
	HAL_StatusTypeDef status = DEFINE_ZERO;
	switch(bleInit_mode)
	{
		case ESP_BLE_INIT_CLIENT: /*if initialize as a client*/
		{
			status = esp_config.sendCmdUart((uint8_t *)BLE_INIT_CLIENT, sizeof(BLE_INIT_CLIENT));
			espReturn.currentCmd = CMD_BLE_INIT_CLIENT;
			break;
		}
		case ESP_BLE_INIT_SERVER:  /*if initialize as a server*/
		{
			status = esp_config.sendCmdUart((uint8_t *)BLE_INIT_SERVER, sizeof(BLE_INIT_CLIENT));
			espReturn.currentCmd = CMD_BLE_INIT_CLIENT;
			break;
		}
		default:
		{
			break;
		}
	}
	if(status) espReturn.status = ESP_BLE_ERROR;
	else espReturn.status = ESP_BLE_SUCCESS;
	return(espReturn);
}


/**
  * @brief  deinitialize esp ble
  * @param  None
  * @retval return the transmission is success or not
  */
ST_ESP_RETURN ble_deinit(void)
{
	ST_ESP_RETURN espReturn = {DEFINE_ZERO};
	HAL_StatusTypeDef status = DEFINE_ZERO;
	/*de-initialize the esp ble*/
	status = esp_config.sendCmdUart((uint8_t *)BLE_DEINIT, sizeof(BLE_DEINIT));
	espReturn.currentCmd = CMD_BLE_DEINIT;
	if(status) espReturn.status = ESP_BLE_ERROR;
	else espReturn.status = ESP_BLE_SUCCESS;
	return(espReturn);
}


/**
  * @brief  sending command to get the ble connection status
  * @param  None
  * @retval return the transmission is success or not
  */
ST_ESP_RETURN sendCmdBle_connectionStatus(void)
{
	ST_ESP_RETURN espReturn = {DEFINE_ZERO};
	HAL_StatusTypeDef status = DEFINE_ZERO;
	status = esp_config.sendCmdUart((uint8_t *)BLE_GET_CONNECTION_STATUS, sizeof(BLE_GET_CONNECTION_STATUS));
	espReturn.currentCmd = CMD_BLE_GET_CONNECTION_STATUS;
	if(status) espReturn.status = ESP_BLE_ERROR;
	else espReturn.status = ESP_BLE_SUCCESS;
	return(espReturn);

}


/**
  * @brief  function get the BLE device name
  * @param  None
  * @retval return the transmission is success or not and command sent
  */
ST_ESP_RETURN bleGetDeviceName(void)
{
	ST_ESP_RETURN espReturn = {DEFINE_ZERO};
	HAL_StatusTypeDef status = DEFINE_ZERO;
	status = esp_config.sendCmdUart((uint8_t *)BLE_GET_DEVICE_NAME, sizeof(BLE_GET_DEVICE_NAME));
	espReturn.currentCmd = CMD_BLE_GET_DEVICE_NAME;
	if(status) espReturn.status = ESP_BLE_ERROR;
	else espReturn.status = ESP_BLE_SUCCESS;
	return(espReturn);
}



/**
  * @brief  function set the BLE device name
  * @param  deviceName : name to be given for the device
  * @retval return the transmission is success or not and command sent
  */
ST_ESP_RETURN bleSetDevice_name(char * deviceName)
{
	ST_ESP_RETURN espReturn = {DEFINE_ZERO};
	HAL_StatusTypeDef status = DEFINE_ZERO;
	char transmitBuffer[50] = {0};
	sprintf(transmitBuffer,"%s%s\r\n",BLE_SET_DEVICE_NAME,deviceName); /*copying the name to the buffer*/
	status = esp_config.sendCmdUart((uint8_t *)transmitBuffer, sizeof(BLE_SET_DEVICE_NAME)+sizeof(deviceName)+2); /*transmitting the data packet*/
	espReturn.currentCmd = CMD_BLE_SET_DEVICE_NAME;
	if(status) espReturn.status = ESP_BLE_ERROR;
	else espReturn.status = ESP_BLE_SUCCESS;
	return(espReturn);
}


/**
  * @brief  function to get the device address
  * @param  None
  * @retval return the transmission is success or not and command sent
  */
ST_ESP_RETURN bleGetDevice_address(void)
{
	ST_ESP_RETURN espReturn = {DEFINE_ZERO};
	HAL_StatusTypeDef status = DEFINE_ZERO;
	status = esp_config.sendCmdUart((uint8_t *)BLE_GET_DEVICE_ADDRESS, sizeof(BLE_GET_DEVICE_ADDRESS));
	espReturn.currentCmd = CMD_BLE_GET_DEVICE_ADDRESS;
	if(status) espReturn.status = ESP_BLE_ERROR;
	else espReturn.status = ESP_BLE_SUCCESS;
	return(espReturn);
}

/**
  * @brief  function set the BLE device address
  * @param  deviceAddressType : address type to be given for the device
  * @retval return the transmission is success or not and command sent
  */
ST_ESP_RETURN bleSetDevice_addressType(EN_BLE_ADDRESS_TYPE deviceAddressType)
{
	ST_ESP_RETURN espReturn = {DEFINE_ZERO};
	HAL_StatusTypeDef status = DEFINE_ZERO;
	if(deviceAddressType == BLE_ADDRESS_TYPE_PUBLIC)
	{
		status = esp_config.sendCmdUart((uint8_t *)BLE_SET_DEVICE_ADDRESS_TYPE_PUBLIC, sizeof(BLE_SET_DEVICE_ADDRESS_TYPE_PUBLIC));
		espReturn.currentCmd = CMD_BLE_SET_DEVICE_ADDRESS_TYPE_PUBLIC;
	}
	else if(deviceAddressType == BLE_ADDRESS_TYPE_RANDOM)
	{
		status = esp_config.sendCmdUart((uint8_t *)BLE_SET_DEVICE_ADDRESS_TYPE_RANDOM, sizeof(BLE_SET_DEVICE_ADDRESS_TYPE_RANDOM));
		espReturn.currentCmd = CMD_BLE_SET_DEVICE_ADDRESS_TYPE_RANDOM;
	}
	if(status) espReturn.status = ESP_BLE_ERROR;
	else espReturn.status = ESP_BLE_SUCCESS;
	return(espReturn);
}


/**
  * @brief  function to get the scanning parameters
  * @param  None
  * @retval return the transmission is success or not and command sent
  */
ST_ESP_RETURN bleGet_scanningParam(void)
{
	ST_ESP_RETURN espReturn = {DEFINE_ZERO};
	HAL_StatusTypeDef status = DEFINE_ZERO;
	status = esp_config.sendCmdUart((uint8_t *)BLE_GET_SCAN_PARAM, sizeof(BLE_GET_SCAN_PARAM));
	espReturn.currentCmd = CMD_BLE_GET_SCAN_PARAM;
	if(status) espReturn.status = ESP_BLE_ERROR;
	else espReturn.status = ESP_BLE_SUCCESS;
	return(espReturn);
}


/**
  * @brief  function to check for the response received from the ESP
  * @param  None
  * @retval return the command sent  is success or not.
  */
EN_ESP_BLE_STATUS checkCmdResponse_status(char *dataReceived , uint16_t length)
{
	for(int i = DEFINE_ZERO; i < length; i++)
	{
		if(dataReceived[i] == 'K' && dataReceived[i-1] == 'O')
		{
			return ESP_BLE_SUCCESS;
		}
	}
	return ESP_BLE_ERROR;
}
