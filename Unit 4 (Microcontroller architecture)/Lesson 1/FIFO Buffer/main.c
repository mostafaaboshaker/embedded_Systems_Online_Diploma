#include "FIFO.c"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char temp=0;
	unsigned char buf[5];
	FIFO_BUFFER_t buffer;

	if (FIFO_INIT(&buffer,buf,5)==FIFO_NOERROR) printf("INIT IS DONE\n");
    //Start ENQUEUE
	for(int i=0;i<5;i++)
	{   printf("FIFO ENQUEUE: %d \n",i);
	if (FIFO_ENQUEUE(&buffer,i)==FIFO_NOERROR) printf("ENQUEUE IS DONE\n");
	else printf("ENQUEUE IS FAILED\n");
	}

	FIFO_PRINT(&buf,5);
    //START DEQUEUE
	if (FIFO_DEQUEUE(&buffer,&temp)==FIFO_NOERROR)
	{
	    printf("=====DEQUEUE IS STARTING===== \n");
	    FIFO_PRINT(&buf,5);
	}

	printf("DEQUEUE IS DONE\n");

}
