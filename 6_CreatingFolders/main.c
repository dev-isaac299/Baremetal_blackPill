#include "stm32f401xe.h"

//where is the led connected?
//port:C
//pin: 13

#define GPIOCEN				(1U<<2)
#define PIN13				(1U<<13)
#define USER_LED			PIN13


int main(void)
{
	//1.Enable clock access to GPIOC
	//2.Set PC13 as output pin

	RCC->AHB1ENR |=GPIOCEN;

	GPIOC->MODER |=(1<<26);
	GPIOC->MODER &=~(1<<27);

	while(1)
	{
		
		GPIOC->ODR ^=USER_LED;
		for(int i=0;i<700000;i++){

		}


	}


}























































































