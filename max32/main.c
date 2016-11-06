#include "main.h"


void initializers(void) {
    
    DDPCONbits.JTAGEN = 0;
    __builtin_disable_interrupts();
    
    initUART();
    initializeTimer();
    initializeBoardLEDs();
    PWMinit(1, 20);
    
    INTCONbits.MVEC = 1;
    __builtin_enable_interrupts();
}

char buffer[BUFFER_SIZE];
int i;

int main(void) {
    
    initializers();
    
    while (1) {
        
        if (UARTavailable()) {
            getMessage(buffer, BUFFER_SIZE);
            println(buffer);
        }
        
        flash();
        delay(1000, MILLI);
        
        for (i = -40; i <= 40; i++) {
           servoSet(i);
           delay(10, MILLI);
        }
        for (i = 40; i >= -40; i--) {
            servoSet(i);
            delay(10, MILLI);
        }
        
    }
    
    return 0;
}