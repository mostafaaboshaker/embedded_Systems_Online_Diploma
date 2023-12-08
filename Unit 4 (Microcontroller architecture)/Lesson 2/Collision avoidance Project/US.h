
#ifndef US_H_
#define US_H_
#include "state.h"
enum{
	USbusy,

}US_STATUS;

void US_busy();
void US_init();

extern void (*US_state)();

#endif /* CA_H_ */
