/*
 * @file:			UART.c
 * @company:			ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */

#include "UART_driver.h"
#include "GPIO.h"
#include "bits.h"
 uart_mail_box_t g_mail_box_uart_0;
 uart_mail_box_t g_mail_box_uart_4;
void UART0_RX_TX_IRQHandler( )
{
	while (!(UART0->S1 & UART_S1_RDRF_MASK))
	{
		// Codigo Bloqueante
	}
	g_mail_box_uart_0.mailBox = UART0->D;
	g_mail_box_uart_0.flag = 1;
}
void UART4_RX_TX_IRQHandler( )
{
	while (!(UART4->S1 & UART_S1_RDRF_MASK))
	{
		// Codigo Bloqueante
	}
	g_mail_box_uart_4.mailBox = UART4->D;
	g_mail_box_uart_4.flag = 1;
}

void UART_init(uart_channel_t uart_channel, uint32_t system_clk, uart_baud_rate_t baud_rate)
{
	if (UART_0 == uart_channel) {
		SIM->SCGC4 |= 0x0400;
		UART0->C2  &= ~(UART_C2_TE_MASK);
		UART0->C2  &= ~(UART_C2_RE_MASK);
		UART0->BDH |= 0x00;
		UART0->BDL  = 0x0B; //seleccion de baudrate con el uso de las tablas
		UART0->C4 |= 0x0D;
		UART0->C2 |= UART_C2_TE_MASK | UART_C2_RE_MASK; //encendido para transmitir y recibir
	}
	if (UART_1 == uart_channel) {}
	if (UART_2 == uart_channel) {}
	if (UART_3 == uart_channel) {}
	if (UART_4 == uart_channel) {
		SIM->SCGC1 |= 0x0400;
		GPIO_clock_gating(GPIO_E);
		gpio_pin_control_register_t bluethooth_config = GPIO_MUX3;	// 100 de GPIO
		GPIO_pin_control_register(GPIO_E, bit_24, &bluethooth_config); //   - pin 24 TX
		GPIO_pin_control_register(GPIO_E, bit_25, &bluethooth_config); //   - pin 25 RX

		UART4->C2  &= ~(UART_C2_TE_MASK);
		UART4->C2  &= ~(UART_C2_RE_MASK);
		UART4->BDH |= 0x00;
		UART4->BDL  = 0x42; //seleccion de baudrate con el uso de las tablas 9600
		UART4->C4 |= 0x00;
		UART4->C2 |= UART_C2_TE_MASK | UART_C2_RE_MASK; //encendido para transmitir y recibir
	}
}

void UART_interrupt_enable(uart_channel_t uart_channel)
{
	if (UART_0 == uart_channel) {
		UART0->C2 |= UART_C2_RIE_MASK;//habilitacion de interrupcion
	}
	if (UART_1 == uart_channel) {}
	if (UART_2 == uart_channel) {}
	if (UART_3 == uart_channel) {}
	if (UART_4 == uart_channel) {
		UART4->C2 |= UART_C2_RIE_MASK;//habilitacion de interrupcion
	}
}

void UART_put_char (uart_channel_t uart_channel, uint8_t character)
{
	if (UART_0 == uart_channel) {
		while (!(UART0->S1 & UART_S1_TC_MASK))//utilizamos el codigo bloqueante para que  termine de transmitir
		{
			// Codigo Bloqueante
		}
		UART0->D = character;

	}
	if (UART_1 == uart_channel) {}
	if (UART_2 == uart_channel) {}
	if (UART_3 == uart_channel) {}
	if (UART_4 == uart_channel) {
		while (!(UART4->S1 & UART_S1_TC_MASK)) //utilizamos el codigo bloqueante para que  termine de transmitir
		{
			// Codigo Bloqueante
		}
		UART4->D = character;
	}
}
void UART_put_string(uart_channel_t uart_channel, int8_t* string)
{
	uint8_t contador_UART0 = 0;
	uint8_t contador_UART4 = 0;
	if (UART_0 == contador_UART0) {
		while (1) {
			if (string[contador_UART0] == '\0') //enviado de caracter  con variable contador qque ayuda a movernos sobre el string
					{
				break;
			}
			UART_put_char(uart_channel, string[contador_UART0]);
			contador_UART0++;
		}
	}
	if (UART_1 == uart_channel) {
	}
	if (UART_2 == uart_channel) {
	}
	if (UART_3 == uart_channel) {
	}
	if (UART_4 == uart_channel) {
		while (1) {
			if (string[contador_UART4] == '\0') //enviado de caracter  con variable contador qque ayuda a movernos sobre el string
					{
				break;
			}
			UART_put_char(uart_channel, string[contador_UART4]);
			contador_UART4++;
		}
	}
}

