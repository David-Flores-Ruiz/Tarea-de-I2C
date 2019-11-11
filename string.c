/*
 * @file:			string.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */


#include "string.h"


uint8_t g_decenas  = 0;
uint8_t g_unidades = 0;

#define STRING_SECONDS &string_time_secs[0]	// Direccion del arreglo de Segundos
#define STRING_MINUTES &string_time_mins[0] // Direccion de minutos
#define STRING_HOURS   &string_time_hrs[0]  // Direccion de horas

uint8_t string_time_secs[3] = "DU";
uint8_t string_time_mins[3] = "DU";
uint8_t string_time_hrs[3] =  "DU";
uint8_t string_dummy[ ] = "";


void Time_to_String(int32_t tiempo, Kind_of_time_t TIPO_TIME)
{
	g_decenas = tiempo / 10;
	g_unidades = (tiempo - (g_decenas * 10)) / 1;

	if (TIPO_TIME == SEC) {
		string_time_secs[0] = Number_to_Char(g_decenas);
		string_time_secs[1] = Number_to_Char(g_unidades);
	}

	if (TIPO_TIME == MIN) {
		string_time_mins[0] = Number_to_Char(g_decenas);
		string_time_mins[1] = Number_to_Char(g_unidades);
	}

	if (TIPO_TIME == HOUR) {
		string_time_hrs[0] = Number_to_Char(g_decenas);
		string_time_hrs[1] = Number_to_Char(g_unidades);
	}

}

uint8_t* Get_String_Time(Kind_of_time_t TIPO_TIME)
{
	uint8_t* ptr_String = 0x00;

	if (TIPO_TIME == SEC) {
		ptr_String = STRING_SECONDS;
	}

	if (TIPO_TIME == MIN) {
		ptr_String = STRING_MINUTES;
	}

	if (TIPO_TIME == HOUR) {
		ptr_String = STRING_HOURS;
	}

	return (ptr_String);
}

uint8_t Number_to_Char(uint8_t entero)
{
	switch (entero)
	{
		case CERO:
			string_dummy[0] = '0';
			break;
		case UNO:
			string_dummy[0] = '1';
			break;
		case DOS:
			string_dummy[0] = '2';
			break;
		case TRES:
			string_dummy[0] = '3';
			break;
		case CUATRO:
			string_dummy[0] = '4';
			break;
		case CINCO:
			string_dummy[0] = '5';
			break;
		case SEIS:
			string_dummy[0] = '6';
			break;
		case SIETE:
			string_dummy[0] = '7';
			break;
		case OCHO:
			string_dummy[0] = '8';
			break;
		case NUEVE:
			string_dummy[0] = '9';
			break;
		default:
			break;
	}
	return string_dummy[0];
}
