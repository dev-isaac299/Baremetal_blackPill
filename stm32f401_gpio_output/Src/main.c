#include "stm32f4xx.h"


#define PIN13				(1U<<13)
#define USER_LED			PIN13
#define GPIOCEN				(1U<<2)


int main(void){

	RCC->AHB1ENR |= GPIOCEN;

	GPIOC->MODER |=(1U<<26);
	GPIOC->MODER &=~(1U<<27);


	while(1){

		GPIOC->ODR ^= USER_LED;

		for(int i=0;i<2000000;i++){

		}



	}

	return 0;


}
