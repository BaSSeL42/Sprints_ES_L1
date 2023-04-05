
/*************************************************************************************************************
 * 								Includes
 ************************************************************************************************************/
#include "avr/interrupt.h"
#include "../../Common/std_types.h"
#include "../../Common/Bit_Math.h"
#include "TIMER_Private.h"
#include "TIMER_Interface.h"

/*************************************************************************************************************
 * 								Macros
 ************************************************************************************************************/
#define PRESCALLER_CLR_MSK		(0b11111000)
#define PRESCALLER_OFFSET		CS00
#define F_CPU			8000000UL

#define STOPPED			0
#define RUNNING			1

#define OVF_TICKS		256UL
#define MAX_TIM_MS		5000UL
/*************************************************************************************************************
 * 								Global/Static Variables
 ************************************************************************************************************/
static enu_timerPrescalar_t global_prescaller;
static Uint8_t global_timerStatus;
static Uint8_t global_ovf;
static Uint16_t preload;
static cbf_t  globalCallFunc = NULL;


static Uint16_t prescaller_map[6] = {
		0,
		1,
		8,
		64,
		256,
		1024
};

/*************************************************************************************************************
 * 							Function Implementation
 ************************************************************************************************************/
enu_timerStatus_t enuTimer0_init (enu_timerMode_t enTimerMode)
{
	enu_timerStatus_t errorStatus = TIMER_OK;

	if(enTimerMode < TIMER_MODE_INVALID)
	{
		switch (enTimerMode)
		{
		case OVF_MODE 				: ClrBit(TCCR0_REG, WGM01);ClrBit(TCCR0_REG, WGM00); break;
		case PHASE_CORRECT_PWM_MODE : ClrBit(TCCR0_REG, WGM01);SetBit(TCCR0_REG, WGM00); break;
		case CTC_MODE 				: SetBit(TCCR0_REG, WGM01);ClrBit(TCCR0_REG, WGM00); break;
		case FAST_PWM_MODE 			: SetBit(TCCR0_REG, WGM01);SetBit(TCCR0_REG, WGM00); break;
		default 					: errorStatus = TIMER_NOK; break;
		}
	}
	else
	{
		errorStatus = TIMER_NOK;
	}
	return errorStatus;
}


/*************************************************************************************************************/
enu_timerStatus_t u8Timer0_setPrescallar(enu_timerPrescalar_t Copy_enPrescal)
{
	enu_timerStatus_t errorStatus = TIMER_OK;
	Uint8_t temp_reg;
	if(Copy_enPrescal < TIMER_PRESCALR_INVALID)
	{
		global_prescaller = Copy_enPrescal;
		if (global_timerStatus == RUNNING)
		{
			temp_reg = TCCR0_REG;		 // read
			temp_reg &= PRESCALLER_CLR_MSK;  // mod
			temp_reg |=  global_prescaller << PRESCALLER_OFFSET; // mod
			TCCR0_REG |= temp_reg;		// write
		}
		else
		{
			/* do nothing */
		}
	}
	else
	{
		errorStatus = TIMER_NOK;
	}


	return errorStatus;

}

/*************************************************************************************************************/
enu_timerStatus_t vidTimer0_OvfIrqEnable(void)
{
	enu_timerStatus_t errorStatus = TIMER_OK;

	SetBit(TIMSK_REG, TOIE0);
	SetBit(SREG_REG, 7);

	return errorStatus;

}

/*************************************************************************************************************/
enu_timerStatus_t vidTimer0_OvfIrqDisable(void)
{
	enu_timerStatus_t errorStatus = TIMER_OK;

	ClrBit(TIMSK_REG, TOIE0);

	return errorStatus;
}

/*************************************************************************************************************/
enu_timerStatus_t vidTimer0_start(void)
{
	enu_timerStatus_t errorStatus = TIMER_OK;

	TCCR0_REG |=  global_prescaller << PRESCALLER_OFFSET;
	global_timerStatus  = RUNNING;

	return errorStatus;
}

/*************************************************************************************************************/
enu_timerStatus_t vidTimer0_stop(void)
{
	enu_timerStatus_t errorStatus = TIMER_OK;

	TCCR0_REG &=  PRESCALLER_CLR_MSK;
	global_timerStatus = STOPPED;

	return errorStatus;
}
/*************************************************************************************************************/
enu_timerStatus_t u8Timer0_setTime_ms(Uint32_t u32_time_ms)
{
	enu_timerStatus_t errorStatus = TIMER_OK;
	Uint32_t desired_ticks;
	Float32_t tick_time_ms;
	if( u32_time_ms < MAX_TIM_MS )
	{
		tick_time_ms = (Float32_t)prescaller_map[global_prescaller] / ((Uint32_t)F_CPU / 1000U)  ;
		desired_ticks = u32_time_ms / tick_time_ms;

		/* Compare ticks with OVF_ticks */
		if(desired_ticks == OVF_TICKS)
		{
			global_ovf = 1;
		}
		else if(desired_ticks < OVF_TICKS)
		{
			preload = OVF_TICKS - desired_ticks;
			TCNT0 = preload;
			global_ovf = 1;
		}
		else if(desired_ticks > OVF_TICKS)
		{
			global_ovf = (Uint8_t)(desired_ticks / OVF_TICKS);
			preload = (uint16_t)(OVF_TICKS - (desired_ticks % OVF_TICKS ));
			TCNT0 = preload;
			if (preload > 0U)
			{
				global_ovf++;
			}
		}
	}
		else
		{
			errorStatus = TIMER_NOK;
		}


		return errorStatus;
	}

/*************************************************************************************************************/
void vidTimer0_setcbf_OVF(cbf_t cbf)
{
	if (cbf != NULL)
	{
		globalCallFunc = cbf;
	}
	return;
}


/*************************************************************************************************************
 * 							ISR Interrupt Handling
 ************************************************************************************************************/
ISR(TIMER0_OVF_vect)
{
	static Uint8_t counter = 0;
	counter++;
	if(counter == global_ovf)
	{
		if (globalCallFunc != NULL)
		{
			counter = 0;

			globalCallFunc();
			TCNT0 = preload;
//			global_ovf = 0;
//			vidTimer1_stop();
		}
	}
}
