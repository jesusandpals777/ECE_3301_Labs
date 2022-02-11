#include <p18f4620.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <math.h>

#pragma config OSC = INTIO67
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config BOREN = OFF
#define delay 5

void main(){
    char in;                    // Use variable 'in' as in char
    TRISA = 0xff;               // Digital input pin
    TRISB = 0x00;               // Digital output pin
    TRISC =0;
    TRISD = 0;
    PORTC = 0;
    PORTD = 0;
    ADCON1 = 0x0f;              // Analog to Digital converter          
    
    while(1){                   
        in = PORTA;             // Read data from PORTA and save it into 'in'
        in = in & 0x0F;         // Mask out the uused upper four bits
        PORTB = in;             // Output the data to PORT
    }
}