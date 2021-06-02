#define Left1 7
#define Left2 9
#define Righ1 11
#define Righ2 10



#include <SoftwareSerial.h>

#define RXSIZE 128
#define RXMASK (RXSIZE - 1)

SoftwareSerial mySerial(13,14);//rx tx
unsigned char rxbuff[RXSIZE];
unsigned char rxin = 0;
unsigned char rxout = 0;

void setup() {
  pinMode(Left1, OUTPUT);
  pinMode(Left2, OUTPUT);
  pinMode(Righ1, OUTPUT);
  pinMode(Righ2, OUTPUT);

    pinMode(13,INPUT);
    pinMode(14, OUTPUT);
    mySerial.begin(38400);

    
  /*analogWrite(Left1, 127);
  analogWrite(Left2, 255);
  analogWrite(Righ1, 127);
  analogWrite(Righ2, 255);*/
  Serial.begin(9600);
}

void loop() {
  if(rxin != rxout) {
      unsigned char data = rxbuff[rxout];
      Serial.print(data);
      rxout++;
      rxout&=RXMASK; 
      switch (data) {
        case 'w':
          analogWrite(Left1, 127);
          analogWrite(Left2, 255);
          analogWrite(Righ1, 127);
          analogWrite(Righ2, 255);
          break;
        case 's':
          analogWrite(Left1, 255);
          analogWrite(Left2, 255);
          analogWrite(Righ1, 255);
          analogWrite(Righ2, 255);
          break;
        case 'd':
          analogWrite(Left1, 127);
          analogWrite(Left2, 255);
          analogWrite(Righ1, 255);
          analogWrite(Righ2, 127);
          break;
        case 'a':
         analogWrite(Left1, 255);
         analogWrite(Left2, 127);
         analogWrite(Righ1, 127);
         analogWrite(Righ2, 255);
          break;
        }
   }
  if(mySerial.available()){
    rxbuff[rxin] = (mySerial.read());
    rxin++;
    rxin &= RXMASK;
    }
}
