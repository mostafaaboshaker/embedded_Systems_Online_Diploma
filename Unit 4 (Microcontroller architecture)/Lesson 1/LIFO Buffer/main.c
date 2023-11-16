#include <stdio.h>
#include <stdlib.h>
#include "LIFO.c"

int main()
{
unsigned char buf[5];
int temp=0;
LIFO_BUFFER_t BUF;
LIFO_INIT(&BUF,buf,5);
for(int i=0;i<5;i++)
{
    if(LIFO_PUSH(&BUF,i)==LIFO_NOERROR) printf("\nPUSH %d \n",i);
}
printf("\n=====PUSHING IS DONE=====\n");

for(char i=0;i<5;i++)
{
    if(LIFO_POP(&BUF,&temp)==LIFO_NOERROR) printf("\nPOP %d \n",temp);
}
printf("\n=====POPING IS DONE=====\n");
}
