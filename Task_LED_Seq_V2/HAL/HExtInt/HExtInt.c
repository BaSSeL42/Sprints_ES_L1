/*
 * HExtInt.c
 *
 *  Created on: Apr 5, 2023
 *      Author: hp
 */


#include "../../Common/std_types.h"
#include "../../Common/Bit_Math.h"
//#include "../../MCAL/ExtInt/EXTINT_Interface.h"
#include "HExtInt.h"


ptr_func cbf = NULL;

enu_HExtIntError_t HExtInt_enInit(void)
{
	enu_HExtIntError_t errorStatus = HEXTINT_OK;

	vidExtInt_init(INT_0 , FALL_EDGE );

	return errorStatus;

}

enu_HExtIntError_t HExtInt_enCBF(ptr_func pFunc)
{
	enu_HExtIntError_t errorStatus = HEXTINT_OK;

	if (pFunc != NULL)
	{
		vidCallBackFunc(pFunc);
	}
	else
	{
		errorStatus = HEXTINT_NOK;
	}


	return errorStatus;

}
