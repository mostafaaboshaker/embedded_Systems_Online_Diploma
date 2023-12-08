#include "DC.h"

int DC_speed=0;

void (*DC_state)();


void DC_init()
{
	printf(" \n DC_initialization\n");

}

void DC_motor(int s)
{
	DC_speed=s;
	DC_state=DC_busy;
	printf("\n CA----speed=%d----->DC",DC_speed);
}

void DC_idle()
{   //state name
	DC_STATUS=DCidle;

	//state action
	DC_speed=0;

	printf("\n DC_idle state: speed=%d",DC_speed);

	//event check

}

void DC_busy()
{
	//state name
	DC_STATUS=DCbusy;

	//state action
	DC_speed=30;
	DC_state=DC_idle;
	printf("\n DC_busy state: speed=%d",DC_speed);
}

