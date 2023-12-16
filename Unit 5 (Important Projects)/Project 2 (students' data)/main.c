#include "Students_Data_FIFO.h"

void main()
{
	FIFO_BUFFER_t buffer;
	int Length =0,choise;
	Students_BUFFER buf[50];
	if (FIFO_INIT(&buffer,buf,50)==FIFO_NOERROR)
		{
         printf("\n************* INIT IS DONE ********************************\n"); //Initialization
		 printf("************* Welcome to students Data system *************");
		}

	while(1)
	{

		printf("\n\t Choose one of the following options: \n");
		printf(" 1: Add Student Details Manually\n");
		printf(" 2: Add Student Details From Text File\n");
		printf(" 3: Find Student Details by Roll Number\n");
		printf(" 4: Find Student Details by First Name\n");
		printf(" 5: Find Student Details by Course ID\n");
		printf(" 6: Find The Total Students Number\n");
		printf(" 7: Delete Student Details by Roll Number\n");
		printf(" 8: Update Student Details by Roll Number\n");
		printf(" 9: Show All Information\n");
		printf(" 10:Exit\n");
		printf("\n Enter option number : ");

		scanf("%d",&choise);
		printf("\n===================================================\n");
		switch(choise)
		{
		case 1:
		    Add_Student_Manually (&buffer);
			break;
		case 2:
			Add_Student_From_File (&buffer);
			break;
		case 3:
			Find_Student_By_Roll_Num (&buffer);
			break;
		case 4:
			Find_Student_By_FNAME (&buffer);
			break;
		case 5:
			Find_Student_By_Courses (&buffer);
			break;
		case 6:
			Total_Num_Of_Students (&buffer);
			break;
		case 7:
			Delete_Student_By_Roll_Num (&buffer);
			break;
		case 8:
			Updata_Student_By_Roll_Num (&buffer);
			break;
		case 9:
			Show_Students_Information (&buffer);
			break;
		case 10:
			exit(0);
			break;
		default:
			printf("Wrong choice \n");
			break;
		}

	}

}

