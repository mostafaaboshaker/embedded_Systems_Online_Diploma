#@copyrights : Mostafa
CC=arm-none-eabi-
CFLAGS=-g -mcp=arm926ej-s
INCS=-I .
SRC=$(wildcard *.c)
#collect all .c files  
OBJ=$(SRC:.c=.o)
#convert all .c files into .o files
AS=$(wildcard *.s)
#collect all .s files  
ASOBJ=$(AS:.s=.o)
#convert all .s files into .o files
Project_name= learn-in-depth

all:$(Project_name).bin
	@echo "_____ ALL IS DONE______"
app.o:app.c 
	 $(CC)gcc -c $(INCS) $(CFLAGS) $< -o $@
	 
uart.o:uart.c
	 $(CC)gcc -c $(INCS) $(CFLAGS) $< -o $@

startup.o:startup.s
	 $(CC)as -c $(INCS) $(CFLAGS) startup.s -o startup.o    
     
$(Project_name).elf:$(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker.ld $(OBJ) $(ASOBJ) -o $(Project_name).elf

$(Project_name).bin:$(Project_name).elf
	$(CC)objcopy.exe -O binary $(Project_name).elf $(Project_name).bin
clean_all:
	rm *.bin *.o *.elf	  
