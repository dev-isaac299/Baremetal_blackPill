#include "stm32f4xx.h"
#include "adc.h"
#include "led.h"


uint32_t sensor_value;

int main(void){

	pa1_adc_init();
	start_conversion();


	while(1){

		start_conversion();
		sensor_value = adc_read();

	}

	return 0;


}
