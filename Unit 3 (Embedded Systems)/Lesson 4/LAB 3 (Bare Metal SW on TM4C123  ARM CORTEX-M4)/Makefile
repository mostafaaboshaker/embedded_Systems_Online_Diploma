#@copyrights : Mostafa
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
SRC=$(wildcard *.c)

OBJ=$(SRC:.c=.o)
#convert all .c files into .o files
AS=$(wildcard *.s)
#collect all .s files  
ASOBJ=$(AS:.s=.o)
#convert all .s files into .o files
Project_name=learn-in-depth-cortex_m4

all:$(Project_name).bin
	@echo "_____ ALL IS DONE______"
	
%.o: %.c 
	 $(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	    

$(Project_name).elf:$(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld  $(OBJ) $(ASOBJ) -o $(Project_name).elf
	cp $(Project_name).elf  $(Project_name).axf 
	# we made this cp step because the excutable file of cortex-m4 is "axf" not "elf" like cortex-m3
$(Project_name).bin:$(Project_name).elf
	$(CC)objcopy.exe -O binary $(Project_name).elf $(Project_name).bin
clean_all:
	rm *.bin *.o *.elf

	 
	  
	  
