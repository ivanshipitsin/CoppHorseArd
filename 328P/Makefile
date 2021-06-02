CC=c:/AVRTOOLCHANE/bin/avr-gcc
CFLAGS = -mmcu=atmega328p -Os

OCOPY = c:/AVRTOOLCHANE/bin/avr-objcopy

DUDE = c:/AVRTOOLCHANE/bin/avrdude
all:
	$(CC) $(CFLAGS) main.c -o main.o
	$(OCOPY) -j .text -j .data -O ihex main.o main.hex

load:
	$(DUDE) -c arduino -p m328p -P COM4 -U flash:w:main.hex -b57600 -D