CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32f401_ls.ld -Wl,-Map=stm32_blink.map

build	:	prereq out/stm32_blink.elf

prereq	:	
	mkdir out

out/main.o : main.c
	$(CC) $(CFLAGS) $^ -o $@

out/stm32f401_startup.o	:	stm32f401_startup.c 
	$(CC) $(CFLAGS) $^ -o $@

out/stm32_blink.elf	:	out/main.o 	out/stm32f401_startup.o
	$(CC) $(LDFLAGS)  $^ -o out/stm32_blink.elf 	

cake :
	openocd -f C:\msys64\mingw64\share\openocd\scripts\interface\stlink.cfg -f C:\msys64\mingw64\share\openocd\scripts\target\stm32f4x.cfg
clean: 
	cmd rmdir //s out
	