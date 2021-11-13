#ifndef DMX_CONFIGS_H
#define DMX_CONFIGS_H

#include <avr/io.h>

// Configurations for USART 3
#define DMX_RX_VECT USART3_RX_vect
#define DMX_TX_VECT USART3_TX_vect
#define DMX_UDR UDR3
#define DMX_UBRRH UBRR3H
#define DMX_UBRRL UBRR3L
#define DMX_UCSRA UCSR3A
#define DMX_UCSRB UCSR3B
#define DMX_TXEN TXEN3
#define DMX_TXCIE TXCIE3
#define DMX_RXEN RXEN3
#define DMX_RXCIE RXCIE3
#define DMX_FE FE3
#define DMX_RX_PIN 15
#define DMX_TX_PIN 14
#define DMX_OE_PIN 2

#ifndef F_CPU
#define F_CPU 16000000
#endif
#define DMX_BREAK_BAUD 49950 // For value of 176 uS
#define DMX_BAUD_RATE 250000

#define SET_BAUD(baud) \
do { \
        DMX_UBRRH = (unsigned char)(((F_CPU + baud * 8L) / (baud * 16L) - 1)>>8); \
        DMX_UBRRL = (unsigned char) ((F_CPU + baud * 8L) / (baud * 16L) - 1); \
} while (0);

#endif // DMX_CONFIGS_H
