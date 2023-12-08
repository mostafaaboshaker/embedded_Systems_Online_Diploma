#include "CA.h"
#include "DC.h"
#include "US.h"
void setup()
{
	US_init();
	DC_init();
	//set state pointers for each block
	CA_state=waiting;
	US_state=US_busy;
	DC_state=DC_idle;

}

int main()
{
    volatile int d;
	setup();

	while(1)
	{
		US_state();
		CA_state();
		DC_state();
		for(d=0;d<=1000;d++);
	}
return 0;

}
