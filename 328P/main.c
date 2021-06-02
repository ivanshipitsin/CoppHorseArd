#define __AVR_ATmega328P__
#include <avr/io.h>
#include <twi.h>
#define INSIZE 128
#define INMASK (INSIZE - 1)
unsigned char inbuffer[INSIZE];
int inbuffin;
int inbuffout;
int read(unsigned char addr);
int init();

int loop();

ISR(TWI_vect) {

}

int main() {
    init();
    
    for(;;) {
        loop();
    }
}

int init() {

    DDRB |= 1<<1;
    DDRB |= 1<<2;
    DDRB |= 1<<3;
    DDRD |= 1<<5;
    DDRD |= 1<<6;
    DDRD |= 1<<3;

    DDRC = 0;
    PORTC |= (1<<4) | (1<<5);
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

    TWAR = 2;
    TWCR = (1<<TWEN)| (1<<TWEA) | (1<<TWINT) | (1<<TWIE);


}

int loop() {
    return 0;
}