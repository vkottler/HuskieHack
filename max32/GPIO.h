#ifndef _GPIO__H__
#define _GPIO__H__

#include <xc.h>
#include "timer.h"

#define OUTPUT          0
#define INPUT           1
#define ON              1
#define OFF             0

#define BOARD_LED1      LATAbits.LATA3
#define BOARD_LED2      LATCbits.LATC1

#define LEFT_FRONT      LATCbits.LATC4  // Pin 11
#define LEFT_BACK       LATDbits.LATD4  // Pin 10
#define RIGHT_FRONT     LATDbits.LATD3  // Pin 9
#define RIGHT_BACK      LATDbits.LATD12 // Pin 8

void initializeBoardLEDs(void);
void flash(void);

#endif
