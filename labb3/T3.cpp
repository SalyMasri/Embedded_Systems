

#include "mbed.h"
#include "C12832.h"
#include "LM75B.h"
Serial pc(USBTX, USBRX); //tx, rx
LM75B temp(p28, p27); //sda, sc1

//float read2;
int x=0,y=0;
C12832 lcd(p5, p7, p6, p8, p11); // Init

int main()
{

    while(1)
    {
    if(x>125)
    { lcd.cls();
    x=0;
    }
    else
    {
  //  for(; i<1000; i++)
    

    lcd.line(0,0,100,6000,1); //y axis
    lcd.line(00,30,10000,100,1);   //x axis
     lcd.locate(3,20);
    lcd.printf("10");
    lcd.locate(3,0);
    lcd.printf("30");

    double re= temp.read();
     lcd.pixel(x,45-re,1);
     lcd.copy_to_lcd(); 
        wait(0.5);
    x++;
    }
    //wait(4);
    }
}



