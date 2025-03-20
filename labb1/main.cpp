
#include "mbed.h"
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);
DigitalIn joyctr(p14); 
DigitalIn joyup(p15); 
DigitalIn joydwn(p12); 
DigitalIn joylft(p13); 
DigitalIn joyrgt(p16); 
int main() {
while(1) {
if (joyup) {
myled2 = 1;
}
else if (joyrgt) {
myled3 = 1;

}
else if (joydwn) {

myled4 = 1;
}
else if (joylft) {
myled1 = 1;
}
else if (joyctr) {
    myled1 =0;
    myled2 =0;
    myled3 =0;
    myled4 =0;
}

}
}
