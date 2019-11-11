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

#define Enable_SEC (0x80)

#define RTC_SEC  (0x00)
#define RTC_MIN  (0x01)
#define RTC_HOUR (0x02)


void RTC_write_Seconds(void);

void RTC_read_Seconds(void);

#endif /* RTC_H_ */
