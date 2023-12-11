#include <stdint.h>
#include <stdio.h>
#include "Pressure_Sensor.h"
#include "Main_Algo.h"
#include "Monitor.h"
#include "driver.h"
#include "state.h"

void setup()
{
	PS_init();  //Sensor initialization
	Monitor_Init();  //Monitor initialization
	//set state pointers for each block
	PS_STATE=PS_Reading;
	Algo_STATE=High_Pressure_Detection;
	Monitor_STATE=Alarm_OFF;

}
int main (){
	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		//Implement your Design
		PS_STATE();
		Algo_STATE();
		Monitor_STATE();
	}

}


