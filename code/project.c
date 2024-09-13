/*
 * File:   project.c
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41 ?
 */


#include <xc.h>
//#include <builtins.h>
#include "project.h"
#define _XTAL_FREQ 80000000UL

led_t int0_led = { .port_name = GPIO_PORTC, .pin = GPIO_PIN0, .led_status = LED_OFF };
led_t int0_led1 = { .port_name = GPIO_PORTC, .pin = GPIO_PIN1, .led_status = LED_OFF };
led_t int0_led2 = { .port_name = GPIO_PORTC, .pin = GPIO_PIN2, .led_status = LED_OFF };

led_t rb1_led1 = { .port_name = GPIO_PORTC, .pin = GPIO_PIN3, .led_status = LED_OFF };
led_t rb2_led2 = { .port_name = GPIO_PORTC, .pin = GPIO_PIN4, .led_status = LED_OFF };
led_t rb3_led3 = { .port_name = GPIO_PORTC, .pin = GPIO_PIN5, .led_status = LED_OFF };
led_t rb4_led4 = { .port_name = GPIO_PORTC, .pin = GPIO_PIN6, .led_status = LED_OFF };




void int0_app(void){
    // Code INT0
    led_turn_on(&int0_led);
}

void int1_app(void){
    // Code INT1
    led_turn_on(&int0_led1);
}

void int2_app(void){
    // Code INT2
    led_turn_on(&int0_led2);
}

void rb1_app_high(void){
    // Code ON_CHANGE_RB4_HIGH
    led_turn_on(&rb1_led1);
}
void rb1_app_low(void){
    // Code ON_CHANGE_RB4_LOW
    led_turn_off(&rb1_led1);
}

void rb2_app_high(void){
    // Code ON_CHANGE_RB5_HIGH
    led_turn_on(&rb2_led2);
}
void rb2_app_low(void){
    // Code ON_CHANGE_RB5_LOW
    led_turn_off(&rb2_led2);
}

void rb3_app_high(void){
    // Code ON_CHANGE_RB6_HIGH
    led_turn_on(&rb3_led3);
}
void rb3_app_low(void){
    // Code ON_CHANGE_RB6_LOW
    led_turn_off(&rb3_led3);
}

void rb4_app_high(void){
    // Code ON_CHANGE_RB7_HIGH
    led_turn_on(&rb4_led4);
}
void rb4_app_low(void){
    // Code ON_CHANGE_RB7_LOW
    led_turn_off(&rb4_led4);
}

Ext_INTx_t int0= {
    .EXT_InterruptHandler = int0_app,
    .Priority = HIGH_PRIORITY,
    .edge = INTERRUPT_ERISING_EDGE,
    .source = INTERRUPT_EXTERNAL_INT0,
    .mcu_pin.Direction = GPIO_INPUT,
    .mcu_pin.Logic = GPIO_LOW,
    .mcu_pin.Port = GPIO_PORTB,
    .mcu_pin.Pin = GPIO_PIN0
};

Ext_INTx_t int1= {
    .EXT_InterruptHandler = int1_app,
    .Priority = HIGH_PRIORITY,
    .edge = INTERRUPT_ERISING_EDGE,
    .source = INTERRUPT_EXTERNAL_INT1,
    .mcu_pin.Direction = GPIO_INPUT,
    .mcu_pin.Logic = GPIO_LOW,
    .mcu_pin.Port = GPIO_PORTB,
    .mcu_pin.Pin = GPIO_PIN1
};

Ext_INTx_t int2= {
    .EXT_InterruptHandler = int2_app,
    .Priority = HIGH_PRIORITY,
    .edge = INTERRUPT_ERISING_EDGE,
    .source = INTERRUPT_EXTERNAL_INT2,
    .mcu_pin.Direction = GPIO_INPUT,
    .mcu_pin.Logic = GPIO_LOW,
    .mcu_pin.Port = GPIO_PORTB,
    .mcu_pin.Pin = GPIO_PIN2
};

Ext_RBx_t rb1= {
    .EXT_HIGH_interruptHandler = rb1_app_high,
    .EXT_LOW_interruptHandler = rb1_app_low,
    .Priority = HIGH_PRIORITY,
    .mcu_pin.Direction = GPIO_INPUT,
    .mcu_pin.Logic = GPIO_LOW,
    .mcu_pin.Port = GPIO_PORTB,
    .mcu_pin.Pin = GPIO_PIN4
};
Ext_RBx_t rb2= {
    .EXT_HIGH_interruptHandler = rb2_app_high,
    .EXT_LOW_interruptHandler = rb2_app_low,
    .Priority = HIGH_PRIORITY,
    .mcu_pin.Direction = GPIO_INPUT,
    .mcu_pin.Logic = GPIO_LOW,
    .mcu_pin.Port = GPIO_PORTB,
    .mcu_pin.Pin = GPIO_PIN5
};
Ext_RBx_t rb3= {
    .EXT_HIGH_interruptHandler = rb3_app_high,
    .EXT_LOW_interruptHandler = rb3_app_low,
    .Priority = HIGH_PRIORITY,
    .mcu_pin.Direction = GPIO_INPUT,
    .mcu_pin.Logic = GPIO_LOW,
    .mcu_pin.Port = GPIO_PORTB,
    .mcu_pin.Pin = GPIO_PIN6
};
Ext_RBx_t rb4= {
    .EXT_HIGH_interruptHandler = rb4_app_high,
    .EXT_LOW_interruptHandler = rb4_app_low,
    .Priority = HIGH_PRIORITY,
    .mcu_pin.Direction = GPIO_INPUT,
    .mcu_pin.Logic = GPIO_LOW,
    .mcu_pin.Port = GPIO_PORTB,
    .mcu_pin.Pin = GPIO_PIN7
};



void initialization(void);


void main(void) {
    #pragma config PBADEN = OFF 
    initialization();
    while(1){
        
    }
    
    return;
}

void initialization(void){
    led_initialize(&int0_led);
    led_initialize(&int0_led1);
    led_initialize(&int0_led2);
    
    led_initialize(&rb1_led1);
    led_initialize(&rb2_led2);
    led_initialize(&rb3_led3);
    led_initialize(&rb4_led4);

    Ext_INTx_Init(&int0);
    Ext_INTx_Init(&int1);
    Ext_INTx_Init(&int2);

    Ext_RBx_Init(&rb1);
    Ext_RBx_Init(&rb2);
    Ext_RBx_Init(&rb3);
    Ext_RBx_Init(&rb4);

}