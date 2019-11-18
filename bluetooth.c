/*
 * bluetooth.c
 *
 *  Created on: 15 nov 2019
 *      Author: pacas
 */
#include "bluetooth.h"
#include "UART_driver.h"

void bluetoot_init(void){
	UART_put_string(UART_4,"1) Establecer Hora\r");
}

