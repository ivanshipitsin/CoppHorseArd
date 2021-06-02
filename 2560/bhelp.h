#ifndef BHELP_H
#define BHELP_H

#include <stdio.h>
#include <string.h>

const char * COMM[] = {"AT\n", "AT+RESET\n", "AT+VERSION?\n", "AT+ORGL\n", "AT+ADDR?\n", "AT+NAME?\n", \
                    "AT+NAME=%s\n", "AT+RNAME? %s\n", "AT+ROLE?\n", "AT+ROLE=%d\n", "AT+CLASS?\n", \
                    "AT+CLASS=%s\n", "AT+IAC?\n", "AT+IAC=%d\n", "AT+INQM?\n", "AT+INQM=%d,%d,%d\n", \
                    "AT+PSWD?\n", "AT+PSWD=%s\n", "AT+UART?\n", "AT+UART=%d,%d,%d\n", "AT+CMODE?\n", \
                    "AT+CMODE=%d\n", "AT+BIND?\n", "AT+BIND=%s\n", "AT+POLAR?\n", "AT+POLAR=%d,%d\n", \
                    "AT+PIO=%d,%d\n", "AT+MPIO?\n", "AT+MPIO=%d\n", "AT+IPSCAN?\n", "AT+IPSCAN=%d,%d,%d,%d\n",\
                    "AT+SNIFF?\n", "AT+SNIFF=%d,%d,%d,%d\n", "AT+ENSNIFF=%s\n", "AT+EXSNIFF=%s\n", "AT+SENM?\n", \
                    "AT+SENM=%d,%d\n", "AT+PMSAD=%s\n", "AT+RMAAD\n", "AT+FSAD=%s\n", "AT+ADCN?\n", "AT+MRAD?\n", \
                    "AT+STATE?\n", "AT+INIT\n", "AT+INQ\n", "AT+INQC\n", "AT+PAIR=%s,%d\n", "AT+LINK=%s\n", \
                    "AT+DISC\n"};
unsigned int ccomm = sizeof(COMM) / sizeof (char *);

#endif