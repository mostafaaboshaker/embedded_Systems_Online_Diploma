#include "state.h"
#include "Pressure_Sensor.h"
#include "driver.h"
void (*PS_STATE)();
int Sensor_reading=0;

void PS_init()
{
	//printf("Pressure Sensor Initialization \n"); //initialization
}

void PS_Reading()
{
	Sensor_State_status=Sensor_Reading;
	Sensor_reading=getPressureVal(); //Geting sensor reading value
	Sensor_Algo(Sensor_reading);     //Sending the reading to main algorithm
	//printf("PS busy state:Sensor_reading= %d",Sensor_reading);
	PS_STATE=PS_Waiting;

}

void PS_Waiting()
{
	Sensor_State_status=Sensor_Waiting;
	Delay(100);  //Delay between sensor readings
	PS_STATE=PS_Reading;
}
