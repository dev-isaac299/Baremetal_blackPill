CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32f401_ls.ld -Wl,-Map=${BUILD_DIR}/stm32_blink.map
BUILD_DIR = Debug


build	:	prereq ${BUILD_DIR}/stm32_blink.elf

prereq	:	
	mkdir ${BUILD_DIR}

${BUILD_DIR}/main.o : src/main.c
	$(CC) $(CFLAGS) $^ -o $@

${BUILD_DIR}/stm32f401_startup.o	:	src/stm32f401_startup.c 
	$(CC) $(CFLAGS) $^ -o $@

${BUILD_DIR}/stm32_blink.elf	:	${BUILD_DIR}/main.o 	${BUILD_DIR}/stm32f401_startup.o
	$(CC) $(LDFLAGS)  $^ -o $@ 	

cake :
	openocd -f C:\msys64\mingw64\share\openocd\scripts\interface\stlink.cfg -f C:\msys64\mingw64\share\openocd\scripts\target\stm32f4x.cfg
clean: 
	cmd //C del -f ${BUILD_DIR}/*.o ${BUILD_DIR}/*.elf ${BUILD_DIR}/*.map
	