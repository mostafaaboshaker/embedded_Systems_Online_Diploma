#include "stdio.h"
#define RCC        *(volatile unsigned int*)(0x40021000 + 0x18)
#define GPIOA_CRH  *(volatile unsigned int*)(0x40010800+ 0x04)
#define GPIOA_ODR  *(volatile unsigned int*)(0x40010800+ 0x0C)

typedef union {
	volatile unsigned int allports;
	struct{
		volatile unsigned int reserved:13;
		volatile unsigned int pin_13:1;

	}PIN;

}R_ODRt;
volatile R_ODRt* R_ODR=(volatile R_ODRt*) (0x40010800+0X0C) ;
int main(void)
{	    RCC |=(1<<2);
		GPIOA_CRH &=0xff0fffff;
		GPIOA_CRH |=0x00200000;
		while(1)
		   {R_ODR->PIN.pin_13=1;
		    for(int i=0;i<5000;i++);
		    R_ODR->PIN.pin_13=0;
		    for(int j=0;j<5000;j++);
		   }

}
