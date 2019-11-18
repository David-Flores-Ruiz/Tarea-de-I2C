/*
 * @file:			TeraTerm.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */


#include "UART_driver.h"
#include "TeraTerm.h"

static uint8_t instruction_1[] = "\033[0;35;43m";
extern uart_mail_box_t g_mail_box_uart_0;
static current_state = menu;
void TeraTerm_Menu(void)
{
	/**The following sentences send strings to PC using the UART_put_string function. Also, the string
	 * is coded with terminal code*/
	/** VT100 command for text in red and background in cyan*/
	UART_put_string(UART_0,&instruction_1);
	/*VT100 command for clearing the screen*/
	UART_put_string(UART_0,"\033[2J");
	/** VT100 command for text in red and background in green*/
	//UART_put_string(UART_0,"\033[0;32;41m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0,"\033[10;10H");
	UART_put_string(UART_0, "1) Establecer Hora\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0,"\033[11;10H");
	UART_put_string(UART_0, "2) Establecer Fecha\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0,"\033[12;10H");
	UART_put_string(UART_0, "3) Leer hora\r");
	UART_put_string(UART_0,"\033[13;10H");
	UART_put_string(UART_0, "4) Leer fecha\r");
	UART_put_string(UART_0,"\033[14;10H");
	UART_put_string(UART_0, "5) Escribir mensajes en memoria I2C\r");
	UART_put_string(UART_0,"\033[15;10H");
	UART_put_string(UART_0, "6) Mostrar hora en matriz de leds\r");
	UART_put_string(UART_0,"\033[16;10H");
	UART_put_string(UART_0, "7) Mostrar mensaje en matriz de leds\r");
}
void TeraTerm_Actual_Time(void)
{

	uint8_t string_seconds[3] = "XY"; /*! String to be printed in the TeraTerm*/
	uint8_t string_minutes[3] = "XY"; /*! Minutes*/
	uint8_t string_hours[3] = "XY"; /*! Hours*/

	uint8_t* ptr_string_seconds = Get_String_Time(SEC);
	uint8_t* ptr_string_minutes = Get_String_Time(MIN);
	uint8_t* ptr_string_hours = Get_String_Time(HOUR);
}
void TeraTerm_menu_FSM(void)
 {
	 if (g_mail_box_uart_0.flag) {
		/**Sends to the PCA the received data in the mailbox*/
		UART_put_char(UART_0, g_mail_box_uart_0.mailBox);
		/**clear the reception flag*/
		g_mail_box_uart_0.flag = 0;
		current_state = g_mail_box_uart_0.mailBox;

		switch (current_state) {
		case ESC:
			TeraTerm_Menu();
			break;
		case '1':
			UART_put_string(UART_0, "\033[2J"); //Clear
			UART_put_string(UART_0, "\033[10;10H"); //posicion
			UART_put_string(UART_0, "1) Establecer Hora\r");
			UART_put_string(UART_0,"\033[11;10H");
			UART_put_string(UART_0, "HH:MM:SS\r");
			break;
		case '2':
			UART_put_string(UART_0, "\033[2J"); //Clear
			UART_put_string(UART_0, "\033[10;10H"); //posicion
			UART_put_string(UART_0, "2) Establecer Fecha\r");
			UART_put_string(UART_0,"\033[11;10H");
			UART_put_string(UART_0, "DD/MM/AA\r");
			break;
		case '3':
			UART_put_string(UART_0, "\033[2J"); //Clear
			UART_put_string(UART_0, "\033[10;10H"); //posicion
			UART_put_string(UART_0, "3) Leer hora\r");
			UART_put_string(UART_0, "\033[11;10H"); //posicion
			UART_put_string(UART_0, " HH:MM:SS\r");
			break;
		case '4':
			UART_put_string(UART_0, "\033[2J"); //Clear
			UART_put_string(UART_0, "\033[10;10H"); //posicion
			UART_put_string(UART_0, "4) Leer fecha\r");
			UART_put_string(UART_0, "\033[11;10H"); //posicion
			UART_put_string(UART_0, "DD/MM/AA\r");
			break;
		case '5':
			UART_put_string(UART_0, "\033[2J"); //Clear
			UART_put_string(UART_0, "\033[10;10H"); //posicion
			UART_put_string(UART_0, "5) Escribir mensaje en memoria I2C\r");
			break;
		case '6':
			UART_put_string(UART_0, "\033[2J"); //Clear
			UART_put_string(UART_0, "\033[10;10H"); //posicion
			UART_put_string(UART_0, "6)Mostrar hora en matriz de leds\r");
			UART_put_string(UART_0, "\033[11;10H"); //posicion
			UART_put_string(UART_0, " HH:MM:SS\r");
			break;
		case '7':
			UART_put_string(UART_0, "\033[2J"); //Clear
			UART_put_string(UART_0, "\033[10;10H"); //posicion
			UART_put_string(UART_0, "7) Mostrar mensaje en matriz de leds\r");
			break;
		} //end switch
	} //end if
}


