#include "CA.h"
int CA_speed=0,CA_distance=0,CA_threshold=50;

void (*CA_state)();

void US_set_distance(int d)
{
	CA_distance=d;
	if(CA_distance<=CA_threshold)
		CA_state=waiting;
	else CA_state=driving;
	printf("\n US----distance=%d----->CA",CA_distance);
}

void waiting()
{   //state name
	CA_STATUS=CA_waiting;
	printf("\n CA_waiting state: distance=%d  speed=%d",CA_distance,CA_speed);

	//state action
	CA_speed=0;
	DC_motor(CA_speed);

}

void driving()
{
	//state name
	CA_STATUS=CA_driving;
	printf("\n CA_driving state: distance=%d  speed=%d",CA_distance,CA_speed);

	//state action
	CA_speed=30;
	DC_motor(CA_speed);

}

