#include "main.h"


void initializers(void) {
    
    DDPCONbits.JTAGEN = 0;
    __builtin_disable_interrupts();
    
    initUART();
    initializeTimer();
    initializeBoardLEDs();
    
    INTCONbits.MVEC = 1;
    __builtin_enable_interrupts();
}

char buffer[BUFFER_SIZE];

int main(void) {
    
    initializers();
    
    while (1) {
        
        if (UARTavailable()) {
            getMessage(buffer, BUFFER_SIZE);
            println(buffer);
        }
        
        flash();
        delay(1000, MILLI);
        
    }
    
    return 0;
}