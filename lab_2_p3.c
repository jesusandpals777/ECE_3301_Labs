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
    TRISD = 0;
    PORTB = 0x00;
    ADCON1 = 0x0f;              // Analog to Digital converter          
    
    char array[8] = {0x81, 0xC7, 0x43, 0x24, 0x02, 0x6C, 0xA5, 0x20}; 
    while(1){                   
        in = PORTC;             // Read data from PORTA and save it into 'in'
        for (char i = 0; i < 8; i++){
            PORTC = i;
            Delay_One_Sec();
        }
    }
}
