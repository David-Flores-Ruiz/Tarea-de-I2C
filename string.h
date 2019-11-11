/*
 * @file:			string.h
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */


#ifndef STRING_H_
#define STRING_H_

#include <stdint.h>

typedef enum {
	SEC,  MIN,  HOUR,
} Kind_of_time_t;

typedef enum {
	CERO,  UNO,  DOS,   TRES, CUATRO,
	CINCO, SEIS, SIETE, OCHO, NUEVE,
} Index_array_t;


//* For print in Tera Term the string of the Time value */
void Time_to_String(int32_t tiempo, Kind_of_time_t TIPO_TIME);

//* Return the string of the time that you want to show */
uint8_t* Get_String_Time(Kind_of_time_t TIPO_TIME);

//* Get the char of the respect number of the Time */
uint8_t Number_to_Char(uint8_t entero);


#endif /* STRING_H_ */
