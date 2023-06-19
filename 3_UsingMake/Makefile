target	:	stm32_blink.elf

main.o : main.c
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 main.c -o main.o

stm32f401_startup.o	:	stm32f401_startup.c 
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 stm32f401_startup.c -o stm32f401_startup.o

stm32_blink.elf	:	main.o 	stm32f401_startup.o
	arm-none-eabi-gcc -nostdlib -T stm32f401_ls.ld *.o -o stm32_blink.elf -Wl,-Map=stm32_blink.map	

cake :
	openocd -f C:\msys64\mingw64\share\openocd\scripts\interface\stlink.cfg -f C:\msys64\mingw64\share\openocd\scripts\target\stm32f4x.cfg