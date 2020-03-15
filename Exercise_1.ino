#include<SPI.h>
#define S1 10
#define S2 9
uint8_t counter=1;
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
}

void loop() {
  SPI.transfer(0x7F);
  digitalWrite(S1,HIGH);
  digitalWrite(S1,LOW);
  SPI.transfer(0x3F);
  digitalWrite(S1,HIGH);
  digitalWrite(S1,LOW);
  delay(1000);
  for(int m=0;m<10;m++){
    for(int n=0;n<10;n++){
      SPI.transfer(digit[n]);
      digitalWrite(S2,HIGH);
      digitalWrite(S2,LOW);
      delay(200);
    }
    SPI.transfer(digit[m]);
    digitalWrite(S1,HIGH);
    digitalWrite(S1,LOW);
    SPI.transfer(0x3F);
    digitalWrite(S2,HIGH);
    digitalWrite(S2,LOW);
    delay(200);
  }
}
