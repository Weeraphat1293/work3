#include<SPI.h>
#define S1 10
#define S2 9
#define b1 3 //plus
#define b2 4 //minus
#define reset 5
int num=0;
uint8_t digit[10]={
  0x3F,//0
  0x06,//1
  0x5B,//2
  0x4F,//3
  0x66,//4
  0x6D,//5
  0x7D,//6
  0x07,//7
  0x7F,//8
  0x6F //9
};
void setup() {
  // put your setup code here, to run once:
  SPI.begin();
 SPI.beginTransaction(SPISettings(14000000,MSBFIRST,SPI_MODE0));
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);

  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(reset,INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(b1)==0){
     num=(num+1)%99;
     while(digitalRead(b1)==0){delay(10);}
  }
  if(digitalRead(b2)==0){
     num=(num-1)%99;
     while(digitalRead(b2)==0){delay(10);}
  }
  Serial.print(num);
  Serial.println();
  delay(100);
}
