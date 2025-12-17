

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
 @file adc_sample_pgm.c
 @brief Contains routines for Read all ADC channel values and display it via UART
 */


/** @fn main
 * @brief Read all ADC channel values and display it via UART..
 * @details 
 * @param[in] No input parameter 
 * @param[Out] No output parameter 
*/
void main (void)
{
	UI adc_data = 0;
	while(1)
	{
				
		printf("\n\r Reading ADC Channel 0 data");
		adc_data = adc_analogRead(A0);
		printf ("\n\r A0 data: %x ", adc_data);
	
		printf("\n\r Reading ADC Channel 1 data");
		adc_data = adc_analogRead(A1);
		printf ("\n\r A1 data: %x ", adc_data);
	
		printf("\n\r Reading ADC Channel 2 data");
		adc_data = adc_analogRead(A2);
		printf ("\n\r A2 data: %x ", adc_data);
	
		printf("\n\r Reading ADC Channel 3 data");
		adc_data = adc_analogRead(A3);
		printf ("\n\r A3 data: %x ", adc_data);
	}
}




