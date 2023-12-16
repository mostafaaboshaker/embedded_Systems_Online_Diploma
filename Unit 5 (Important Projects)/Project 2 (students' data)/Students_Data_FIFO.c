#include "Students_Data_FIFO.h"

//Include students' data from external file
FILE *Students_Data_File, *database_Students_Data_File;

//Initialization
FIFO_STATUS FIFO_INIT(FIFO_BUFFER_t *BUFFER,Students_BUFFER *buf,int length)
{
    if(buf==NULL)
    	{return FIFO_NULL;
    	printf("**************Students data is not exist*****************\n");
    	printf("**************Initialization failed**********************\n");
    	}
    BUFFER->base=buf;
    BUFFER->head=buf;
    BUFFER->tail=buf;
    BUFFER->count=0;
    BUFFER->length=length;
    return FIFO_NOERROR;
}

Students_BUFFER *Search_Student_by_Roll_Number(FIFO_BUFFER_t *BUFFER, int roll)
{
	Students_BUFFER *Student = BUFFER->tail;
    int i=0;
	for (i = 0; i < BUFFER->count; ++i)
	{
		if (Student->Roll_Number == roll)
		{
			break;
		}

		if((Student + 1) == (BUFFER->base + BUFFER->length))
		{
			Student = BUFFER->base;
		}
		else
		{
			Student++;
		}
	}

	if(i == BUFFER->count)
	{
		Student = NULL;
	}

	return Student;
}


void Add_Student_Manually (FIFO_BUFFER_t *BUFFER)
{
	Students_BUFFER New_Student;
	int i;

		printf("\n=== Enter student data ===\n");
		printf("\tPlease enter roll number: ");
		scanf("%d", &New_Student.Roll_Number);

		// Check if the entered roll number is already exist
		if(Search_Student_by_Roll_Number(BUFFER, New_Student.Roll_Number))
		{
			printf("\n[ERROR] Roll number %d is already taken\n", New_Student.Roll_Number);
			printf("\n[ERROR] Adding student manually failed\n");
			return;
		}

		// If not, Continue reading other data
		printf("\tEnter first name: ");
		scanf("%s", New_Student.First_Name);

		printf("\tEnter second name: ");
		scanf("%s", New_Student.Last_Name);

		printf("\tEnter GPA: ");
		scanf("%f", &New_Student.GPA);

		printf("\tEnter Courses IDs\n");
		for (i = 0; i<5; ++i)
		{
			printf("\t\tEnter Courses no.%d: ",i+1);
			scanf("%d", &New_Student.Course_ID[i]);
		}

		// Add new student
		if(FIFO_ENQUEUE (BUFFER,New_Student) == FIFO_NOERROR)
		{
			printf("\n[INFO] Student details us saved successfully\n");
		}
		else
		{
			printf("\n[ERROR] Adding students manually failed\n");
			return;
		}

}

void Add_Student_From_File(FIFO_BUFFER_t *BUFFER)
{
	Students_BUFFER New_Student;
	int i;

	/* Open a file --> read */
	Students_Data_File = fopen("Students_Data_File.txt", "r");

	/* Check if the file is not empty */
	if(Students_Data_File == NULL)
	{
		printf("\n [ERROR] Students_Data_File.txt file is empty. \n");
		printf("\n [ERROR] Adding students from file >>> failed. \n");
		return;
	}

	/* Reading from file until eof = End Of File */
	while(!feof(Students_Data_File))
	{
		/* Reading roll number */
		fscanf(Students_Data_File, "%d", &New_Student.Roll_Number);

		/* Check if the roll number is exist */
		if(Search_Student_by_Roll_Number(BUFFER, New_Student.Roll_Number) != NULL)
		{
			/* Error ... reapeated Roll Number */
			printf("\n[ERROR] Roll number %d is already taken\n", New_Student.Roll_Number);

			/* Ignore the rest of the line --> because this roll numberis taken */
			fscanf(Students_Data_File, "%*[^\n]");

			continue;
		}

		/* Reading data >>> first name, last name and GPA */
		fscanf(Students_Data_File, "%s", New_Student.First_Name);
		fscanf(Students_Data_File, "%s", New_Student.Last_Name);
		fscanf(Students_Data_File, "%f", &New_Student.GPA);

		/* Reading course IDs */
		for (i = 0; i<5; ++i)
		{
			fscanf(Students_Data_File, "%d", &New_Student.Course_ID[i]);
		}

		/* Enqueue a new student */
		if((FIFO_ENQUEUE(BUFFER, New_Student))== FIFO_NOERROR)
		{
			printf("\n[INFO] Roll number %d is saved successfully\n", New_Student.Roll_Number);
		}
		else
		{
			printf("\n[ERROR] Adding students by file failed\n");
			return;
		}
	}

	printf("\n[INFO] Students details are saved successfully\n");

	/* Close the file */
	fclose(Students_Data_File);
}

void Find_Student_By_Roll_Num  (FIFO_BUFFER_t *BUFFER)
{
	Students_BUFFER *Student;

	FIFO_STATUS queue_status;
	/* Check >>> the queue is empty */
	queue_status = FIFO_is_Empty(BUFFER);
	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Find student by roll number failed\n");
		return;
	}

	int roll_number;
	printf("\nEnter roll number: ");
	scanf("%d", &roll_number);

	/* Scan the queue to find the roll number */
	Student = Search_Student_by_Roll_Number(BUFFER, roll_number);

	/* Check >>> roll number is found */
	if (Student == NULL)
	{
		printf("\n[ERROR] Roll number %d in not found\n", roll_number);
		return;
	}
	else
	{
		/* If we found the roll number >>> print the data */
		Print_Students_Info(Student);
	}
}

