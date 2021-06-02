/*#include <SoftwareSerial.h>
#include <Wire.h>

#define RXSIZE 128
#define RXMASK (RXSIZE - 1)

SoftwareSerial mySerial(13,14);
unsigned char rxbuff[RXSIZE];
unsigned char rxin = 0;
unsigned char rxout = 0;
unsigned mot[6];


void setup(){
  Wire.begin();
  
  pinMode(13,INPUT);
  pinMode(14, OUTPUT);
  mySerial.begin(38400);
  Serial.begin(9600);
}

void loop(){
  Serial.print(mot[0]);
  Serial.print("\n");
  if(rxin != rxout) {
      unsigned char data = rxbuff[rxout];
      rxout++;
      rxout&=RXMASK; 
      switch (data) {
        case 'F':
          mot[0]=mot[1]=mot[2]=mot[3]=mot[4]=mot[5] = 0b10111111;
          break;
        case 'B':
          mot[0]=mot[1]=mot[2]=mot[3]=mot[4]=mot[5] = 0b00111111;
          break;
        case 'S':
          mot[0]=mot[1]=mot[2]=mot[3]=mot[4]=mot[5] = 0b00000000;
          break;
        case 'L':
          mot[0]=mot[1]=mot[2]= 0b00111111;
          mot[3]=mot[4]=mot[5] = 0b10111111;
          break;
        case 'R':
          mot[0]=mot[1]=mot[2]= 0b10111111;
          mot[3]=mot[4]=mot[5] = 0b00111111;
          break;
        }
   }
    Wire.beginTransmission(1);
    Wire.write(mot[0]);
    Wire.write(mot[1]);
    Wire.write(mot[2]);
    Wire.endTransmission();

    Wire.beginTransmission(2);
    Wire.write(mot[3]);
    Wire.write(mot[4]);
    Wire.write(mot[5]);
    Wire.endTransmission();
   
  if(mySerial.available()){
    rxbuff[rxin] = (mySerial.read());
    rxin++;
    rxin &= RXMASK;
    }
  }
  */
#include <SoftwareSerial.h>

#define RXSIZE 128
#define RXMASK (RXSIZE - 1)

SoftwareSerial mySerial(13,14);
unsigned char rxbuff[RXSIZE];
unsigned char rxin = 0;
unsigned char rxout = 0;

void setup() {
     pinMode(13,INPUT);
    pinMode(14, OUTPUT);
    mySerial.begin(38400);
    pinMode(3,OUTPUT);
    pinMode(5,OUTPUT);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
 }

 void loop() {
  if(rxin != rxout) {
      unsigned char data = rxbuff[rxout];
      rxout++;
      rxout&=RXMASK; 
      switch (data) {
        case 'w':
          digitalWrite(3,HIGH);
          digitalWrite(5,HIGH);
          break;
        case 's':
          digitalWrite(3,LOW);
          digitalWrite(5,LOW);
          break;
        case 'd':
          digitalWrite(3,HIGH);
          digitalWrite(5,LOW);
          break;
        case 'r':
         digitalWrite(3,LOW);
          digitalWrite(5,HIGH);
          break;
        }
   }
  if(mySerial.available()){
    rxbuff[rxin] = (mySerial.read());
    rxin++;
    rxin &= RXMASK;
    }
 }
