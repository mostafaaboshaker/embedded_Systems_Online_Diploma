#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

//FIFO data types
typedef struct {
unsigned int length;
unsigned int count;
unsigned char *base;
unsigned char *head;
unsigned char *tail;

}FIFO_BUFFER_t;

typedef enum{
FIFO_NOERROR,
FIFO_NULL,
FIFO_FULL,
FIFO_EMPTY

}FIFO_STATUS;

//FIFO APIS
FIFO_STATUS FIFO_INIT(FIFO_BUFFER_t *BUFFER,unsigned char *buf,int length);
FIFO_STATUS FIFO_ENQUEUE(FIFO_BUFFER_t *BUFFER,char item);
FIFO_STATUS FIFO_DEQUEUE(FIFO_BUFFER_t *BUFFER,char *item);
void FIFO_PRINT (unsigned char *buf,int length);
#endif // FIFO_H_INCLUDED
