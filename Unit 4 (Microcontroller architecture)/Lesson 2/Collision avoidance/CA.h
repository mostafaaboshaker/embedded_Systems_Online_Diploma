
#ifndef CA_H_
#define CA_H_
#include "state.h"
enum{
	CA_waiting,
	CA_driving
}CA_STATUS;

void waiting();
void driving();

extern void (*CA_state)();

#endif /* CA_H_ */
