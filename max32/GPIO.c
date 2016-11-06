#include "GPIO.h"

void initializeBoardLEDs(void) {
    TRISAbits.TRISA3 = OUTPUT;      // Also Board LED1
    TRISCbits.TRISC1 = OUTPUT;      // Board LED2  
    TRISCbits.TRISC4 = OUTPUT;
    TRISDbits.TRISD4 = OUTPUT;
    TRISDbits.TRISD3 = OUTPUT;
    TRISDbits.TRISD12 = OUTPUT;
    
    BOARD_LED1 = 0, BOARD_LED2 = 0;
}

void flash(void) {
    BOARD_LED1 = 1; BOARD_LED2 = 0;
    delay(100, MILLI);
    BOARD_LED1 = 0; BOARD_LED2 = 1;
    delay(100, MILLI);
    BOARD_LED1 = 1; BOARD_LED2 = 0;
    delay(100, MILLI);
    BOARD_LED1 = 0; BOARD_LED2 = 1;
    delay(100, MILLI);
    BOARD_LED1 = 1; BOARD_LED2 = 0;
    delay(100, MILLI);
    BOARD_LED1 = 0; BOARD_LED2 = 1;
    delay(100, MILLI);
    BOARD_LED1 = 1; BOARD_LED2 = 0;
    delay(100, MILLI);
    BOARD_LED1 = 0; BOARD_LED2 = 1;
    delay(100, MILLI);
    BOARD_LED1 = 1; BOARD_LED2 = 0;
    delay(100, MILLI);
    BOARD_LED1 = 0; BOARD_LED2 = 1;
    delay(100, MILLI);
    BOARD_LED1 = 0; BOARD_LED2 = 0;
}
