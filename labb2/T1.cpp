#include "mbed.h"
InterruptIn event(p14); 
DigitalOut flash1 (LED1);
DigitalOut flash2 (LED2);
DigitalOut flash3 (LED3);

void ISR1() //switch state of LED2
{
    flash2=! flash2;   
}

void ISR2() //switch state of LED3
{
    flash3=! flash3;   
}
int main()
{
    event.rise(&ISR1); //at rise,  (ISR1)
    event.fall(&ISR2);//at fall,  (ISR2)
    while(1) 
    {
      flash1=! flash1;  // LED1 blink
      wait(0.25);
      }
}

