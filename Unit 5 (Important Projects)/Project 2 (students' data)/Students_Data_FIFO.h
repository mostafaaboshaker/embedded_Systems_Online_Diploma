#ifndef STUDENTS_DATA_FIFO_H_
#define STUDENTS_DATA_FIFO_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"


//Students_Data
typedef struct {
	char First_Name[50];
	char Last_Name[50];
	int Roll_Number;
	float GPA;
	int Course_ID[5];
}Students_BUFFER;


//FIFO data types
typedef struct {
unsigned int length;
unsigned int count;
Students_BUFFER *base;
Students_BUFFER *head;
Students_BUFFER *tail;
}FIFO_BUFFER_t;

typedef enum{
FIFO_NOERROR,
FIFO_NULL,
FIFO_FULL,
FIFO_NOT_FULL,
FIFO_EMPTY,
FIFO_NOT_EMPTY
}FIFO_STATUS;

//FIFO APIS
FIFO_STATUS FIFO_INIT             (FIFO_BUFFER_t *BUFFER,Students_BUFFER *buf,int length);
FIFO_STATUS FIFO_ENQUEUE          (FIFO_BUFFER_t *BUFFER,Students_BUFFER Node);
FIFO_STATUS FIFO_is_Empty         (FIFO_BUFFER_t *BUFFER);
FIFO_STATUS FIFO_is_Full          (FIFO_BUFFER_t *BUFFER);

void Add_Student_Manually         (FIFO_BUFFER_t *BUFFER);
void Add_Student_From_File        (FIFO_BUFFER_t *BUFFER);
void Find_Student_By_Roll_Num     (FIFO_BUFFER_t *BUFFER);
void Find_Student_By_FNAME        (FIFO_BUFFER_t *BUFFER);
void Find_Student_By_Courses      (FIFO_BUFFER_t *BUFFER);
void Total_Num_Of_Students        (FIFO_BUFFER_t *BUFFER);
void Delete_Student_By_Roll_Num   (FIFO_BUFFER_t *BUFFER);
void Updata_Student_By_Roll_Num   (FIFO_BUFFER_t *BUFFER);
void Show_Students_Information    (FIFO_BUFFER_t *BUFFER);
void Print_Students_Info          (Students_BUFFER *Student);
Students_BUFFER * Search_Student_by_Roll_Number(FIFO_BUFFER_t *BUFFER, int roll);

#endif /* STUDENTS_DATA_FIFO_H_ */
