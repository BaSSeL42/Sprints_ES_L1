/*
 * HExtInt.h
 *
 *  Created on: Apr 5, 2023
 *      Author: hp
 */

#ifndef HAL_HEXTINT_HEXTINT_H_
#define HAL_HEXTINT_HEXTINT_H_

#include "../../MCAL/ExtInt/EXTINT_Interface.h"

typedef enum
{
	HEXTINT_NOK = 0,
	HEXTINT_OK

}enu_HExtIntError_t;



//typedef void(*ptr_func)(void);


enu_HExtIntError_t HExtInt_enInit(void);

enu_HExtIntError_t HExtInt_enCBF(ptr_func pFunc);



#endif /* HAL_HEXTINT_HEXTINT_H_ */
