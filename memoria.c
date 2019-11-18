/*
 * memoria.c
 *
 *  Created on: 15 nov 2019
 *      Author: pacas
 */
#include "I2C.h"
#include "MK64F12.h"
#include "bits.h"
#include "memoria.h"
#include "UART_driver.h"

uint8_t g_mensaje_1_array_read[30] ={'1','B','Z','B','A','B'};
uint8_t g_mensaje_2_array_read[30] ={'C','C'};
uint8_t g_mensaje_3_array_read[30] ={'Z','Y'};
uint8_t g_mensaje_4_array_read[30] ={'I','B'};
uint8_t g_mensaje_5_array_read[30] ={'R','S'};
uint8_t datafrommemmory_1[30] = {0};
uint8_t datafrommemmory_2[30] = {0};
uint8_t datafrommemmory_3[30] = {0};
uint8_t datafrommemmory_4[30] = {0};
uint8_t datafrommemmory_5[30] = {0};

void memoria_write(void){
	I2C_start(); //** It configures de I2C in transmitting mode and generates the start signal */
	I2C_write_byte(MEMMORY_WRITE);
	I2C_wait();
	I2C_write_byte(0x00);//ADDRESS HIGH
	I2C_wait();
	I2C_write_byte(0x30);//ADDRESS HIGH
	I2C_wait();
	I2C_write_byte(0xBB);
	I2C_wait();
	I2C_stop();
}
void memoria_write_mensaje_to_memmory(uint8_t num_mensaje){
	static uint8_t index_data = 0;
	switch(num_mensaje){
	case mensaje_1:
		I2C_start(); //** It configures de I2C in transmitting mode and generates the start signal */
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00);//ADDRESS HIGH
		I2C_wait();
		I2C_write_byte(0x00);//ADDRESS LOW
		I2C_wait();
		while(1){
			I2C_write_byte(g_mensaje_1_array_read[index_data]);
			I2C_wait();
			if(g_mensaje_1_array_read[index_data] == '\0'){
				index_data=0;
				I2C_stop();
				break;
			}
			index_data++;
			if(index_data==MAX){
				index_data=0;
				I2C_stop();
				break;
			}
		}
		break;
	case mensaje_2:
		I2C_start(); //** It configures de I2C in transmitting mode and generates the start signal */
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00); //ADDRESS HIGH
		I2C_wait();
		I2C_write_byte(0x30); //ADDRESS LOW
		I2C_wait();
		while (1) {
			I2C_write_byte(g_mensaje_2_array_read[index_data]);
			I2C_wait();
			if (g_mensaje_2_array_read[index_data] == '\0') {
				index_data = 0;
				I2C_stop();
				break;
			}
			index_data++;
			if (index_data == MAX) {
				index_data = 0;
				I2C_stop();
				break;
			}
		}
		break;
	case mensaje_3:
		I2C_start(); //** It configures de I2C in transmitting mode and generates the start signal */
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00); //ADDRESS HIGH
		I2C_wait();
		I2C_write_byte(0x60); //ADDRESS LOW
		I2C_wait();
		while (1) {
			I2C_write_byte(g_mensaje_3_array_read[index_data]);
			I2C_wait();
			if (g_mensaje_3_array_read[index_data] == '\0') {
				index_data = 0;
				I2C_stop();
				break;
			}
			index_data++;
			if (index_data == MAX) {
				index_data = 0;
				I2C_stop();
				break;
			}
		}

		break;
	case mensaje_4:
		I2C_start(); //** It configures de I2C in transmitting mode and generates the start signal */
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00); //ADDRESS HIGH
		I2C_wait();
		I2C_write_byte(0x90); //ADDRESS LOW
		I2C_wait();
		while (1) {
			I2C_write_byte(g_mensaje_4_array_read[index_data]);
			I2C_wait();
			if (g_mensaje_4_array_read[index_data] == '\0') {
				index_data = 0;
				I2C_stop();
				break;
			}
			index_data++;
			if (index_data == MAX) {
				index_data = 0;
				I2C_stop();
				break;
			}
		}

		break;
	case mensaje_5:
		I2C_start(); //** It configures de I2C in transmitting mode and generates the start signal */
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00); //ADDRESS HIGH
		I2C_wait();
		I2C_write_byte(0xC0); //ADDRESS LOW
		I2C_wait();
		while (1) {
			I2C_write_byte(g_mensaje_5_array_read[index_data]);
			I2C_wait();
			if (g_mensaje_5_array_read[index_data] == '\0') {
				index_data = 0;
				I2C_stop();
				break;
			}
			index_data++;
			if (index_data == MAX) {
				index_data = 0;
				I2C_stop();
				break;
			}
		}

	break;
	}
}
void memoria_read_byte(uint8_t num_mensaje){
	static uint8_t index_low = 0;
	static uint8_t addres_mensaje0 = 0x00;
	static uint8_t addres_mensaje1 = 0x30;
	static uint8_t addres_mensaje2 = 0x60;
	static uint8_t addres_mensaje3 = 0x90;
	static uint8_t addres_mensaje4 = 0xC0;
	switch (num_mensaje) {
	case mensaje_1:
		I2C_start();
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00);
		I2C_wait();
		I2C_write_byte(addres_mensaje0);
		I2C_wait();
		I2C_repeted_start();
		I2C_write_byte(MEMMORY_READ);
		I2C_wait();
		I2C_tx_rx_mode(I2C_RX_mode);
		I2C_nack_or_ack(Nacknowledge);
		datafrommemmory_1[index_low] = I2C_read_byte(); //dummy read
		I2C_wait();
		I2C_stop();
		datafrommemmory_1[index_low] = I2C_read_byte(); //dato read
		if(datafrommemmory_1[index_low] =='\0'){
			index_low=0;
			addres_mensaje0=0x00;
			break;
		}
		index_low++;
		addres_mensaje0++;
		break;
	case mensaje_2:
		I2C_start();
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00);
		I2C_wait();
		I2C_write_byte(addres_mensaje1);
		I2C_wait();
		I2C_repeted_start();
		I2C_write_byte(MEMMORY_READ);
		I2C_wait();
		I2C_tx_rx_mode(I2C_RX_mode);
		I2C_nack_or_ack(Nacknowledge);
		datafrommemmory_2[index_low] = I2C_read_byte(); //dummy read
		I2C_wait();
		I2C_stop();
		datafrommemmory_2[index_low] = I2C_read_byte(); //dato read
		if (datafrommemmory_2[index_low] == '\0') {
			index_low = 0;
			addres_mensaje1 = 0x30;
			break;
		}
		index_low++;
		addres_mensaje1++;
		break;
	case mensaje_3:
		I2C_start();
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00);
		I2C_wait();
		I2C_write_byte(addres_mensaje2);
		I2C_wait();
		I2C_repeted_start();
		I2C_write_byte(MEMMORY_READ);
		I2C_wait();
		I2C_tx_rx_mode(I2C_RX_mode);
		I2C_nack_or_ack(Nacknowledge);
		datafrommemmory_3[index_low] = I2C_read_byte(); //dummy read
		I2C_wait();
		I2C_stop();
		datafrommemmory_3[index_low] = I2C_read_byte(); //dato read
		if (datafrommemmory_3[index_low] == '\0') {
			index_low = 0;
			addres_mensaje2 = 0x60;
			break;
		}
		index_low++;
		addres_mensaje2++;
		break;
	case mensaje_4:
		I2C_start();
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00);
		I2C_wait();
		I2C_write_byte(addres_mensaje3);
		I2C_wait();
		I2C_repeted_start();
		I2C_write_byte(MEMMORY_READ);
		I2C_wait();
		I2C_tx_rx_mode(I2C_RX_mode);
		I2C_nack_or_ack(Nacknowledge);
		datafrommemmory_4[index_low] = I2C_read_byte(); //dummy read
		I2C_wait();
		I2C_stop();
		datafrommemmory_4[index_low] = I2C_read_byte(); //dato read
		if (datafrommemmory_4[index_low] == '\0') {
			index_low = 0;
			addres_mensaje3 = 0x90;
			break;
		}
		index_low++;
		addres_mensaje3++;
		break;
	case mensaje_5:
		I2C_start();
		I2C_write_byte(MEMMORY_WRITE);
		I2C_wait();
		I2C_write_byte(0x00);
		I2C_wait();
		I2C_write_byte(addres_mensaje4);
		I2C_wait();
		I2C_repeted_start();
		I2C_write_byte(MEMMORY_READ);
		I2C_wait();
		I2C_tx_rx_mode(I2C_RX_mode);
		I2C_nack_or_ack(Nacknowledge);
		datafrommemmory_5[index_low] = I2C_read_byte(); //dummy read
		I2C_wait();
		I2C_stop();
		datafrommemmory_5[index_low] = I2C_read_byte(); //dato read
		if (datafrommemmory_5[index_low] == '\0') {
			index_low = 0;
			addres_mensaje4 = 0xC0;
			break;
		}
		index_low++;
		addres_mensaje4++;
		break;
	} //end case
}//end funcion

