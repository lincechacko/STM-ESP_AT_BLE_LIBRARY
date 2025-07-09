/*
 * esp_ble.h
 *
 *  Created on: Jul 9, 2025
 *      Author: Lince
 */

#ifndef BSP_ESP_COMM_ESP_BLE_H_
#define BSP_ESP_COMM_ESP_BLE_H_


#define  CHECK_BLE_INIT_STATUS               "AT+BLEINIT?\r\n" /*check for the ble intit status*/
#define  BLE_INIT_CLIENT                     "AT+BLEINIT=1\r\n"
#define  BLE_INIT_SERVER                     "AT+BLEINIT=2\r\n"
#define  BLE_DEINIT                          "AT+BLEINIT=0\r\n"


typedef enum
{
	ESP_SUCCESS,
	ESP_TIMEOUT,
	ESP_ERROR
}ESP_AT_STATUS;

#endif /* BSP_ESP_COMM_ESP_BLE_H_ */
