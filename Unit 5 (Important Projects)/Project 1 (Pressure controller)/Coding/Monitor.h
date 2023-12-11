
#ifndef MONITOR_H_
#define MONITOR_H_

enum{
	Set_Alarm,
	Reset_Alarm,
	Waiting
}Monitor_State_status;
extern void (*Monitor_STATE)();

void Monitor_Init();
void Alarm_ON();
void Alarm_OFF();

void Monitor_Waiting(); //Delay of 60 seconds since the led is turned on

#endif /* MONITOR_H_ */
