/*
 * led.c
 *
 *  Created on: Jun 21, 2023
 *      Author: ISAAC
 */


#include "led.h"
#include "stm32f401xe.h"

#define PIN13				(1U<<13)
#define USER_LED			PIN13
#define GPIOCEN				(1U<<2)


void led_init(void)
{

	RCC->AHB1ENR |= GPIOCEN;

	GPIOC->MODER |=(1U<<26);
	GPIOC->MODER &=~(1U<<27);

}


void led_toggle(void)
{
	GPIOC->ODR ^= USER_LED;

	for(int i=0;i<2000000;i++){

	}
}
