/*
 * main.c
 *
 *  Created on: Apr 3, 2023
 *      Author: hp
 */

#include <util/delay.h>
#include "../Common/std_types.h"
#include "../HAL/Button/button.h"
#include "../HAL/LED/led.h"



int main(void)
{
	Uint8_t pressed;
	Uint8_t flag = 0;


	HLed_Init(DIO_PINC_0);
	HLed_Init(DIO_PINC_1);
	HLed_Init(DIO_PINC_2);
	HLed_Init(DIO_PINC_3);

	HButton_Init(DIO_PINA_6);

	HLed_off(DIO_PINC_0);
	HLed_off(DIO_PINC_1);
	HLed_off(DIO_PINC_2);
	HLed_off(DIO_PINC_3);


	while(1)
	{
		HButton_getPinVal(DIO_PINA_6, &pressed);
		if (!pressed)
		{
			_delay_ms(200);
			if ( !pressed)
			{
				if (flag == 0)
				{
					HLed_on(DIO_PINC_0);
					HLed_off(DIO_PINC_1);
					HLed_off(DIO_PINC_2);
					HLed_off(DIO_PINC_3);
					flag++;
				}
				else if (flag == 1)
				{
					HLed_on(DIO_PINC_0);
					HLed_on(DIO_PINC_1);
					HLed_off(DIO_PINC_2);
					HLed_off(DIO_PINC_3);
					flag++;
				}
				else if (flag == 2)
				{
					HLed_on(DIO_PINC_0);
					HLed_on(DIO_PINC_1);
					HLed_on(DIO_PINC_2);
					HLed_off(DIO_PINC_3);
					flag++;
				}
				else if (flag == 3)
				{
					HLed_on(DIO_PINC_0);
					HLed_on(DIO_PINC_1);
					HLed_on(DIO_PINC_2);
					HLed_on(DIO_PINC_3);
					flag++;
				}
				else if (flag == 4)
				{
					HLed_off(DIO_PINC_0);
					HLed_on(DIO_PINC_1);
					HLed_on(DIO_PINC_2);
					HLed_on(DIO_PINC_3);
					flag++;
				}
				else if (flag == 5)
				{
					HLed_off(DIO_PINC_0);
					HLed_off(DIO_PINC_1);
					HLed_on(DIO_PINC_2);
					HLed_on(DIO_PINC_3);
					flag++;
				}
				else if (flag == 6)
				{
					HLed_off(DIO_PINC_0);
					HLed_off(DIO_PINC_1);
					HLed_off(DIO_PINC_2);
					HLed_on(DIO_PINC_3);
					flag++;
				}
				else if (flag == 7)
				{
					HLed_off(DIO_PINC_0);
					HLed_off(DIO_PINC_1);
					HLed_off(DIO_PINC_2);
					HLed_off(DIO_PINC_3);
					flag = 0;
				}
				else
				{
					/* do nothing */
				}
			}
		}

	}


	return 0;
}
