#ifndef _TIMER__H_
#define _TIMER__H_

#include <xc.h>

#define MILLI   64000
#define MICRO   64

void initializeTimer1(void);
void delay(int length, int interval);

#endif