#ifndef _GPIO__H__
#define _GPIO__H__

#include <xc.h>
#include "timer.h"

#define OUTPUT          0
#define INPUT           1

#define BOARD_LED1  LATAbits.LATA3
#define BOARD_LED2  LATCbits.LATC1

void initializeBoardLEDs(void);
void flash(void);

#endif
