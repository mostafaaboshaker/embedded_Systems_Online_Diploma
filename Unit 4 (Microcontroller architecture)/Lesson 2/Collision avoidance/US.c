#include "US.h"

int US_distance=0;

void (*US_state)();
int US_GET_DISTANCE_RANDOM (int l,int r,int count);

void US_init()
{
//init US driver
printf("\n US_init");
}

void US_busy()
{   //state name
	US_STATUS=USbusy;

	//state action
	US_distance=US_GET_DISTANCE_RANDOM(45, 55,1);

	printf("\n US_waiting state: distance=%d  ",US_distance);
    US_set_distance(US_distance);
	US_state=US_busy;

}



int US_GET_DISTANCE_RANDOM (int l,int r,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		int rand_num=(rand() % (r-l+1))+l;
		return rand_num;
	}

}
