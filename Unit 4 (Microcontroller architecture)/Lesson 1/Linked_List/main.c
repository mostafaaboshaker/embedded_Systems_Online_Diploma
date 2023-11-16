/*
 * ENG/ MOSTAFA HASSAN ABOSHAKER
 */

#include "Students_Data.h"
#include "Students_Data.c"

void main()
{
	char temp_text[40];
	int Length =0,x=0,temp=0;
	while(1)
	{

		printf("\n\t Choose one of the following options: \n");
		printf("\n 1:Add student");
		printf("\n 2:Delete student");
		printf("\n 3:view students");
		printf("\n 4:Delete all");
		printf("\n 5:Data of Nth node");
		printf("\n 6:Length of linked list (Iterative_Solution)");
		printf("\n 7:Length of linked list (Recursive_Solution)");
		printf("\n 8:Nth_Node_From_The_End");
		printf("\n 9:Middle_Of_Linked_List\n");
		printf("\n Enter option number : ");

		gets(temp_text);
		printf("\n===================================================");
		switch(atoi(temp_text))
		{
		case 1:
			Addstudent();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			View_Students();
			break;
		case 4:
			Delete_All();
			break;
		case 5:
			printf("\nEnter the desired Node : ");
			gets(temp_text);
			Nth_Node(atoi(temp_text));
			break;
		case 6:
			x=Length_Of_Linked_List_Iterative_Solution();
			printf("\nThe length of linked list is : %d \n",x);
			break;
		case 7:
			Length=Length_Of_Linked_List_Recursive_Solution(&PFirstStudent);
			printf("\nThe length of linked list is : %d",Length);
			break;
		case 8:
			printf("\n Enter the desired node from the end : ");
			gets(temp_text);
			Nth_Node_From_The_End(atoi(temp_text));
			break;
		case 9:
			Middle_Of_Linked_List();
			break;
		default:
			printf("Error choice");
			break;
		}


	}


}
