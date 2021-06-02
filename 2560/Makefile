CC=c:/AVRTOOLCHANE/bin/avr-gcc
CFLAGS = -mmcu=atmega328p -Os -Wl,-u,vfprintf -lprintf_min

OCOPY = c:/AVRTOOLCHANE/bin/avr-objcopy

DUDE = c:/AVRTOOLCHANE/bin/avrdude
all:
	$(CC) $(CFLAGS) main.c -o main.o
	$(OCOPY) -j .text -j .data -O ihex main.o main.hex

load:
	$(DUDE) -c wiring -p atmega2560 -P COM3 -U flash:w:main.hex -b115200 -D