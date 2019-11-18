/*
 * @file:			RTC.h
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */


#ifndef RTC_H_
#define RTC_H_


#include <stdint.h>
#include "I2C.h"

#define SYSTEM_CLOCK (10500000U)
#define BAUD_RATE (9600U)

#define RTC_ADDRESS_WRITE (0xDE)	//** The last bit = 0, means Write */
#define RTC_ADDRESS_READ  (0xDF)	//** The last bit = 1, means Reade */

#define Enable_OSC (0x80)

#define RTC_SEC  (0x00)
#define RTC_MIN  (0x01)
#define RTC_HOUR (0x02)

//** Macros for propose to debug and modified the initial value of the Time registers */
#define SECONDS_30_hex (0x30)
#define MINUTES_59_hex (0x59)
#define HOURS_23_hex (0x23)

void RTC_write_Seconds(void); //**Inicializa los segundos*/
void RTC_read_Seconds(void);  //**Lee el registro de los segundos*/
uint8_t RTC_Get_Seconds (void); //** In Decimal format*/

void RTC_write_Minutes(void); //**Inicializa los minutos*/
void RTC_read_Minutes(void);  //**Lee el registro de los minutos*/
uint8_t RTC_Get_Minutes (void); //** In Decimal format*/

void RTC_write_Hours(void);   //**Inicializa los minutos*/
void RTC_read_Hours(void);	  //**Lee el registro de las horas*/
uint8_t RTC_Get_Hours (void);	//** In Decimal format*/

#endif /* RTC_H_ */
