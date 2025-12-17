/***************************************************************************
 * Project                               :  MDP
 * Name of the file                      :  adc.c
 * Brief Description of file             :  Driver to read the ADC value.
 * Name of Author                        :  Sreeju G R
 * Email ID                              :  sreeju@cdac.in

  Copyright (C) 2020  CDAC(T). All rights reserved.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

***************************************************************************/


#include <include/stdlib.h>
#include <include/adc.h>
#include <include/config.h>

/**
 @file adc.c
 @brief Contains routines to read ADC values
 */

/** @fn UI adc_analogRead(UC adc_channel_number)
  @brief  Read ADC value.
  @details The selected ADC returns the value as 32 bit data.
  @param[in] unsigned char adc_channel_number: The channel number from where ADC value to be read.
  @return Returns ADC data
*/

UI adc_analogRead(UC adc_channel_number)
{
	UI adc_data = 0;
	
	printf("analog read function\n");
	if((adc_channel_number >= 0) && (adc_channel_number <= 3))
	{
		switch (adc_channel_number)
		{
			case 0:
				printf("adc_channel_number 0\n");
				ADCReg.address_reg = 0x14;	
				printf("adc_channel_number 0 after write\n");		// Address of A0
				while((ADCReg.status_reg & 0x1) != 0x1);	// Waiting for ADC status reg LSB to set.
				adc_data = ADCReg.data_reg;
				printf("adc_channel_number 0 after read\n");			// Read ADC data.
				break;
			case 1:
				ADCReg.address_reg = 0x15;			// Address of A1
				while((ADCReg.status_reg & 0x1) != 0x1);	// Waiting for ADC status reg LSB to set.
				adc_data = ADCReg.data_reg;			// Read ADC data.
				break;	
			case 2:
				ADCReg.address_reg = 0x16;			// Address of A2
				while((ADCReg.status_reg & 0x1) != 0x1);	// Waiting for ADC status reg LSB to set.
				adc_data = ADCReg.data_reg;			// Read ADC data.
				break;
			case 3:
				ADCReg.address_reg = 0x17;			// Address of A3
				while((ADCReg.status_reg & 0x1) != 0x1);	// Waiting for ADC status reg LSB to set.
				adc_data = ADCReg.data_reg;			// Read ADC data.
				break;
			default:
				break;
		}
		return adc_data;						// return read data.
	}
}

 
