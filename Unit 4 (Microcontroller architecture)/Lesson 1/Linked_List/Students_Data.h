/*
 * ENG/ MOSTAFA HASSAN ABOSHAKER
 */
#ifndef STUDENTS_DATA_H_INCLUDED
#define STUDENTS_DATA_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"


struct Sdata{
	int ID;
	char name[40];
	float Height;
};

struct Sstudent{
	struct Sdata students;
	struct Sstudent *PNextStudent;
};
struct Sstudent *PFirstStudent=NULL;


void Addstudent();
int Delete_Student();
void View_Students();
void Delete_All();
void Nth_Node(int temp);
int Length_Of_Linked_List_Iterative_Solution();
int Length_Of_Linked_List_Recursive_Solution(struct Sstudent *PcurrentStudent);
void Nth_Node_From_The_End(int n);
void Middle_Of_Linked_List();



#endif // STUDENTS_DATA_H_INCLUDED
