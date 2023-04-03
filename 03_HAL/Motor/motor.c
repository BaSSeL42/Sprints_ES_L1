/*
 * motor.c
 *
 *  Created on: Apr 4, 2023
 *      Author: hp
 */


#include "../../05_Common/std_types.h"
#include "../../05_Common/Bit_Math.h"
#include "../../04_MCAL/DIO/DIO_Interface.h"
#include "motor.h"
#include "motor_cfg.h"

extern str_motorPin_t motorPin;



enu_motorError_t HMotor_Init(void)
{
	enu_motorError_t errorStatus = MOTOR_OK;

	DIO_s8SETPinDir( motorPin.motor1_1, OUTPUT );
	DIO_s8SETPinDir( motorPin.motor1_2, OUTPUT );
	DIO_s8SETPinDir( motorPin.motor2_1, OUTPUT );
	DIO_s8SETPinDir( motorPin.motor2_2, OUTPUT );
	DIO_s8SETPinDir( motorPin.motor3_1, OUTPUT );
	DIO_s8SETPinDir( motorPin.motor3_2, OUTPUT );
	DIO_s8SETPinDir( motorPin.motor4_1, OUTPUT );
	DIO_s8SETPinDir( motorPin.motor4_2, OUTPUT );

	return errorStatus;

}

enu_motorError_t HMotor_moveForward(void)
{

}


enu_motorError_t HMotor_moveBackward(void)
{

}



enu_motorError_t HMotor_moveRight(void)
{



}



enu_motorError_t HMotor_moveLeft(void)
{

}
