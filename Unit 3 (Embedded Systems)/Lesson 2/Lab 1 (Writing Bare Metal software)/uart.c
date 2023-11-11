#include "uart.h"
#define UART *((volatile unsigned int*) ((unsigned int*) 0x101f1000))

void Uart_String( unsigned char *ptr)
{
   while(*ptr != '\0')
   { UART=(unsigned int)*ptr;
   	ptr++;
 
   }

}