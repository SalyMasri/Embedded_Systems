
#include <math.h>
#include "mbed.h"
DigitalIn joyctr(p14);
Timeout flipper;
Serial pc(USBTX, USBRX);
void mess()
{
    //srand((unsigned) time (NULL));
    int fl= rand() % 10;
    while (fl<=5)
    {
        fl= rand() % 10;
    }   
    while (fl!=0)
    {
        pc.printf("%d \n", fl);
        fl--;
        wait(1.0);
    }
    if (fl==0)
    {
        std::printf("YES \n");
    }
}
int main()
{
    while(1)
    {
    if (joyctr) //joystick pressed
    {
        flipper.attach(&mess, 2);
    }
    }
}





