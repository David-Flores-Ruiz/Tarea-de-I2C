/*
 * @file:			TeraTerm.h
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */


#ifndef TERATERM_H_
#define TERATERM_H_

#include <stdint.h>
#include "string.h"

#define ESC 27
typedef enum {
	menu
} Index_menu_t;
//** For show the actual Menu for the user */
void TeraTerm_Menu(void);

//** For show the actual time in the terminal */
void TeraTerm_Actual_Time(void);
void TeraTerm_menu_FSM(void);


#endif /* TERATERM_H_ */
