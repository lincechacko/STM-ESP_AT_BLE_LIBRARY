/*******************************************************************************
* Title                 :   ESP BLE AT Driver
* Filename              :   espble.h
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
  * @file    espble.h
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

#ifndef BSP_ESP_BLE_SLAVE_ESPBLE_H_
#define BSP_ESP_BLE_SLAVE_ESPBLE_H_

#include "main.h"


#define DEFINE_ZERO                                               0

/*BLE INIT COMMANDS*/
#define BLE_CHECK_INIT_STATUS                                     "AT+BLEINIT?\r\n"
#define BLE_INIT_CLIENT                                           "AT+BLEINIT=1\r\n"
#define BLE_INIT_SERVER                                           "AT+BLEINIT=2\r\n"
#define BLE_DEINIT                                                "AT+BLEINIT=0\r\n"


/*Query/Set Bluetooth LE Device Address*/

#define BLE_GET_DEVICE_ADDRESS                                    "AT+BLEADDR?\r\n"
#define BLE_SET_DEVICE_ADDRESS_TYPE_PUBLIC                        "AT+BLEADDR=0\r\n"
#define BLE_SET_DEVICE_ADDRESS_TYPE_RANDOM                        "AT+BLEADDR=1\r\n"


/*Query/Set Bluetooth LE Device Name*/

#define BLE_GET_DEVICE_NAME                                       "AT+BLENAME?\r\n"
#define SET_GET_DEVICE_NAME                                       "AT+BLENAME="


/*Query/Set Parameters of Bluetooth LE Scanning*/

#define BLE_GET_SCAN_PARAM                                         "AT+BLESCANPARAM?\r\n"
#define BLE_SET_SCAN_PARAM                                         "AT+BLESCANPARAM="/*AT+BLESCANPARAM=<scan_type>,<own_addr_type>,<filter_policy>,<scan_interval>,<scan_window>*/

/*Enable Bluetooth LE Scanning*/

#define BLE_ENABLE_SCANNING                                         "AT+BLESCAN=1" /*AT+BLESCAN=<enable>[,<duration>][,<filter_type>,<filter_param>]*/
#define BLE_DISABLE_SCANNING                                        "AT+BLESCAN=0\r\n"
/* AT+BLEINIT=1    // Role: client
 * AT+BLESCAN=1    // start scanning
 * AT+BLESCAN=0    // stop scanning
 * AT+BLESCAN=1,3,1,"24:0A:C4:96:E6:88"  // start scanning, filter type is MAC address
 * AT+BLESCAN=1,3,2,"ESP-AT"  // start scanning, filter type is device name*/

/*Set Bluetooth LE Scan Response*/
#define BLE_SET_SCAN_RESPONSE                                       "AT+BLESCANRSPDATA="


/*Query/Set Parameters of Bluetooth LE Advertising*/

#define BLE_GET_ADV_PARAM                                            "AT+BLEADVPARAM?\r\n"
#define BLE_SET_ADV_PARAM                                            "AT+BLEADVPARAM="

#define BLE_SET_ADV_DATA                                             "AT+BLEADVDATA="      /*Set Bluetooth LE Advertising Data*/

#define BLE_GET_PARAM_ADV_DATA                                       "AT+BLEADVDATAEX?\r\n"/*Query the parameters of advertising data.*/
#define BLE_SET_SET_ADV_DATA_START_ADV                               "AT+BLEADVDATAEX="  /*Set the advertising data and start advertising.*//*<dev_name>,<uuid>,<manufacturer_data>,<include_power>*/
#define BLE_START_ADV                                                "AT+BLEADVSTART"

#define BLE_STOP_ADV                                                 "AT+BLEADVSTOP\r\n"
#define BLE_GET_CONNECTION_STATUS                                    "AT+BLECONN?\r\n"

#define BLE_GET_CONNECTION_PARAM                                     "AT+BLECONNPARAM?\r\n"
#define BLE_SET_CONNECTION_PARAM                                     "AT+BLECONNPARAM="/*=<conn_index>,<min_interval>,<max_interval>,<latency>,<timeout>*/

#define BLE_END_CONNECTION                                           "AT+BLEDISCONN=" /*=<conn_index>*/

#define BLE_GET_MTU_LENGHT                                           "AT+BLECFGMTU?\r\n" /*to get the length of the MTU*/
#define BLE_SET_MTU_LENGHT                                           "AT+BLECFGMTU=" /*to set the length of the MTU*/
/*-  Bluetooth LE connection has to be established first.
-  Only the client can call this command to set the length of MTU.*/
#define BLE_GET_GATT_DISCOVER_SERVICE                                "AT+BLEGATTSSRV?\r\n" /*GATTS Discovers Services :<srv_index>,<start>,<srv_uuid>,<srv_type>*/
#define BLE_GATT_DISCOVER_CHARACTERISTICS                            "AT+BLEGATTSCHAR?\r\n"


/*ENUM for the last transmitted command*/
typedef enum
{
	CMD_BLE_NONE,
	CMD_BLE_CHECK_INIT_STATUS ,
	CMD_BLE_INIT_CLIENT,
	CMD_BLE_DEINIT,
	CMD_BLE_GET_CONNECTION_STATUS

}EN_CURRENT_ESP_AT_CMD;

/*status of the BLE transmission*/
typedef enum
{
	ESP_BLE_SUCCESS,
	ESP_BLE_TIMEOUT,
	ESP_BLE_ERROR
}EN_ESP_BLE_STATUS;

/*ENUM for the BLE initialization*/
typedef enum
{
	ESP_BLE_INIT_CLIENT,
	ESP_BLE_INIT_SERVER,
	ESP_BLE_INIT_DEINIT,

}EN_ESP_BLE_INIT;

typedef enum
{
	ESP_ERROR,
	ESP_BLE_NO_CONNECTION,
	ESP_BLE_CONNECTION_SUCCESS,
}EN_ESP_BLE_CONNECTION_STATUS;


typedef struct
{
	EN_ESP_BLE_CONNECTION_STATUS bleConnectionStatus;
	uint16_t  iconnectionIndex;
	uint8_t * iremoteaddress;
}ST_ESP_CONNECTION_STATUS;


typedef struct
{
	HAL_StatusTypeDef(*sendCmdUart) (uint8_t* command , uint16_t size);
}ESP_HAL_CONFIG;

















#endif /* BSP_ESP_BLE_SLAVE_ESPBLE_H_ */
