#include "LIFO.h"

LIFO_STATUS LIFO_INIT(LIFO_BUFFER_t *buffer,unsigned char *buf,int length)
{   //check if LIFO is exist
    if(buf==NULL) return LIFO_NULL;
    buffer->base=buf;
    buffer->head=buf;
    buffer->length=length;
    buffer->count=0;
    return LIFO_NOERROR;
}
LIFO_STATUS LIFO_PUSH(LIFO_BUFFER_t *buffer,unsigned char item)
{
    //check if LIFO is exist
    if(!buffer->base || !buffer->head) return LIFO_NULL;
    //check if LIFO is full
    if((buffer->count)==(buffer->length)) return LIFO_FULL;
    //Pushing data
    *(buffer->head)=item;
    buffer->head++;
    buffer->count++;
    return LIFO_NOERROR;
}
LIFO_STATUS LIFO_POP(LIFO_BUFFER_t *buffer,unsigned char *item)
{   //check if LIFO is exist
    if(!buffer->base || !buffer->head) return LIFO_NULL;
    //check if LIFO is empty
    if(buffer->count==0) return LIFO_EMPTY;
    buffer->head--;
    //Poping data
    *item =*(buffer->head);
    buffer->count--;
    return LIFO_NOERROR;

}
