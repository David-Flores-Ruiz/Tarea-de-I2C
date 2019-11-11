/*
 * @file:			I2C_vClass.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */

#include <stdio.h>
#include "MK64F12.h"
#include "GPIO.h"
#include "NVIC.h"
#include "bits.h"
#include "I2C.h"


#define SYSTEM_CLOCK (10500000U)
#define BAUD_RATE (9600U)

#define RTC_ADDRESS_WRITE (0xDE)	//** The last bit = 0, means Write */
#define RTC_ADDRESS_READ  (0xDF)	//** The last bit = 1, means Reade */

#define Enable_SEC (0x80)

#define RTC_SEC  (0x00)
#define RTC_MIN  (0x01)
#define RTC_HOUR (0x02)


int main(void) {


	I2C_init(I2C_0, SYSTEM_CLOCK, BAUD_RATE);
//	I2C_enable_interrupt();


	/**Sets the threshold for interrupts, if the interrupt has higher priority constant that the BASEPRI, the interrupt will not be attended*/
//	NVIC_set_basepri_threshold(PRIORITY_10);
//	NVIC_enable_interrupt_and_priotity(I2C0_IRQ,PRIORITY_9);	// Protocolo I2C
//	NVIC_global_enable_interrupts;


	uint8_t acknowledge = 0xF0;
	uint8_t dataFrom_MCP7940M_RTC = 0;


    while(1) {

    	I2C_start();	//** It configures de I2C in transmitting mode and generates the start signal */

    	I2C_write_byte(RTC_ADDRESS_WRITE);	//** Writing RTC address in the data register */
    	I2C_wait();	//** Checking if the I2C module is busy */
    	acknowledge = I2C_get_ack_or_nack();			/* Waiting for the acknowledge, this function is able to detect
    	// Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK
												         */


    	I2C_write_byte( RTC_SEC );	//** Writing the Register Address */
    	I2C_wait();	//** Checking if the I2C module is busy */
       	acknowledge = I2C_get_ack_or_nack();			/* Waiting for the acknowledge, this function is able to detect
        // Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK


												         */
       	I2C_write_byte(Enable_SEC);	//** Writing the Register Address */
       	I2C_wait();	//** Checking if the I2C module is busy */
       	acknowledge = I2C_get_ack_or_nack();			// Waiting for the acknowledge, this function is able to detect
    	I2C_stop();	//** Generating stop signal */



    	I2C_start();	//** It configures de I2C in transmitting mode and generates the start signal */

    	I2C_write_byte(RTC_ADDRESS_WRITE);	//** Writing RTC address in the data register */
        I2C_wait();	//** Checking if the I2C module is busy */
        acknowledge = I2C_get_ack_or_nack();

    	I2C_write_byte( RTC_SEC );	//** Writing the Register Address */
    	I2C_wait();	//** Checking if the I2C module is busy */
       	acknowledge = I2C_get_ack_or_nack();
        // Return 0: if an acknowledge was received!!!



       	I2C_repeted_start();	// Generating a new start
       	I2C_write_byte(RTC_ADDRESS_READ);	//** Writing slave in order to read the previous register */
    	I2C_wait();	//** Checking if the I2C module is busy */
       	acknowledge = I2C_get_ack_or_nack();			/* Waiting for the acknowledge, this function is able to detect
        // Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK
												         */

       	I2C_tx_rx_mode(I2C_RX_mode);	//** Changing I2C module to receiver mode */


       	I2C_nack_or_ack(Nacknowledge);	//** Generating not acknowledge */
       	dataFrom_MCP7940M_RTC = I2C_read_byte();	//** Dummy read */
    	I2C_wait();	//** Checking if the I2C module is busy */

    	I2C_stop();	//** Generating stop signal */

    	dataFrom_MCP7940M_RTC = I2C_read_byte();	//** Reading the true value */


    }

    return 0 ;
}

