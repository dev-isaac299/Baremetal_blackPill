//where is the led connected?
//port:C
//pin: 13


#define PERIPH_BASE			(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL)
#define AHB1PERIPH_BASE 	(PERIPH_BASE+AHB1PERIPH_OFFSET)

#define GPIOA_OFFSET		(0x0UL)
#define GPIOC_OFFSET		(0x0800UL)

#define GPIOA_BASE			(AHB1PERIPH_BASE+GPIOA_OFFSET)
#define GPIOC_BASE			(AHB1PERIPH_BASE+GPIOC_OFFSET)


#define RCC_OFFSET			(0x00003800UL)
#define RCC_BASE			(AHB1PERIPH_BASE+RCC_OFFSET)

#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int *)(RCC_BASE+AHB1EN_R_OFFSET))

#define MODE_R_OFFSET		(0x00UL)
#define GPIOA_MODE_R		(*(volatile unsigned int *)(GPIOA_BASE+MODE_R_OFFSET))
#define GPIOC_MODE_R		(*(volatile unsigned int *)(GPIOC_BASE+MODE_R_OFFSET))


#define OD_R_OFFSET			(0x14UL)
#define GPIOA_OD_R			(*(volatile unsigned int *)(GPIOA_BASE+OD_R_OFFSET))
#define GPIOC_OD_R			(*(volatile unsigned int *)(GPIOC_BASE+OD_R_OFFSET))

#define GPIOAEN				(1U<<0)
#define GPIOCEN				(1U<<2)

#define PIN5				(1U<<5)
#define LED_PIN				PIN5

#define PIN13				(1U<<13)
#define USER_LED			PIN13


int main(void)
{
	//1.Enable clock access to GPIOA
	//2.Set PA5	as output pin


	//1.Enable clock access to GPIOC
	//2.Set PC13 as output pin


	RCC_AHB1EN_R |=GPIOAEN;
	RCC_AHB1EN_R |=GPIOCEN;

	GPIOA_MODE_R |=(1<<10);
	GPIOA_MODE_R &=~(1<<11);

	GPIOC_MODE_R |=(1<<26);
	GPIOC_MODE_R &=~(1<<27);



	while(1)
	{
		//GPIOA_OD_R |=LED_PIN;

		GPIOC_OD_R ^=USER_LED;
		for(int i=0;i<900000;i++){

		}


	}


}























































































