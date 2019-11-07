/*
 * @file:			I2C_vClass.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */

#include <stdio.h>
#include "MK64F12.h"
#include "I2C.h"


#define SYSTEM_CLOCK (21000000U)
#define BAUD_RATE (9600U)


int main(void) {

	I2C_init(I2C_0, SYSTEM_CLOCK, BAUD_RATE);



    while(1) {

    	////

    }



    return 0 ;
}

