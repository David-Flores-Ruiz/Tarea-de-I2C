/*
 * @file:			I2C_vClass.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */

#include "MK64F12.h"
#include <stdint.h>
#include <stdio.h>

#include "GPIO.h"
#include "NVIC.h"
#include "bits.h"
#include "string.h"
//#include "I2C.h"
#include "UART.h"


#define SYSTEM_CLOCK (10500000U)
#define BAUD_RATE (9600U)

static uint8_t instruction_1[] = "\033[0;35;43m";

/**This is mail box to received the information from the serial port*/
extern uart_mail_box_t g_mail_box_uart_0;


int main(void) {
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

	/**Enables interrupts*/
	NVIC_global_enable_interrupts;


    while (1) {

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

