/*
 * @file:			TeraTerm.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */


#include "TeraTerm.h"

void TeraTerm_Actual_Time(void)
{

	uint8_t string_seconds[3] ="XY"; /*! String to be printed in the TeraTerm*/
	uint8_t string_seconds[3] ="XY";



	uint8_t* ptr_string_seconds = Get_String_Time(SEC);


	LCD_nokia_goto_xy(0, 0); /*! It establishes the position to print the messages in the LCD*/
	LCD_nokia_send_string(ptr_string_FREC);




}
