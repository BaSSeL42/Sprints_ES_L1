/*
 * motor_Config.c
 *
 *  Created on: Apr 4, 2023
 *      Author: hp
 */

#include "motor_cfg.h"



str_motorPin_t motorPin = {
		.motor1_1 = DIO_PINA_0,
		.motor1_2 = DIO_PINA_1,
		.motor2_1 = DIO_PINA_2,
		.motor2_2 = DIO_PINA_3,
		.motor3_1 = DIO_PINA_4,
		.motor3_2 = DIO_PINA_5,
		.motor4_1 = DIO_PINA_6,
		.motor4_2 = DIO_PINA_7
};
