#include "state.h"
#include "Monitor.h"
#include "driver.h"
void (*Monitor_STATE)();
void Monitor_Init()
{
	//printf("High Pressure Detected \n"); //init
}

void Algo_Monitor() //From main algorithm to monitor
{
	Monitor_STATE=Alarm_ON;

}

void Alarm_ON()
{
	Monitor_State_status=Set_Alarm;
	Set_Alarm_actuator(0);  //turning the led on
	Monitor_STATE=Monitor_Waiting;
}

void Alarm_OFF()
{
	Monitor_State_status=Reset_Alarm;
	Set_Alarm_actuator(1); //turning the led off
}

void Monitor_Waiting()
{
	Monitor_State_status=Waiting;
	Delay(60);  //delay of 60 seconds since the the led is turned on
	Monitor_STATE=Alarm_OFF;
}
