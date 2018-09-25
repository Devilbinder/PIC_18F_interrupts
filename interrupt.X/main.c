#include <xc.h>
#include <p18f4520.h>
#include "conbits.h"

void interrupt high_isr(void){
    INTCONbits.GIEH = 0;
    
    if(INTCONbits.INT0IF){
        LATBbits.LB7 = ~LATBbits.LB7;
        INTCONbits.INT0IF = 0;
    }
    
    
    INTCONbits.GIEH = 1;
}

void interrupt low_priority low_isr(void){
    INTCONbits.GIEH = 0;
    
    if(INTCON3bits.INT1IF){
        LATBbits.LB6 = ~LATBbits.LB6;
        INTCON3bits.INT1IF = 0;
    }
    
    INTCONbits.GIEH = 1;
}

void main(void) {
    
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    
    TRISBbits.RB7 = 0;
    TRISBbits.RB6 = 0;
    
    LATBbits.LB7 = 0;
    LATBbits.LB6 = 0;
    
    
    RCONbits.IPEN = 1;
    
    INTCON3bits.INT1E = 1;
    INTCON3bits.INT1P = 0;
    INTCON2bits.INTEDG1 =1;
    
    INTCONbits.INT0IE = 1;
    INTCON2bits.INTEDG0 =1;
    
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
    while(1){
        
    }
    
}
