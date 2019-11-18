/*
 * memoria.h
 *
 *  Created on: 15 nov 2019
 *      Author: Ricardo
 */

#ifndef MEMORIA_H_
#define MEMORIA_H_
#include <stdio.h>
#include "MK64F12.h"
#define MEMMORY_WRITE (0xA0)
#define MEMMORY_READ (0xA1)
#define MAX (30)






typedef enum{
	mensaje_1 = 1,
	mensaje_2 = 2,
	mensaje_3 = 3,
	mensaje_4 = 4,
	mensaje_5 = 5,
}numero_mensaje_t;

void memoria_write(void);

void memoria_write_mensaje_to_memmory(uint8_t num_mensaje);
void memoria_read(uint8_t num_mensaje);
void memoria_read_byte(uint8_t num_mensaje);


#endif /* MEMORIA_H_ */
