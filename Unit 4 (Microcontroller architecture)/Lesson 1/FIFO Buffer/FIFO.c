#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>
FIFO_STATUS FIFO_INIT(FIFO_BUFFER_t *BUFFER,unsigned char *buf,int length)
{
    if(buf==NULL) return FIFO_NULL;
    BUFFER->base=buf;
    BUFFER->head=buf;
    BUFFER->tail=buf;
    BUFFER->count=0;
    BUFFER->length=length;
    return FIFO_NOERROR;
}
FIFO_STATUS FIFO_ENQUEUE(FIFO_BUFFER_t *BUFFER,char item)
{   //check if FIFO is exist
    if(!BUFFER->base || !BUFFER->head || !BUFFER->tail) return FIFO_NULL;
    //check if FIFO is full
    if(BUFFER->count==BUFFER->length) return FIFO_FULL;
    BUFFER->count++;
    //ENQUEUING DATA
    *(BUFFER->head)=item;
    //circular FIFO
    if((BUFFER->head)==(BUFFER->base)+(BUFFER->length)*sizeof(char)) BUFFER->head=BUFFER->base;
    else BUFFER->head++;

    return FIFO_NOERROR;

}
FIFO_STATUS FIFO_DEQUEUE(FIFO_BUFFER_t *BUFFER,char *item)
{
    //check if FIFO is exist
    if(!BUFFER->base || !BUFFER->head || !BUFFER->tail) return FIFO_NULL;
    //check if FIFO is empty
    if(BUFFER->count==0) return FIFO_EMPTY;
    BUFFER->count--;
    //DEQUEUING DATA
    *item=*(BUFFER->tail);
    //circular FIFO
    if((BUFFER->tail)==(BUFFER->base)+(BUFFER->length)*sizeof(char)) BUFFER->tail=BUFFER->base;
    else BUFFER->tail++;

    return FIFO_NOERROR;
}
void FIFO_PRINT (unsigned char *buf,int length)
{
    printf("\n=====FIFO_print=====");
    for(int i=0;i<length;i++) printf("\n%d \n",buf[i]);
}
