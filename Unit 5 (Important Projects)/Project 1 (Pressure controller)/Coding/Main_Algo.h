#ifndef MAIN_ALGO_H_
#define MAIN_ALGO_H_

extern void (*Algo_STATE)();
void High_Pressure_Detection(); //detection if pressure>20bar

enum{
	Algorithm_Pressure_Detection
}Algo_State_status ;


#endif /* MAIN_ALGO_H_ */
