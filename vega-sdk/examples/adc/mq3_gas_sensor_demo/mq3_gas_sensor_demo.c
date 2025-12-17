/***************************************************


 Project Name	: MDP - Microprocessor Development Project
 Project Code	: HD083D
 Created		: 20-july-2021
 Filename		: MQ3_gas_sensor_demo.c
 Purpose		:  UART communication with MQ3 gas sensor
 Description	: Alchohol detection
 Author(s)		: Thomas Sebastian, C-DAC
 Email			: vega@cdac.in

 See LICENSE for license details.
 ***************************************************/

#include "adc.h"
#include "stdlib.h"
#include "config.h"
#include "led.h"
#include "gpio.h"

/**
 @file MQ3_gas_sensor_demo.c
 @brief Contains routines for Read all ADC channel values and display it via UART
 */

int threshold = 1700; //Please change the threshold according to the sensor

/** 
 * @brief Read all ADC channel values and display it via UART..
 * @details 
 * @param[in] No input parameter 
 * @param[Out] No output parameter 
*/
void main(void)
{
	US adc_data = 0;

	printf("\r Connect A0 of MQ3 to A0 pin in VEGA board & adjust threshold ");

	printf("\n\r Reading gas sensor\n\r");

	while (1)
	{
		adc_data = adc_analogRead(A0);
		//printf("\rvalue = %d",adc_data);

		if (adc_data >= threshold)
		{
			printf("\rAlcohol detected !!");
			on_LED(PIN_19);
		}
		else
		{
			printf("\r Alcohol Free   !!");
			off_LED(PIN_19);
		}
	}
}
