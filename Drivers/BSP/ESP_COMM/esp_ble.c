/*
 * esp_ble.c
 *
 *  Created on: Jul 9, 2025
 *      Author: Lince
 */

#include "esp_ble.h"
#include "bsp.h"




ESP_AT_STATUS initialiseEspBle(void)
{
	transmitAT_commands((uint8_t *)CHECK_BLE_INIT_STATUS);

	return (ESP_SUCCESS);
}


