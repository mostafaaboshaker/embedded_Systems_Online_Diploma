#ifndef LIFO_H_INCLUDED
#define LIFO_H_INCLUDED

//LIFO data types
typedef struct {
unsigned int length;
unsigned char *base ;
unsigned char *head;
unsigned int count;
}LIFO_BUFFER_t;

typedef enum {
LIFO_NOERROR,
LIFO_NULL,
LIFO_FULL,
LIFO_EMPTY
}LIFO_STATUS;

//LIFO APIS
LIFO_STATUS LIFO_INIT(LIFO_BUFFER_t *buffer,unsigned char *buf,int length);
LIFO_STATUS LIFO_PUSH(LIFO_BUFFER_t *buffer,unsigned char item);
LIFO_STATUS LIFO_POP(LIFO_BUFFER_t *buffer,unsigned char *item);

#endif // LIFO_H_INCLUDED
