/*
 * ENG/ MOSTAFA HASSAN ABOSHAKER
 */

#include "Students_Data.h"
void Addstudent()
{
	struct Sstudent *pnewstudent;
	struct Sstudent *plaststudent;
	char temp_text[40];
	//check list is empty
	if(PFirstStudent==NULL)
	{ //create new record
		pnewstudent=(struct Sstudent*)malloc(sizeof(struct Sstudent));
		//assign it to pfirst
		PFirstStudent=pnewstudent;
	}
	else //list contain record
	{ //navigate until reach to last record
		plaststudent=PFirstStudent;
		while(plaststudent->PNextStudent) plaststudent=plaststudent->PNextStudent;
		//create new record
		pnewstudent=(struct Sstudent*)malloc(sizeof(struct Sstudent));
		plaststudent->PNextStudent=pnewstudent;
	}

	printf("\n Enter student ID: ");
	gets(temp_text);
	pnewstudent->students.ID=atoi(temp_text);

	printf("\n Enter student name: ");
	gets(pnewstudent->students.name);

	printf("\n Enter student Height: ");
	gets(temp_text);
	pnewstudent->students.Height=atof(temp_text);

	pnewstudent->PNextStudent=NULL;
}

int Delete_Student()
{char temp_text[40];
unsigned int selected_ID;
printf("\n Enter student ID: ");
gets(temp_text);
selected_ID=atoi(temp_text);

if(PFirstStudent)
{struct Sstudent *pselectedstudent=PFirstStudent;
struct Sstudent  *ppreviousstudent=NULL;
//loop on all records
while(pselectedstudent)
{
	if(pselectedstudent->students.ID==selected_ID)
	{
		if(ppreviousstudent) //the first student is not the selected student
		{
			ppreviousstudent->PNextStudent = pselectedstudent->PNextStudent;
		}
		else
		{
			PFirstStudent=pselectedstudent->PNextStudent;
		}
		free(pselectedstudent);
		return 1;
	}
	ppreviousstudent=pselectedstudent;
	pselectedstudent=pselectedstudent->PNextStudent;

}

}
printf("\n Can't find this ID ");
return 0;
}


void View_Students()
{
	struct Sstudent *pcurrentstudent=PFirstStudent;
	int count=0;
	if(PFirstStudent==NULL) printf("\n EMPTY LIST");
	else
	{
		while(pcurrentstudent)
		{
			printf("\n record number %d",count+1);
			printf("\n \t ID: %d",pcurrentstudent->students.ID);
			printf("\n \t Name: %s",pcurrentstudent->students.name);
			printf("\n \t Height: %.2f",pcurrentstudent->students.Height);
			pcurrentstudent=pcurrentstudent->PNextStudent;
			count++;
		}

	}

}


void Delete_All()
{
	struct Sstudent *pcurrentstudent=PFirstStudent;
	if(PFirstStudent==NULL) printf("\n EMPTY LIST");
	else
	{
		while(pcurrentstudent)
		{
			struct Sstudent *ptempstudent=pcurrentstudent;
			pcurrentstudent=pcurrentstudent->PNextStudent;
			free(ptempstudent);
		}
		PFirstStudent=NULL;
	}

}
void Nth_Node(int temp)
{
	struct Sstudent *Pdesirednode=PFirstStudent;
	int count=1;
	int selected_node=temp;
    while(Pdesirednode)
    {
    	if(selected_node < 0) printf("\n None valid Node");
    	if(selected_node==count)
    	{
    		printf("\nThe desired node is node number : %d",selected_node);
    		printf("\nThe student name is : %s",Pdesirednode->students.name);
    		printf("\nThe student ID is : %d",Pdesirednode->students.ID);
    		printf("\nThe student Height is : %.2f",Pdesirednode->students.Height);
    	    printf("\n=============================");
    	}
    	else
    	{
    		count++;
    	}
    	Pdesirednode=Pdesirednode->PNextStudent;

    }
}
//Iterative solution
int Length_Of_Linked_List_Iterative_Solution()
{
	struct Sstudent *PcurrentStudent=PFirstStudent;
	int count =0;
	while(PcurrentStudent)
	{
		count++;
		PcurrentStudent=PcurrentStudent->PNextStudent;
	}
	return count;


}
//Recursive solution
int Length_Of_Linked_List_Recursive_Solution(struct Sstudent *PcurrentStudent)
{

	if(PcurrentStudent) return 1+Length_Of_Linked_List_Recursive_Solution(PcurrentStudent->PNextStudent);
	else return 0;
}

void Nth_Node_From_The_End(int n)
{
	struct Sstudent *refStudent=PFirstStudent;
	struct Sstudent *mainStudent=PFirstStudent;
	for(int i=0;i<n;i++) refStudent=refStudent->PNextStudent;
	while(refStudent)
	{
		refStudent=refStudent->PNextStudent;
		mainStudent=mainStudent->PNextStudent;
	}

	printf("\nThe student name is : %s",mainStudent->students.name);
	printf("\nThe student ID is : %d",mainStudent->students.ID);
	printf("\nThe student Height is : %.2f",mainStudent->students.Height);
    printf("\n==========================================================");

}
void Middle_Of_Linked_List()
{
	int l=Length_Of_Linked_List_Iterative_Solution();
	Nth_Node(l/2);

}


