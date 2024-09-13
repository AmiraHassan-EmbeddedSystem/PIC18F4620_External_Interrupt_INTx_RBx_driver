#include "manage_interrupt.h"

volatile uint8 RB4_Flag = 1, RB5_Flag = 1, RB6_Flag = 1, RB7_Flag = 1;

#ifdef INTERRUPT_PRIORITY_LEVELS
void __interrupt() InterruptManagerHigh(void)
{
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF)){
        ISR_INT0();
    }
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF)){
        ISR_INT1();
    }
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        ISR_INT2();
    }
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB4 == GPIO_HIGH) && (RB4_Flag == 0)){
        RB4_Flag = 1;
        ISR_RB4(1);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB4 == GPIO_LOW) && (RB4_Flag == 1)){
        RB4_Flag = 0;
        ISR_RB4(0);
    }   
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB5 == GPIO_HIGH) && (RB5_Flag == 0)){
        RB5_Flag = 1;
        ISR_RB5(1);
    } 
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB5 == GPIO_LOW) && (RB5_Flag == 1)){
        RB5_Flag = 0;
        ISR_RB5(0);
    } 
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB6 == GPIO_HIGH) && (RB6_Flag == 0)){
        RB6_Flag = 1;
        ISR_RB6(1);
    } 
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB6 == GPIO_LOW) && (RB6_Flag == 1)){
        RB6_Flag = 0;
        ISR_RB6(0);
    } 
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB7 == GPIO_HIGH) && (RB6_Flag == 0)){
        RB7_Flag = 1;
        ISR_RB7(1);
    } 
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB7 == GPIO_LOW) && (RB7_Flag == 1)){
        RB7_Flag = 0;
        ISR_RB7(0);
    } 
}

void __interrupt(low_priority) InterruptManagerLow(void)
{
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF)){
        ISR_INT1();
    }
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        ISR_INT2();
    }
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB4 == GPIO_HIGH) && (RB4_Flag == 0)){
        RB4_Flag = 1;
        ISR_RB4(1);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB4 == GPIO_LOW) && (RB4_Flag == 1)){
        RB4_Flag = 0;
        ISR_RB4(0);
    }   
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB5 == GPIO_HIGH) && (RB5_Flag == 0)){
        RB5_Flag = 1;
        ISR_RB5(1);
    } 
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB5 == GPIO_LOW) && (RB5_Flag == 1)){
        RB5_Flag = 0;
        ISR_RB5(0);
    } 
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB6 == GPIO_HIGH) && (RB6_Flag == 0)){
        RB6_Flag = 1;
        ISR_RB6(1);
    } 
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB6 == GPIO_LOW) && (RB6_Flag == 1)){
        RB6_Flag = 0;
        ISR_RB6(0);
    } 
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB7 == GPIO_HIGH) && (RB6_Flag == 0)){
        RB7_Flag = 1;
        ISR_RB7(1);
    } 
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB7 == GPIO_LOW) && (RB7_Flag == 1)){
        RB7_Flag = 0;
        ISR_RB7(0);
    } 
}
#else

void  __interrupt() InterruptManagerHigh(void)
{
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF)){
        ISR_INT0();
    }
     if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF)){
        ISR_INT1();
    }
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        ISR_INT2();
    }
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB4 == GPIO_HIGH) && (RB4_Flag == 0)){
        RB4_Flag = 1;
        ISR_RB4(1);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB4 == GPIO_LOW) && (RB4_Flag == 1)){
        RB4_Flag = 0;
        ISR_RB4(0);
    }   
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB5 == GPIO_HIGH) && (RB5_Flag == 0)){
        RB5_Flag = 1;
        ISR_RB5(1);
    } 
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB5 == GPIO_LOW) && (RB5_Flag == 1)){
        RB5_Flag = 0;
        ISR_RB5(0);
    } 
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB6 == GPIO_HIGH) && (RB6_Flag == 0)){
        RB6_Flag = 1;
        ISR_RB6(1);
    } 
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB6 == GPIO_LOW) && (RB6_Flag == 1)){
        RB6_Flag = 0;
        ISR_RB6(0);
    } 
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB7 == GPIO_HIGH) && (RB6_Flag == 0)){
        RB7_Flag = 1;
        ISR_RB7(1);
    } 
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (PORTBbits.RB7 == GPIO_LOW) && (RB7_Flag == 1)){
        RB7_Flag = 0;
        ISR_RB7(0);
    } 
}
#endif
