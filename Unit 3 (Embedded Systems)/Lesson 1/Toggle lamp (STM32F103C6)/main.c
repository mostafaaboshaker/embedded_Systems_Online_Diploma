#include "stdio.h"
#define RCC        *(volatile unsigned long int*)(0x400210000+0X18)
#define GPIOA_CRH  *(volatile unsigned long int*)(0x40010800+0X04)
#define GPIOA_ODR  *(volatile unsigned long int*)(0x40010800+0X0C)

typedef union{
	volatile unsigned int allports;
	struct{
		volatile unsigned int reserved:13;
		volatile unsigned int pin13:1;

	}pin;

}R_ODRt;
volatile R_ODRt* R_ODR=(volatile R_ODRt*) (0x40010800+0X0C) ;
int main(void)
{	    RCC |=1<<2;
		GPIOA_CRH &=0Xff0fffff;
		GPIOA_CRH |=0X00200000;
		while(1)
		   {R_ODR->pin.pin13=1;
		    for(int i=0;i<5;i++);
		    R_ODR->pin.pin13=0;
		    for(int i=0;i<5;i++);

		   }
}
