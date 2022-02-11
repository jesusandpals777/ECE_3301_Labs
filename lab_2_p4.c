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

void Delay_One_Sec(){
    for (int I = 0; I < 17000; I++);
}

void main(){
    char in;                    // Use variable 'in' as in char
    TRISA = 0xff;               // Digital input pin
    TRISB = 0x00;               // Digital output pin
    TRISC =0x00;
    TRISD = 0x00;
    PORTB = 0x00;
    ADCON1 = 0x0f;              // Analog to Digital converter          
    while(1){                   
        for (char i = 0; i < 8; i++){
            PORTC = in;
            Delay_One_Sec();
            PORTD = (7-i);
        }
    }
}
