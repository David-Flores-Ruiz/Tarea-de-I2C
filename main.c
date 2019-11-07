/*
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * @file    T11_I2C_vClass.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "MK64F12.h"
#include "I2C.h"

#define SYSTEM_CLOCK (21000000U)
#define BAUD_RATE (9600U)

/*
 * @brief   Application entry point.
 */
int main(void) {
	I2C_init(I2C_0, SYSTEM_CLOCK, BAUD_RATE);


  	/* Init board hardware. */




    return 0 ;
}
