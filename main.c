/*
 * @file:			I2C_vClass.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */

#include "MK64F12.h"
#include <stdint.h>
#include <stdio.h>
#include "UART_driver.h"

#include "GPIO.h"
#include "NVIC.h"
#include "bits.h"
#include "string.h"
#include "I2C.h"
#include "RTC.h"
#include "TeraTerm.h"


#define SYSTEM_CLOCK (10500000U)
#define BAUD_RATE (9600U)


/**This is mail box to received the information from the serial port*/
extern uart_mail_box_t g_mail_box_uart_0;

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
	printf("UART is configured");
	/**Enables the UART 0 interrupt*/
	UART_interrupt_enable(UART_0);
	/**Enables the UART 0 interrupt in the NVIC*/
	NVIC_enable_interrupt_and_priotity(UART0_IRQ, PRIORITY_10);


	I2C_init(I2C_0, SYSTEM_CLOCK, BAUD_RATE);
	RTC_write_Seconds();	/** Configura para leer registro de Segundos*/


	/**Enables interrupts*/
	NVIC_global_enable_interrupts;


	TeraTerm_Menu(); /**Show the initial Menu for the User*/


    while (1) {

		RTC_read_Seconds();	// Lee los segundos del RTC

		if (g_mail_box_uart_0.flag)
		{
			/**Sends to the PCA the received data in the mailbox*/
			UART_put_char(UART_0, g_mail_box_uart_0.mailBox);

			/**clear the reception flag*/
			g_mail_box_uart_0.flag = 0;
		}

	}
    return 0 ;
}

