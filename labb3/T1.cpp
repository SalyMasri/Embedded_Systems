
#include "mbed.h"
#include "C12832.h"
C12832 lcd(p5, p7, p6, p8, p11); // Initialize lcd
AnalogIn Ain(p19);
float percentage;

int x=0;
int main() {
//lcd.printf("    LCD Counter");
//int i;
while (1) {
lcd.locate(25,24);
percentage=Ain*3.3;
lcd.printf("%.2f",percentage);
lcd.printf("%i",x);
wait(1);
x++;

}
}