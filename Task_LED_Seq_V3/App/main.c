/*
 * main.c
 *
 *  Created on: Apr 3, 2023
 *      Author: Bassel Yasser
 */
/*******************************************************************************
 * 								Includes
 ******************************************************************************/
#include <util/delay.h>
#include "../Common/std_types.h"
#include "../HAL/Button/button.h"
#include "../HAL/LED/led.h"
#include "../HAL/HExtInt/HExtInt.h"
#include "../HAL/HTimer/HTimer.h"

/*******************************************************************************
 * 								Macros
 ******************************************************************************/
#define LED_SEQ0		0
#define LED_SEQ1		1
#define LED_SEQ2		2
#define LED_SEQ3		3
#define LED_SEQ4		4
#define LED_SEQ5		5
#define LED_SEQ6		6
#define LED_SEQ7		7
#define LED_SEQ8		8
#define LED_SEQ9		9


/*******************************************************************************
 * 								Global Variables
 ******************************************************************************/
void ledDisplay(void);
void blink(void);
void changeBlinkTime(void);
/*******************************************************************************
 * 								Functions prototype
 ******************************************************************************/
Uint32_t blinkVersion;
Uint32_t time1 = 9;
Uint32_t time2 = 10;
Uint8_t gLEDSeq = LED_SEQ1;
/*******************************************************************************
 * 								main function
 ******************************************************************************/
int main(void)
{
	HLed_Init(DIO_PINC_0);
	HLed_Init(DIO_PINC_1);
	HLed_Init(DIO_PINC_2);
	HLed_Init(DIO_PINC_3);

	HButton_Init(DIO_PIND_2);
	HButton_Init(DIO_PIND_3);

	(void)HExtInt_enInit();
	(void)HTimer_enInit();

	(void)HExtInt_enCBF(ledDisplay);
	(void)HExtInt_enCBFInt1(changeBlinkTime);


	HLed_off(DIO_PINC_0);
	HLed_off(DIO_PINC_1);
	HLed_off(DIO_PINC_2);
	HLed_off(DIO_PINC_3);

	(void)HTimer_vidDelayMs(100);
	(void)HTimer_enCBF(blink);



	while(1)
	{

	}


	return 0;
}


/*******************************************************************************
 * 							Function Implementation
 ******************************************************************************/
/*
 * to choose led sequence
 */
void ledDisplay(void)
{
	static Uint8_t counter = 0;
	counter++;
	HLed_off(DIO_PINC_0);
	HLed_off(DIO_PINC_1);
	HLed_off(DIO_PINC_2);
	HLed_off(DIO_PINC_3);
	if(counter == LED_SEQ1)
	{
		gLEDSeq = LED_SEQ1;
	}
	else if(counter == LED_SEQ2)
	{
		gLEDSeq = LED_SEQ2;
	}
	else if(counter == LED_SEQ3)
	{
		gLEDSeq = LED_SEQ3;
	}
	else if(counter == LED_SEQ4)
	{
		gLEDSeq = LED_SEQ4;
	}
	else if(counter == LED_SEQ5)
	{
		gLEDSeq = LED_SEQ5;
	}
	else if(counter == LED_SEQ6)
	{
		gLEDSeq = LED_SEQ6;
	}
	else if(counter == LED_SEQ7)
	{
		gLEDSeq = LED_SEQ7;
	}
	else if(counter == LED_SEQ8)
	{
		gLEDSeq = LED_SEQ8;
		counter = 0;
	}
	else
	{
		/* do nothing */
	}


}
/*************************************************************************************/
/*
 * simulate LED on duration and LED off duration
 */
void blink(void)
{
	static Uint32_t counter = 0;
	counter++;
	if(counter == time1 )
	{
		if (gLEDSeq == LED_SEQ1)
		{
			HLed_toggle(DIO_PINC_0);
			HLed_off(DIO_PINC_1);
			HLed_off(DIO_PINC_2);
			HLed_off(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ2)
		{
			HLed_toggle(DIO_PINC_0);
			HLed_toggle(DIO_PINC_1);
			HLed_off(DIO_PINC_2);
			HLed_off(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ3)
		{
			HLed_toggle(DIO_PINC_0);
			HLed_toggle(DIO_PINC_1);
			HLed_toggle(DIO_PINC_2);
			HLed_off(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ4)
		{
			HLed_toggle(DIO_PINC_0);
			HLed_toggle(DIO_PINC_1);
			HLed_toggle(DIO_PINC_2);
			HLed_toggle(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ5)
		{
			HLed_off(DIO_PINC_0);
			HLed_toggle(DIO_PINC_1);
			HLed_toggle(DIO_PINC_2);
			HLed_toggle(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ6)
		{
			HLed_off(DIO_PINC_0);
			HLed_off(DIO_PINC_1);
			HLed_toggle(DIO_PINC_2);
			HLed_toggle(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ7)
		{
			HLed_off(DIO_PINC_0);
			HLed_off(DIO_PINC_1);
			HLed_off(DIO_PINC_2);
			HLed_toggle(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ8)
		{
			HLed_off(DIO_PINC_0);
			HLed_off(DIO_PINC_1);
			HLed_off(DIO_PINC_2);
			HLed_off(DIO_PINC_3);
		}
		else
		{

		}


	}else if(counter == time2)
	{
		if (gLEDSeq == LED_SEQ1)
		{
			HLed_toggle(DIO_PINC_0);
			HLed_off(DIO_PINC_1);
			HLed_off(DIO_PINC_2);
			HLed_off(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ2)
		{
			HLed_toggle(DIO_PINC_0);
			HLed_toggle(DIO_PINC_1);
			HLed_off(DIO_PINC_2);
			HLed_off(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ3)
		{
			HLed_toggle(DIO_PINC_0);
			HLed_toggle(DIO_PINC_1);
			HLed_toggle(DIO_PINC_2);
			HLed_off(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ4)
		{
			HLed_toggle(DIO_PINC_0);
			HLed_toggle(DIO_PINC_1);
			HLed_toggle(DIO_PINC_2);
			HLed_toggle(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ5)
		{
			HLed_off(DIO_PINC_0);
			HLed_toggle(DIO_PINC_1);
			HLed_toggle(DIO_PINC_2);
			HLed_toggle(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ6)
		{
			HLed_off(DIO_PINC_0);
			HLed_off(DIO_PINC_1);
			HLed_toggle(DIO_PINC_2);
			HLed_toggle(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ7)
		{
			HLed_off(DIO_PINC_0);
			HLed_off(DIO_PINC_1);
			HLed_off(DIO_PINC_2);
			HLed_toggle(DIO_PINC_3);
		}
		else if (gLEDSeq == LED_SEQ8)
		{
			HLed_off(DIO_PINC_0);
			HLed_off(DIO_PINC_1);
			HLed_off(DIO_PINC_2);
			HLed_off(DIO_PINC_3);
		}
		else
		{

		}
		counter = 0;
	}
}

/********************************************************************************/
/*
 * change duration of LED on and LED off
 */
void changeBlinkTime(void)
{
	time1--;
	time2++;

	if(time1 == 2)
	{
		time1 = 9;
		time2 = 10;
	}


}
