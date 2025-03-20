#include "mbed.h"
Ticker flipper;
Ticker flipper2;
Ticker flipper3;
Ticker flipper4;
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
//flip functions switch state of LED1,2,3,4 
void flip1() {
    led1 = !led1;
}
 
 
void flip2() {
    led2 = !led2;
}
void flip3() {
    led3= !led3;
}
 
 
void flip4() {
    led4 = !led4;
} 
int main() {
    flipper.attach(&flip1, 0.7); // the address of the function to be attached (flip1) and the interval (0.7 seconds)
    flipper2.attach(&flip2, 1.2);
    flipper3.attach(&flip3, 2.3);
    flipper4.attach(&flip4, 3.9);
 
   
    while(1) {
        
    }
}