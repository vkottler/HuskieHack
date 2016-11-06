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
int currPos = 0;

int main(void) {
    
    initializers();
    
    while (1) {
        
        if (UARTavailable()) {
            
            getMessage(buffer, BUFFER_SIZE);
            if (strcmp(buffer, "forward") == 0) {
                LEFT_FRONT = ON;
                RIGHT_FRONT = ON;
                LEFT_BACK = OFF;
                RIGHT_BACK = OFF;
            }
            
            else if (strcmp(buffer, "backward") == 0) {
                LEFT_FRONT = OFF;
                RIGHT_FRONT = OFF;
                LEFT_BACK = ON;
                RIGHT_BACK = ON;
            }
            
            else if (strcmp(buffer, "stop") == 0) {
                LEFT_FRONT = OFF;
                RIGHT_FRONT = OFF;
                LEFT_BACK = OFF;
                RIGHT_BACK = OFF;
            }
            
            else if (strcmp(buffer, "left") == 0) 
                if (currPos > -40) currPos -= 5;
            
            else if (strcmp(buffer, "right") == 0) 
                if (currPos < 40) currPos +=5;
            
            else {
                
            }
        }
        
        servoSet(currPos);
        
        //lash();
        //delay(1000, MILLI);
    }
    
    return 0;
}