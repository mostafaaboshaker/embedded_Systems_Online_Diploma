#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

enum{
	Sensor_Reading,
	Sensor_Waiting
}Sensor_State_status;
extern void (*PS_STATE)();

void PS_init();
void PS_Reading();  //The sensor is reading pressure values
void PS_Waiting();  //Delay between sensor readings

#endif /* PRESSURE_SENSOR_H_ */
