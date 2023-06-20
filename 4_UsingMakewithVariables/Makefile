CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32f401_ls.ld -Wl,-Map=stm32_blink.map

final	:	stm32_blink.elf

main.o : main.c
	$(CC) $(CFLAGS) $^ -o $@

stm32f401_startup.o	:	stm32f401_startup.c 
	$(CC) $(CFLAGS) $^ -o $@

stm32_blink.elf	:	main.o 	stm32f401_startup.o
	$(CC) $(LDFLAGS)  $^ -o stm32_blink.elf 	

cake :
	openocd -f C:\msys64\mingw64\share\openocd\scripts\interface\stlink.cfg -f C:\msys64\mingw64\share\openocd\scripts\target\stm32f4x.cfg
clean: 
	cmd //C del -f *.o *.elf *.map
	