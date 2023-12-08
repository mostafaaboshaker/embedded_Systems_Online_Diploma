
#ifndef DC_H_
#define DC_H_
#include "state.h"
enum{
	DCidle,
	DCbusy
}DC_STATUS;

void DC_idle();
void DC_busy();
void DC_init();

extern void (*DC_state)();

#endif /* CA_H_ */
