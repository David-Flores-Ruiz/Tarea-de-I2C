/*
 * I2C.c
 *
 *  Created on: Nov 6, 2019
 *      Author: David Ruiz
 */


#include "I2C.h"


void I2C_init(i2c_channel_t channel, uint32_t system_clock, uint16_t baud_rate) {
	if (I2C_0 == channel) {
		SIM->SCGC4 |= I2C0_CLOCK_GATING;	/* Bit_6 = 0x40h*/
		/**	Configurar el Clock Gating de los perifericos GPIO a utilizar */
		GPIO_clock_gating(GPIO_B);
		/** Utiliza la alternativa 2 para I2C_SCL(reloj) y I2C_SDA(datos) */
		gpio_pin_control_register_t I2C_config = GPIO_MUX2;
		/** Asignamos los pines de salidas del protocolo de comunicacion I2C */
		GPIO_pin_control_register(GPIO_B, bit_2, &I2C_config);
		GPIO_pin_control_register(GPIO_B, bit_3, &I2C_config);
		GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, bit_2); //SCL Reloj
		GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, bit_3); //SDA Dato




	}
	if (I2C_1 == channel) {
		SIM->SCGC4 |= SIM_SCGC4_I2C1_MASK;	/* Bit_7 = 0x80h*/
	}
	if (I2C_2 == channel) {
		SIM->SCGC1 |= SIM_SCGC1_I2C2_MASK;	/* Bit_6 = 0x40h*/
	}
}
