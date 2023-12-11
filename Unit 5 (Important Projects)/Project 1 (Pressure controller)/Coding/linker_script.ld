/*linker script cortexM3
ENG : MOSTAFA */

MEMORY
{
FLASH (rx) : ORIGIN = 0X00000000, LENGTH = 512M
SRAM  (rwx) : ORIGIN = 0X20000000, LENGTH = 512M
}
SECTIONS
{ .text :{
      *(.vectors*)
		  *(.text*)
		  *(.rodata)
      _END_text = . ;
    }>FLASH
	
  .data :{
         _Start_data = . ;
         *(.data)
         . = ALIGN(4);
         _END_data = . ;
		 
  }>SRAM AT> FLASH
  .bss :{
        _Start_bss = . ;
        *(.bss)
        _END_bss = . ;
       
  }>SRAM

}