

#include "mbed.h"
#include <math.h>
#include "C12832.h"
#include <time.h>
  #include<string> 
C12832 uLCD(p5, p7, p6, p8, p11);
LocalFileSystem local("local");
int operand1,operand2, op, answer, score;
int ans = 0;
int seconds = 25;
float seed;
Timer t;
Timeout flipper;

DigitalIn ctr(p14);
DigitalIn up(p15); 
DigitalIn dwn(p12); 
DigitalIn lft(p13); 
DigitalIn rgt(p16);

class RGBLed
{
public:
    RGBLed(PinName redpin, PinName greenpin, PinName bluepin);
    void write(float red,float green, float blue);
private:
    PwmOut _redpin;
    PwmOut _greenpin;
    PwmOut _bluepin;
};
 
RGBLed::RGBLed (PinName redpin, PinName greenpin, PinName bluepin)
    : _redpin(redpin), _greenpin(greenpin), _bluepin(bluepin)
{
    //50Hz PWM clock default a bit too low, go to 2000Hz (less flicker)
    _redpin.period(0.0005);
}
 
void RGBLed::write(float red,float green, float blue)
{
    _redpin = red;
    _greenpin = green;
    _bluepin = blue;
}
RGBLed myRGBled(p25,p24,p23); //RGB PWM pins

void ISR3()
{
    for(int x=0; x<2; x++)
    {
        myRGBled.write(0.0,1.0,0.0); //red
        wait(0.5);
        myRGBled.write(0.0,0.0,0.0); //white
        wait(0.5);
    }
   
}


void generateProblem(){
    //generates random numbers between 1 and 40 as operands
    operand1 = rand() % 40 + 1;
    operand2 = rand() % 40 + 1;
    op = rand() % 3;
    
    //genearte random operator and appropriate answer
    if (op == 0){
        uLCD.locate(0,0);
        uLCD.printf("%d + %d\n",operand1, operand2);
        
        answer = operand1 + operand2;
        }
    else if (op == 1){
        uLCD.locate(0,0);
        uLCD.printf("%d - %d\n",operand1, operand2);
        answer = operand1 - operand2;
        }
    else if (op == 2){
        uLCD.locate(0,0);
        uLCD.printf("%d * %d\n",operand1, operand2);
        answer = operand1 * operand2;        
        }
  
    
    }
   
void printloc(int ans)
{
    uLCD.locate(55,20);
        uLCD.printf("Ans: %d",ans);
        wait(0.2);
}

int main()

{   
        myRGBled.write(1.0,1.0,1.0); //green
    bool randomGen = true;
    t.start();
    while(randomGen){ //push centre button to start game
        
        uLCD.locate(4,0);
        uLCD.printf("Push centre button to start the game");
        if(ctr){
            seed = t.read_us(); 
        randomGen= false;
        t.reset();
        uLCD.cls();
        }
           } 
    srand((int)seed);
      FILE* file1=fopen("/local/DATA.TXT", "r");  //get the value and store it as score
      if (file1==NULL) {
        FILE* file2=fopen("/local/DATA.TXT", "w");
          score=0;
        fprintf(file2, "%d", score);
        fclose(file2);
      }    
       score= fgetc( file1);
        fclose(file1);
   
   while(1)
   {
       
  
    generateProblem(); //generate problem
    uLCD.locate(1,20);
   uLCD.printf("Score: %d",score);//display score
    t.start();
    
    while(t.read() <= seconds){//until timer reaches 25 s, time goes down every second
                         uLCD.locate(13,10);
               uLCD.printf("%d",(seconds -(int)t.read()));
        if ((int)t.read()==23) {
        flipper.attach(&ISR3,0.001); //red flash 
        }
                      myRGBled.write(1.0,1.0,1.0); //black
           //move joystick to add up your answer to approach correct answer
       if(dwn)
        {
        ans = ans + 1;
        printloc( ans);
        
        }
        if(rgt)
        {
        ans = ans + 10;
        printloc( ans);
        }
        if(up)
        {
        ans = ans  - 1;
        printloc( ans);
        }
        if(lft) 
        {
        ans = ans - 10;
        printloc( ans);
        }
      }
               FILE* file=fopen("/local/DATA.TXT", "w"); 

      if( ans == answer){//if correct answer then increase score by one and add it to the file
      uLCD.cls();
      score+= 1;
       uLCD.printf("You Win!\n Your score is %d",score);
            wait(1.0);
        fprintf(file, "%d", score);
        uLCD.cls(); 
        }
        if (ans != answer)
        {
           uLCD.cls();
           score -= 1;
        fprintf(file, "%d", score);
        uLCD.printf("You lose!\n Your score is %d",score);
           wait(1.0);
            uLCD.cls();

        }

        t.reset();
            fclose(file);
      ans = 0;
      uLCD.cls(); 
    }
      
               
}