void Find_Student_By_FNAME(FIFO_BUFFER_t *BUFFER)
{
	Students_BUFFER *Student = BUFFER->tail;
	char input_name[50];
	int i;

	FIFO_STATUS queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_Empty(BUFFER);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Find student by first name failed\n");
		return;
	}

	printf("\nEnter First Name: ");
	scanf("%s",input_name);

	/* Loop on the queue */
	for (i = 0; i < BUFFER->count; i++)
	{
		/* Compare between each input name and all names in queue */
		if ((strcmp(input_name,Student->First_Name)))
		{
		    if((Student +1) == (BUFFER->base + BUFFER->length))
		{
			/* Set to the start */
			Student = BUFFER->base;
		}
		else
		{
			/* go to the next tail */
			Student++;
		}
		}
		else
		{
			Print_Students_Info(Student);
			return;
		}
	}
	printf("\n[ERROR] %s is not found\n",input_name);

}


void Find_Student_By_Courses(FIFO_BUFFER_t *BUFFER)
{
	Students_BUFFER *Student;
	int input_id, i, j, number_enroled_student = 0;

	FIFO_STATUS queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_Empty(BUFFER);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Find student by course failed\n");
		return;
	}

	/* Get the ID that you want to search about */
	printf("\nEnter Course ID: ");
	scanf("%d", &input_id);

	/* Loop on the queue */
	Student = BUFFER->tail;
	for (i = 0; i < BUFFER->count; ++i)
	{
		/* Scan inside every Node */
		for(j = 0; j<5; ++j)
		{
			/* Search for this ID */
			if(Student->Course_ID[j] == input_id)
			{
				Print_Students_Info(Student);
				number_enroled_student++;
				printf("\n");
				break;
			}
		}

		/* Check if we reach the last Node in the queue */
		if((Student +1) == (BUFFER->base + BUFFER->length))
		{
			/* Set to the start */
			Student = BUFFER->base;
		}
		else
		{
			/* go to the next tail */
			Student++;
		}
	}

	/* Check if it is not found in any student */
	if(number_enroled_student == 0)
	{
		printf("\n[ERROR] Course id %d is not found\n", input_id);
	}
	else
	{
		printf("\n[INFO] Total number of students enrolled: %d\n", number_enroled_student);
	}
}


void Total_Num_Of_Students(FIFO_BUFFER_t *BUFFER)
{
	int counter =  BUFFER->count;
	int capacity = BUFFER->length;

	printf("[INFO] Total number of students is %d\n", counter);
	printf("[INFO] You can add up to %d students\n", capacity);
	printf("[INFO] You can add %d more students\n", capacity - counter);

}


