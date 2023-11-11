#include "stdio.h"
#define SYSCTL_RCGC2_R     (*((volatile unsigned long*)(0x400FE108)))
#define GPIO_PORTF_DIR_R   (*((volatile unsigned long*)(0x40025400)))
#define GPIO_PORTF_DEN_R   (*((volatile unsigned long*)(0x4002551C)))
#define GPIO_PORTF_DATA_R  (*((volatile unsigned long*)(0x400253FC)))

int main(void)
{  volatile long delay; //we used volatile as when optimization is open, it will not delete the delay  
   SYSCTL_RCGC2_R=0x20;
   //delay to make sure GPIOF is up and initialized
   for(delay=0;delay<200;delay++);
   GPIO_PORTF_DIR_R |=(1<<3);   
   GPIO_PORTF_DEN_R |=(1<<3);   
   while(1)
   {
	   GPIO_PORTF_DATA_R |=(1<<3);
	   for(delay=0;delay<200;delay++);
	   GPIO_PORTF_DATA_R &= ~(1<<3);
	   for(delay=0;delay<200;delay++);
   }
   return 0;
}
