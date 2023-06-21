/*
 * adc.c
 *
 *  Created on: Jun 21, 2023
 *      Author: ISAAC
 */

#include "adc.h"
#include "stm32f401xe.h"


#define GPIOAEN				(1U<<0)
#define ADC1EN				(1U<<8)
#define ADC_CH1				(1U<<0)
#define ADC_SEQ_LEN			(0x00)
#define	CR2_ADON			(1U<<0)
#define CR2_SWSTART			(1<<30)
#define SR_EOC				(1U<<1)



void pa1_adc_init(void)
{

	/*Enable clock access to GPIOA*/

	RCC->AHB1ENR |=GPIOAEN;

	/*Set the mode of pa1 to analog*/
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);


	/*configure adc module*/
	/*enable clock access to adc*/
	RCC->APB2ENR |=ADC1EN;
	/*configure adc parameter*/
	/*conversion sequence start*/
	ADC1->SQR3 = ADC_CH1;
	/*conversion sequence length*/
	ADC1->SQR1 = ADC_SEQ_LEN;
	/*enable adc module*/
	ADC1->CR2 |= CR2_ADON;

}


void start_conversion(void)
{
	/*start adc conversion*/

	ADC1->CR2 |=CR2_SWSTART;

}



uint32_t adc_read(void)
{
	while(!(ADC1->SR & SR_EOC)){

	}

	return ADC1->DR;

}
