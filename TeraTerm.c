/*
 * @file:			TeraTerm.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */


#include "UART_driver.h"
#include "TeraTerm.h"

static uint8_t instruction_1[] = "\033[0;35;43m";

void TeraTerm_Menu(void)
{
	/**The following sentences send strings to PC using the UART_put_string function. Also, the string
	 * is coded with terminal code*/
	/** VT100 command for text in red and background in cyan*/
	UART_put_string(UART_0,&instruction_1);
	/*VT100 command for clearing the screen*/
	UART_put_string(UART_0,"\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_put_string(UART_0,"\033[0;32;41m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0,"\033[10;10H");
	UART_put_string(UART_0, "SISTEMAS EMBEBIDOS I\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0,"\033[11;10H");
	UART_put_string(UART_0, "    ITESO\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0,"\033[12;10H");
}

void TeraTerm_Actual_Time(void)
{

	uint8_t string_seconds[3] = "XY"; /*! String to be printed in the TeraTerm*/
	uint8_t string_minutes[3] = "XY"; /*! Minutes*/
	uint8_t string_hours[3] = "XY"; /*! Hours*/

	uint8_t* ptr_string_seconds = Get_String_Time(SEC);
	uint8_t* ptr_string_minutes = Get_String_Time(MIN);
	uint8_t* ptr_string_hours = Get_String_Time(HOUR);

//	LCD_nokia_goto_xy(0, 0); /*! It establishes the position to print the messages in the LCD*/
//	LCD_nokia_send_string(ptr_string_FREC);

}