void Delete_Student_By_Roll_Num(FIFO_BUFFER_t *BUFFER)
{
	int roll_number, i, flag = 0;
	Students_BUFFER *Student;

	FIFO_STATUS queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_Empty(BUFFER);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Delete student by roll number failed\n");
		return;
	}

	/* Enter roll number you want to delete */
	printf("\nEnter roll number: ");
	scanf("%d", &roll_number);

	Student = BUFFER->base;
	/* Loop on the queue */
	for (i = 0; i < BUFFER->count; ++i)
	{
		if(Student->Roll_Number == roll_number)
		{
			/* Deleting student */
			*(Student) = *(BUFFER->tail);

			/* Update counter of queue */
			BUFFER->count--;

			/* Check if we reach the last Node in the queue */
			if((BUFFER->tail + 1) == (BUFFER->base + BUFFER->length))
			{
				/* Set to the start */
				BUFFER->tail = BUFFER->base;
			}
			else
			{
				/* go to the next tail */
				BUFFER->tail++;
			}

			flag = 1;
			break;
		}
		else
		{
			flag = 0;
		}
		Student++;
	}

	if(flag == 1)
	{
		printf("\n[INFO] The Roll Number is removed successfully\n");
	}
	else
	{
		printf("\n[ERROR] This Roll Number %d not found\n",roll_number);
	}
}


void Updata_Student_By_Roll_Num(FIFO_BUFFER_t *BUFFER)
{
	Students_BUFFER *Update_Student, *Student;
	int i, input_roll , input_option, input_new_roll, flag = 0;

	FIFO_STATUS queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_Empty(BUFFER);

	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Delete student by roll number failed\n");
		return;
	}

	/* Enter roll number you want to update */
	printf("\nEnter roll number: ");
	scanf("%d", &input_roll);

	/* Search about the input roll to get its whole Node */
	Update_Student = Search_Student_by_Roll_Number(BUFFER, input_roll);

	/* Check if we find roll number in the queue */
	if (Update_Student == NULL)
	{
		printf("\n[ERROR] Roll number %d in not found\n", input_roll);
		return;
	}
	else
	{
		/* If we found the roll number lets print all data */
		printf("\n==== Student data ====\n");
		Print_Students_Info(Update_Student);
	}

	printf("\nWhich date do you want to change ?\n");
	printf("\t 1: The Roll Number\n");
	printf("\t 2: The First Name\n");
	printf("\t 3: The Second Name\n");
	printf("\t 4: The GPA Score\n");
	printf("\t 5: The Courses ID\n");
	printf("Enter your option: ");

	/* Get the option */
	scanf("%d",&input_option);
	switch (input_option)
	{
		case 1:
			printf("Enter the new roll number: ");
			scanf("%d",&input_new_roll);

			Student = BUFFER->tail;
			/* Loop inside the queue */
			for (i = 0; i<BUFFER->count; ++i)
			{
				/* Check if we find the the roll we search about to break */
				if (Student->Roll_Number == input_new_roll)
				{
					/* Get out form for loop */
					printf("\n[ERROR] This Roll Number %d is exist\n",input_new_roll);

					/* If we find a roll number match set flag */
					flag = 1;
					break;
				}

				/* Check if we reach the last Node in the queue */
				if((Student + 1) == (BUFFER->base + BUFFER->length))
				{
					Student = BUFFER->base;
				}
				else
				{
					/* go to the next tail */
					Student++;
				}
			}

			// If the flag doesn't changed this mean that no roll number match
			if(flag == 0)
			{
				Update_Student->Roll_Number = input_new_roll;
				printf("\n[INFO] The Roll Number %d in updated successfully\n", input_new_roll);
			}
			break;

		case 2:
			printf("Enter the new first name: ");
			scanf("%s", Update_Student->First_Name);
			printf("\n[INFO] The First Name %s in updated successfully\n",Update_Student->First_Name);
			break;

		case 3:
			printf("Enter the new last name: ");
			scanf("%s", Update_Student->Last_Name);
			printf("\n[INFO] The Last Name %s in updated successfully\n",Update_Student->Last_Name);
			break;

		case 4:
			printf("Enter the new GPA: ");
			scanf("%f", &Update_Student->GPA);
			printf("\n[INFO] The GPA Score %0.1f in updated successfully\n", Update_Student->GPA);
			break;

		case 5:
			printf("Enter the course number from %d to %d: ", 1, 5);
			scanf("%d", &input_option);
			printf("Enter the new course id: ");
			scanf("%d", &Update_Student->Course_ID[input_option - 1]);
			printf("\n[INFO] The Course ID %d in updated successfully\n", Update_Student->Course_ID[input_option - 1]);
			break;

		default:
			break;
	}
}


