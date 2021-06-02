#define __AVR_ATmega2560__
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define F_CPU 8000000
#define BAUD_CALC(x) (F_CPU/16/x - 1)


#define BUFSIZERX 128
#define BUFSIZETX 128

#define BUFMASKRX (BUFSIZERX - 1)
#define BUFMASKTX (BUFSIZETX - 1)

unsigned char rxbuff[BUFSIZERX];
unsigned char rxin, rxout;

unsigned char txbuff[BUFSIZETX];
unsigned char txin, txout;


int init();
int loop();


ISR(USART1_RX_vect) {
    rxbuff[rxin] = UDR1;
    rxin++;
    rxin &= BUFMASKRX;
}

static int uart_putchar(char c, FILE *stream){
    txbuff[txin] = c;
    txin++;
    txin&=BUFMASKTX;
    return 0;
}

static int uart_getchar(){
    if (txout != txin) {
        char c = rxbuff[txout];
        txout++;
        txout &= BUFMASKRX;
        return c;
    }else{
        return 0;
    }
}

static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);


/*
int getstr(char * str, int len) {
    for (int i = 0; i < len; i++){
        while(str[i] = uart_getchar());
    }
    return 0;
}*/

int main() {
    init();
    for(;;) {
        loop();
    }
}

void USART1_Init( unsigned int ubrr){
    DDRB = 0b00000110;
/* Set baud rate */
    UBRR1H = (unsigned char)(ubrr>>8);
    UBRR1L = (unsigned char)ubrr;
    /* Enable receiver and transmitter */
    UCSR1B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0);
    /* Set frame format: 8data, 1stop bit */
    UCSR1C = (3<<UCSZ00);
}

int init() {
    //USART0_Init(BAUD_CALC(38400));
    USART1_Init(12);
    sei();

    //stdout = &mystdout;
    //txbuff[0] = 'a';
    //txin+=1;
    
    //printf("C");
    //uart_putchar('c',&mystdout);
    //fprintf(&mystdout,"e");

}

int loop() {
    if(txin != txout && (UCSR1A & (1 << UDRE1))) {
        UDR1 = txbuff[txout];
        txout++;
        txout &= BUFMASKTX;
    }
}