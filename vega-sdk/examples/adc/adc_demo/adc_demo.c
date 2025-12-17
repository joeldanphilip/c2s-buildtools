

/***************************************************
* Module name: main.c
*
* Copyright 2020 Company CDAC(T)
* All Rights Reserved.
*
*  The information contained herein is confidential
* property of Company. The user, copying, transfer or
* disclosure of such information is prohibited except
* by express written agreement with Company.
*
*
* Module Description:
* SPI test pgm
*
***************************************************/

/*  Include section
*
*
***************************************************/
#include "adc.h"
#include "stdlib.h"
#include "config.h"

/**
 @file adc_demo.c
 @brief Contains routines for Read all ADC channel values and display it via UART
 */



/** 
 * @brief Read all ADC channel values and display it via UART..
 * @details 
 * @param[in] No input parameter 
 * @param[Out] No output parameter 
*/
void main (void)
{
	US adc_data = 0;
	float volt_per_division = 0.0008179;
	float result_volt; 
	printf("\n\r Reading ADC Channel 0 data\n\r");
	while(1)
	{			
		adc_data = adc_analogRead(A0);
		printf("after function %d\n",adc_data);	
		result_volt = (adc_data * volt_per_division);
		printf("after multiplication\n");	
		printf ("\r A0 data: %0.2f V", result_volt);
		udelay(6000);
	}
}




