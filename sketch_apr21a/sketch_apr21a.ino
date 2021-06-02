#include <Wire.h>

unsigned char mot[3];
void receive();
void requests();
unsigned char error;

void setup() {
    Serial.begin(9600);
    DDRB |= 1<<1;
    DDRB |= 1<<2;
    DDRB |= 1<<3;
    DDRB |= (0) | (0<<4) | (0<<5);
    DDRD = (unsigned char)252;
    
      
    // first 8-bit Timer
    TCCR0A = (1<<COM0A1) | (1<<COM0A0) | (1<<COM0B1) | (1<<COM0B0) | (0b11) ; // Fast PWM in inverse mode
    TCCR0B = 5; //  freqensy div 128
    OCR0A = 0; // run mode
    OCR0B = 255; 
  
    TCCR2A = (1<<COM2A1) | (1<<COM2A0) | (1<<COM2B1) | (1<<COM2B0) | (0b11) ; // Fast PWM in inverse mode
    TCCR2B = 5; // freqensy div 128
    OCR2A = 0; // run mode
    OCR2B = 255; 
  
    TCCR1A = (1<<COM1A1) | (1<<COM1A0) | (1<<COM1B1) | (1<<COM1B0) | 0b01;
    TCCR1B = (1<<WGM12) | 0b101;
  
    OCR1A = 0;
    OCR1B = 255;


    Wire.begin(2);
    Wire.onReceive(receive);
    Wire.onRequest(requests);
}

void loop() {
    unsigned char current = mot[0] & 128;
    PORTD = ~((mot[0]&64) << 2);
    if (current) {
      OCR0A = 0;
      OCR0B = (mot[0] & (63)) << 2;
    }else {
      OCR0B = 0;
      OCR0A = (mot[0] & (63)) << 2;
    }
    error = (PORTB) & 1;
    
    current = mot[1] & 128;
    PORTD = ~((mot[1]&64) << 4);
    if (current) {
      OCR1A = 0;
      OCR1B =  ((mot[1] & (63)) << 2);
    }else {
      OCR1B = 0;
      OCR1A = (mot[1] & (63)) << 2;
    }
    error |= ((PORTB) & 16) << 1;
    
    current = mot[2] & 128;
    PORTD = ~((mot[2]&64) << 7);
    if (current) {
      OCR2A = 0;
      OCR2B = (mot[2] & (63)) << 2;
    }else {
      OCR2B = 0;
      OCR2A = (mot[2] & (63)) << 2;
    }
    error |= ((PORTB) & (32)) << 2;
    Serial.print(mot[0]);
    Serial.print("\n");
}

void receive(int len){
    if(len > 2){
        while(Wire.available() > 2){
          mot[0] = Wire.read();
          mot[1] = Wire.read();
          mot[2] = Wire.read();
        }
    }
}

void requests(){
    Wire.write(error);
}
