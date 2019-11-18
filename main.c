/*
 * @file:			I2C_vClass.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */

#include "MK64F12.h"
#include <stdint.h>
#include <stdio.h>
#include "UART_driver.h"
#include "memoria.h"
#include "GPIO.h"
#include "NVIC.h"
#include "bits.h"
#include "string.h"
#include "I2C.h"
#include "RTC.h"
#include "TeraTerm.h"
#include "display.h"
#include "bluetooth.h"
#include "Submenu_matriz.h"





#define SYSTEM_CLOCK (10500000U)
#define BAUD_RATE (9600U)

/**This is mail box to received the information from the serial port*/
extern uart_mail_box_t g_mail_box_uart_0;
extern uart_mail_box_t g_mail_box_uart_4;
int main(void)
{
	/**Enables the clock of PortB in order to configures TX and RX of UART peripheral*/
	SIM->SCGC5 = SIM_SCGC5_PORTB_MASK;
	/**Configures the pin control register of pin16 in PortB as UART RX*/
	PORTB->PCR[16] = PORT_PCR_MUX(3);
	/**Configures the pin control register of pin16 in PortB as UART TX*/
	PORTB->PCR[17] = PORT_PCR_MUX(3);
	/**Configures UART 0 to transmit/receive at 11520 bauds with a 21 MHz of clock core*/


	UART_init (UART_0,  10200000, BD_115200);
	UART_init (UART_4,  10200000, BD_115200);
	printf("UART is configured");
	/**Enables the UART 0 interrupt*/
	UART_interrupt_enable(UART_0);
	UART_interrupt_enable(UART_4);
	/**Enables the UART 0 interrupt in the NVIC*/
	NVIC_enable_interrupt_and_priotity(UART0_IRQ, PRIORITY_10);
	NVIC_enable_interrupt_and_priotity(UART4_IRQ, PRIORITY_10);
	/**Enables interrupts*/
	NVIC_global_enable_interrupts;


//	TeraTerm_Menu(); /**Show the initial Menu for the User*/


	I2C_init(I2C_0, SYSTEM_CLOCK, BAUD_RATE);
//	display_init();
//	display_clear();

//	RTC_write_Seconds();	/** Configurado para Inicializar el registro de Segundos*/
//	RTC_write_Minutes();	/** Configurado para Inicializar el registro de Minutos */
//	RTC_write_Hours();		/** Configurado para Inicializar el registro de Horas */

	uint8_t RTC_Decimal_seconds = 0;
	uint8_t RTC_Decimal_minutes = 0;
	uint8_t RTC_Decimal_hours = 0;
	memoria_write_mensaje_to_memmory(mensaje_1);
	memoria_write_mensaje_to_memmory(mensaje_2);
	memoria_write_mensaje_to_memmory(mensaje_3);
	memoria_write_mensaje_to_memmory(mensaje_4);
	memoria_write_mensaje_to_memmory(mensaje_5);
    while (1) {
    	memoria_read_byte(mensaje_1);
    	memoria_read_byte(mensaje_2);
    	memoria_read_byte(mensaje_3);
    	memoria_read_byte(mensaje_4);
    	memoria_read_byte(mensaje_5);





//    	memoria_write_mensaje_to_memmory(mensaje_2);
//    	memoria_read(mensaje_2);






//    	RTC_read_Seconds();	//** Lee los segundos del RTC */
//    	RTC_Decimal_seconds = RTC_Get_Seconds(); //** In Decimal Format */
//    	printf("Segundos: %d \n", RTC_Decimal_seconds);
//    	RTC_read_Minutes();
//    	RTC_Decimal_minutes = RTC_Get_Minutes(); 	 //** In Decimal Format */
//    	RTC_read_Hours();	//** Lee las horas del RTC */
//       	RTC_Decimal_hours = RTC_Get_Hours(); 	 //** In Decimal Format */
//    	Submenu_matriz_horas_minutos(RTC_Decimal_hours,RTC_Decimal_minutes);



 //   	display_instruccion_debug(minutos_00,minutos_03);
//    	bluetoot_init();
//    	memoria_init();
 //   	memoria_read();
//    	display_instruccion_debug(0,0);
//    	display_horas();
 //   	movimiento();

    	//display_instruccion_debug(1);
//   	RTC_read_Hours();	//** Lee las horas del RTC */
//    	RTC_Decimal_hours = RTC_Get_Hours(); 	 //** In Decimal Format */
//    	printf("Horas: %d - ", RTC_Decimal_hours);

//    	RTC_read_Minutes(); //** Lee los minutos del RTC */
//    	RTC_Decimal_minutes = RTC_Get_Minutes(); //** In Decimal Format */
//    	printf("Minutos: %d - ", RTC_Decimal_minutes);

//		RTC_read_Seconds();	//** Lee los segundos del RTC */
//		RTC_Decimal_seconds = RTC_Get_Seconds(); //** In Decimal Format */
//		printf("Segundos: %d \n", RTC_Decimal_seconds);

//		TeraTerm_menu_FSM();

		/** Modulo de codice que hace la funcion de echo para recibir de
		 *  la terminal de TeraTerm que entra cuando escribes y envia el
		 *  valor ASCII de la tecla que presionaste en TeraTerm */

/*		if (g_mail_box_uart_4.flag) {
			//Sends to the PCA the received data in the mailbox
			UART_put_char(UART_4, g_mail_box_uart_0.mailBox);

			//clear the reception flag
			g_mail_box_uart_4.flag = 0;
		}*/



	}
    return 0 ;
}



