#include "Main_Algo.h"
#include "state.h"
int PVal=0;
int Threshold=20;
void (*Algo_STATE)();

void Sensor_Algo(int reading) //From Sensor to main algorithm
{
	PVal=reading;
	Algo_STATE=High_Pressure_Detection;

}

void High_Pressure_Detection()
{
	Algo_State_status=Algorithm_Pressure_Detection;
	if(PVal>Threshold)  Algo_Monitor(); //From main algorithm to monitor
	Algo_STATE=High_Pressure_Detection; //Get another readings
}
