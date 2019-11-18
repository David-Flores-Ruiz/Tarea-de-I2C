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
	I2C_write_byte(Enable_OSC | SECONDS_30_hex);	//** Writing the Register Address */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack();// Waiting for the acknowledge, this function is able to detect
	I2C_stop();	//** Generating stop signal */
}

void RTC_read_Seconds(void)
{
	uint8_t aux_Unit = 0;
	uint8_t aux_Tens = 0;
	uint8_t acknowledge = 0xF0;

	uint8_t dataFrom_MCP7940M_RTC = 0;
	I2C_start();//** It configures de I2C in transmitting mode and generates the start signal */

	I2C_write_byte(RTC_ADDRESS_WRITE);//** Writing RTC address in the data register */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack();

	I2C_write_byte( RTC_SEC );	//** Writing the Register Address */
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
	aux_Unit = dataFrom_MCP7940M_RTC & (~Enable_OSC); //** Delete MSB from oscillator */
	aux_Tens = aux_Unit;
	aux_Unit = (aux_Unit >> 0) & (0x0F); //** Units of Seconds*/
	aux_Tens = (aux_Tens >> 4) & (0x0F); //** Tens of Seconds */

	g_SEC = (aux_Tens * 10) + (aux_Unit * 1);
	//** g_SEC: Bit 6 - 4 = Contains a value from 0 to 5 */
	//**		Bit 3 - 0 = Contains a value from 0 to 9 */
}

uint8_t RTC_Get_Seconds (void) {
	uint8_t Seconds_in_decimal = g_SEC;
	return (Seconds_in_decimal);
}

void RTC_write_Minutes(void)
{
	uint8_t acknowledge = 0xF0;

	I2C_start();//** It configures de I2C in transmitting mode and generates the start signal */

	I2C_write_byte(RTC_ADDRESS_WRITE);//** Writing RTC address in the data register */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack(); /* Waiting for the acknowledge, this function is able to detect
	 // Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK
	 */

	I2C_write_byte( RTC_MIN );	//** Writing the Register Address */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack(); /* Waiting for the acknowledge, this function is able to detect
	 // Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK

	 */
	I2C_write_byte(Enable_OSC | MINUTES_59_hex);	//** Writing the Register Address */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack();// Waiting for the acknowledge, this function is able to detect
	I2C_stop();	//** Generating stop signal */
}

void RTC_read_Minutes(void)
{
	uint8_t aux_Unit = 0;
	uint8_t aux_Tens = 0;
	uint8_t acknowledge = 0xF0;

	uint8_t dataFrom_MCP7940M_RTC = 0;
	I2C_start();//** It configures de I2C in transmitting mode and generates the start signal */

	I2C_write_byte(RTC_ADDRESS_WRITE);//** Writing RTC address in the data register */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack();

	I2C_write_byte( RTC_MIN );	//** Writing the Register Address */
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
	aux_Unit = dataFrom_MCP7940M_RTC & (~Enable_OSC); //** Delete MSB from oscillator */
	aux_Tens = aux_Unit;
	aux_Unit = (aux_Unit >> 0) & (0x0F); //** Units of Minutes*/
	aux_Tens = (aux_Tens >> 4) & (0x0F); //** Tens of Minutes */

	g_MIN = (aux_Tens * 10) + (aux_Unit * 1);
	//** g_MIN: Bit 6 - 4 = Contains a value from 0 to 5 */
	//**		Bit 3 - 0 = Contains a value from 0 to 9 */
}

uint8_t RTC_Get_Minutes (void) {
	uint8_t Minutes_in_decimal = g_MIN;
	return (Minutes_in_decimal);
}

void RTC_write_Hours(void)
{
	uint8_t acknowledge = 0xF0;

	I2C_start();//** It configures de I2C in transmitting mode and generates the start signal */

	I2C_write_byte(RTC_ADDRESS_WRITE);//** Writing RTC address in the data register */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack(); /* Waiting for the acknowledge, this function is able to detect
	 // Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK
	 */

	I2C_write_byte( RTC_HOUR );	//** Writing the Register Address */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack(); /* Waiting for the acknowledge, this function is able to detect
	 // Return 0: if an acknowledge was received!!!	 * if an acknowledge was received by checking the RXAK

	 */
	I2C_write_byte(Enable_OSC | HOURS_23_hex);	//** Writing the Register Address */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack();// Waiting for the acknowledge, this function is able to detect
	I2C_stop();	//** Generating stop signal */
}

void RTC_read_Hours(void)
{
	uint8_t aux_Unit = 0;
	uint8_t aux_Tens = 0;
	uint8_t acknowledge = 0xF0;

	uint8_t dataFrom_MCP7940M_RTC = 0;
	I2C_start();//** It configures de I2C in transmitting mode and generates the start signal */

	I2C_write_byte(RTC_ADDRESS_WRITE);//** Writing RTC address in the data register */
	I2C_wait();	//** Checking if the I2C module is busy */
	acknowledge = I2C_get_ack_or_nack();

	I2C_write_byte( RTC_HOUR );	//** Writing the Register Address */
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
	aux_Unit = dataFrom_MCP7940M_RTC & (~Enable_OSC); //** Delete MSB from oscillator */
	aux_Tens = aux_Unit;
	aux_Unit = (aux_Unit >> 0) & (0x0F); //** Units of Hours*/
	aux_Tens = (aux_Tens >> 4) & (0x0F); //** Tens of Hours */

	g_HR = (aux_Tens * 10) + (aux_Unit * 1);
	//** g_HR:  Bit 5 - 4 = Contains a value from 0 to 2 */
	//**		Bit 3 - 0 = Contains a value from 0 to 9 */
}

uint8_t RTC_Get_Hours (void) {
	uint8_t Hours_in_decimal = g_HR;
	return (Hours_in_decimal);
}

