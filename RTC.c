/*
 * @file:			RTC.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */


#include "RTC.h"

	uint8_t g_SEC = 0;	// Listo para convertir a cadena con Time_to_String()
	uint8_t g_MIN = 0;
	uint8_t g_HR = 0;

void RTC_write_Seconds(void)
{
	uint8_t acknowledge = 0xF0;

	I2C_start();//** It configures de I2C in transmitting mode and generates the start signal */

	I2C_write_byte(RTC_ADDRESS_WRITE);//** Writing RTC address in the data register */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack(); /* Waiting for the acknowledge, this function is able to detect
	 // Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK
	 */

	I2C_write_byte( RTC_SEC);	//** Writing the Register Address */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack(); /* Waiting for the acknowledge, this function is able to detect
	 // Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK

	 */
	I2C_write_byte(Enable_SEC);	//** Writing the Register Address */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack();// Waiting for the acknowledge, this function is able to detect
	I2C_stop();	//** Generating stop signal */
}

void RTC_read_Seconds(void)
{
	uint8_t acknowledge = 0xF0;

	uint8_t dataFrom_MCP7940M_RTC = 0;
	I2C_start();//** It configures de I2C in transmitting mode and generates the start signal */

	I2C_write_byte(RTC_ADDRESS_WRITE);//** Writing RTC address in the data register */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack();

	I2C_write_byte( RTC_SEC);	//** Writing the Register Address */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack();
	// Return 0: if an acknowledge was received!!!

	I2C_repeted_start();	// Generating a new start
	I2C_write_byte(RTC_ADDRESS_READ);//** Writing slave in order to read the previous register */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack(); /* Waiting for the acknowledge, this function is able to detect
	 // Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK
	 */
	I2C_tx_rx_mode(I2C_RX_mode);	//** Changing I2C module to receiver mode */

	I2C_nack_or_ack(Nacknowledge);	//** Generating not acknowledge */
	dataFrom_MCP7940M_RTC = I2C_read_byte();	//** Dummy read */
	I2C_wait();	//** Checking if the I2C module is busy */

	I2C_stop();	//** Generating stop signal */

	dataFrom_MCP7940M_RTC = I2C_read_byte();	  //** Reading the true value */
	g_SEC = dataFrom_MCP7940M_RTC & (Enable_SEC); //** Delete MSB from oscillator */
	//** g_SEC: Bit 6 - 4 = Contains a value from 0 to 5 */
	//**		Bit 3 - 0 = Contains a value from 0 to 9 */
}
