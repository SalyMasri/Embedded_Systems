
#include "mbed.h"
#include "C12832.h"
DigitalIn joyup(p15); 
DigitalIn joydwn(p12); 
DigitalIn joylft(p13); 
DigitalIn joyrgt(p16); 
C12832 lcd(p5, p7, p6, p8, p11); 
int x=0,y=0; // initialise x, y variables

void printmap(int x, int y)//create a rectangle with certain x and y variables 
{
    lcd.cls(); //to clear the screen 
    lcd.rect(x, y, x + 4, y + 4, 1); //create the figure
    lcd.copy_to_lcd(); //print it, copy to LCD
}
int main()
{
    while(1)
    { //print figure with the initialized constant x and y 
   printmap( x,  y);

if(joyup && y>0) //if up is pressed and figure's location is within the display area, move the figure 1 unit up
{
       printmap( x,  y--);

}
if(joydwn && y<27)//if down is pressed and figure's location is within the display area, move the figure 1 unit down
{
       printmap( x,  y++);

}
if(joylft && x>0){//if left is pressed and figure's location is within the display area, move the figure 1 unit left
       printmap( x--,  y);
}
if(joyrgt && x<120){ //if right is pressed and figure's location is within the display area, move the figure 1 unit right
      printmap( x++,  y);
} 
}
}
