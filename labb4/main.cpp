
#include "mbed.h"
 #include<string> 
 
#include "LM75B.h"
Serial pc(USBTX, USBRX); //tx, rx
LM75B temp(p28, p27); //sda, sc1
LocalFileSystem local("local");

DigitalOut myled1(LED1);

    char write_st[64];
    float wri;
DigitalIn jo(p14); 
int main() {
        while(1)
        if(jo)
        {
        FILE* file=fopen("/local/DATA.TXT", "a"); 
        double tem= temp.read();

         pc.printf("\n\n");
             fprintf(file, "\n");
    for(int i=0; i<5; i++){

         pc.printf("Temp = %.2f degC\n\r", tem);

    fprintf(file, "%.2f", tem);
    fputs(", ",file);
    }
        fclose(file);
    
        FILE* file1=fopen("/local/data.txt", "r");      
        fseek(file1,-37,SEEK_END);   //seek to end
        for(int i=0; i<5; i++){ 
        fgets(write_st, 10, file1);
               pc.printf("%s  ", write_st);
               }
        fclose(file1);
}
}
