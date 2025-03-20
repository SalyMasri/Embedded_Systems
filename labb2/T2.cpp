
#include "mbed.h"

Serial pc(USBTX, USBRX);
Timer t; // define Timer with name “t”

int main() {
    int r;
    float f;
    char sr[100];
    pc.printf("Enter a sentence.\n");
    t.start(); //start the timer
    pc.scanf("%s", sr);
    t.stop(); //stop the timer
    pc.printf("You wrote: '");
    pc.printf("%s",sr);
    r=(unsigned)strlen(sr);
    pc.printf( "'. The sentence entered is %u characters long. ", r);
    pc.printf("The time taken was %f seconds. ", t.read()); //print to pc
    f=  (float)r/t.read();
    //f= t.read()/ (float) r; //Or this formula But I forgot how to do math 
    pc.printf("The average time per character in the string %0.2f\n", f);

}
