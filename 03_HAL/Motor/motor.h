/*
 * motor.h
 *
 *  Created on: Apr 4, 2023
 *      Author: hp
 */

#ifndef HAL_MOTOR_MOTOR_H_
#define HAL_MOTOR_MOTOR_H_

typedef enum
{
	MOTOR_NOK = 0,
	MOTOR_OK

}enu_motorError_t;



enu_motorError_t HMotor_Init(void);

enu_motorError_t HMotor_moveForward(void);
enu_motorError_t HMotor_moveBackward(void);
enu_motorError_t HMotor_moveRight(void);
enu_motorError_t HMotor_moveLeft(void);

#endif /* HAL_MOTOR_MOTOR_H_ */
