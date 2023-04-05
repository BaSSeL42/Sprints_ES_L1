/*
 * HTimer.c
 *
 *  Created on: Apr 5, 2023
 *      Author: Bassel Yasser
 */
/*************************************************************************************************************
 * 								Includes
 ************************************************************************************************************/
#include "../../Common/std_types.h"
#include "../../Common/Bit_Math.h"
#include "../../MCAL/Timer/TIMER_Interface.h"
#include "HTimer.h"

/*************************************************************************************************************
 * 							Function Implementation
 ************************************************************************************************************/
enu_HTimerError_t HTimer_enInit(void)
{
	enu_HTimerError_t errorStatus = TIMER_OK;

	(void)enuTimer0_init (OVF_MODE);
	(void)u8Timer0_setPrescallar(TIMER_PRE_256);
	(void)vidTimer0_OvfIrqEnable();

	return errorStatus;

}
/*************************************************************************************************************/
void HTimer_vidDelayMs( Uint32_t u32_delay )
{
	(void)u8Timer0_setTime_ms(u32_delay);
	(void)vidTimer0_start();
}
/*************************************************************************************************************/
enu_HTimerError_t HTimer_enCBF(ptr_funcc pFunc)
{
	enu_HTimerError_t errorStatus = TIMER_OK;

	if(pFunc != NULL)
	{
		vidTimer0_setcbf_OVF(pFunc);

	}else{
		errorStatus = TIMER_NOK;
	}

	return errorStatus;

}
/*************************************************************************************************************/
/*							End Of Implementation
*************************************************************************************************************/

