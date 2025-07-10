/*
 * bsp.h
 *
 *  Created on: Jul 10, 2025
 *      Author: Tachlog
 */

#ifndef BSP_BOARD_BSP_H_
#define BSP_BOARD_BSP_H_

#include "main.h"

HAL_StatusTypeDef sendCmdEsp(uint8_t * commands , uint16_t size);


#endif /* BSP_BOARD_BSP_H_ */