void Show_Students_Information(FIFO_BUFFER_t *BUFFER)
{
	Students_BUFFER *Student;
	char i;
	FIFO_STATUS queue_status;

	/* Check >>> the queue is empty */
	queue_status = FIFO_is_Empty(BUFFER);
	if((queue_status == FIFO_EMPTY) || (queue_status == FIFO_NULL))
	{
		printf("\n[ERROR] Show students info failed\n");
		return;
	}

	printf("\nAll Students\n\n");

	Student = BUFFER->tail;
	for (i = 0; i < BUFFER->count; ++i)
	{
		Print_Students_Info(Student);
		printf("\n");

		/* Check if we reach the last Node in the queue */
		if((Student + 1) == (BUFFER->base + BUFFER->length))
		{
			Student = BUFFER->base;
		}
		else
		{
			/* go to the next tail */
			Student++;
		}
	}
}


FIFO_STATUS FIFO_ENQUEUE (FIFO_BUFFER_t *BUFFER, Students_BUFFER Node)
{
	/* Check parameters validity */
	if(!BUFFER || !BUFFER->base || !BUFFER->head || !BUFFER->tail )
	{
		printf("FIFO Enqueue failed: Null is passed\n");

		return FIFO_NULL;
	}

	/* Check if FIFO is Full */
	if((FIFO_is_Full(BUFFER)) == FIFO_FULL)
	{
		printf("FIFO Enqueue failed: FIFO is full\n");

		return FIFO_FULL;
	}

	/* Enqueue new Node */
	*(BUFFER->head) = Node;

	if((BUFFER->head + 1) == (BUFFER->base + BUFFER->length)) // Check if the head in the end of fifo to start over
	{
		BUFFER->head = BUFFER->base;
	}
	else
	{
		BUFFER->head++;
	}

	BUFFER->count++;

	return FIFO_NOERROR;
}


FIFO_STATUS FIFO_is_Full(FIFO_BUFFER_t *BUFFER)
{
	/* validation */
	if(!BUFFER || !BUFFER->base || !BUFFER->head || !BUFFER->tail )
	{
		printf("FIFO is full failed: Null is passed\n");

		return FIFO_NULL;
	}


	if(BUFFER->count == BUFFER->length)
	{
		return FIFO_FULL;
	}

	return FIFO_NOT_FULL;
}


FIFO_STATUS FIFO_is_Empty(FIFO_BUFFER_t *BUFFER)
{
	/* validation */
	if(!BUFFER || !BUFFER->base || !BUFFER->head || !BUFFER->tail )
	{
		printf("FIFO is empty failed: Null is passed\n");

		return FIFO_NULL;
	}

	/* Check if the number of Nodes is zero */
	if(BUFFER->count == 0)
	{
		return FIFO_EMPTY;
	}

	return FIFO_NOT_EMPTY;
}



void Print_Students_Info(Students_BUFFER *Student)
{
	int i;

	printf("The student details are\n");
	printf("\tFirst Name: %s\n", Student->First_Name);
	printf("\tLast Name: %s\n", Student->Last_Name);
	printf("\tRoll Number: %d\n", Student->Roll_Number);
	printf("\tGPA: %0.1f\n", Student->GPA);
	printf("\tCourses IDs are\n");

	for(i = 0; i <5; i++)
	{
		printf("\t\tCourse %d id: %d\n", i + 1, Student->Course_ID[i]);
	}
}
