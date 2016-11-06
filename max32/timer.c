#include "timer.h"

void initializeTimer(void) {
    T1CON = 0x8000; PR1 = -1; TMR1 = 0;
}

void delay(int length, int interval) {
    int i;
    for (i = 0; i < length; i++) {
        TMR1 = 0;
        while (TMR1 < interval);
    }
}
