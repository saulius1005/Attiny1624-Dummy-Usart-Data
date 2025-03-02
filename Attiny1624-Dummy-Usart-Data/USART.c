/*
 * USART.c
 *
 * Created: 2025-03-01 22:15:43
 *  Author: Saulius
 */ 
#include "Settings.h"

void USART0_init() {
    USART0.BAUD = (uint16_t)USART0_BAUD_RATE(500000); ///< Set baud rate to 0.25 Mbps.
    USART0.CTRLB = USART_TXEN_bm | USART_RXMODE_CLK2X_gc; ///< Enable transmitter, double-speed mode.
    USART0.CTRLC = USART_CMODE_ASYNCHRONOUS_gc | ///< Configure for asynchronous mode.
                  USART_CHSIZE_8BIT_gc |      ///< Set data frame to 8 bits.
                  USART_PMODE_DISABLED_gc |  ///< Disable parity.
                  USART_SBMODE_1BIT_gc;      ///< Set 1 stop bit.
}

/**
 * @brief Sends a single character via USART0.
 * 
 * This function waits for the USART0 data register to be empty and then transmits the specified character.
 * 
 * @param c The character to be transmitted.
 */
void USART0_sendChar(char c) {
    while (!(USART0.STATUS & USART_DREIF_bm)); ///< Wait for data register to be empty.
    USART0.TXDATAL = c; ///< Transmit the character.
}

/**
 * @brief Sends a string via USART0.
 * 
 * This function sends a string of characters one by one using the `USART0_sendChar` function.
 * 
 * @param str The string to be transmitted.
 */
void USART0_sendString(char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        USART0_sendChar(str[i]); ///< Send each character of the string.
    }
}

void USART0_printf(const char *format, ...) {
	char buffer[38]; ///< Temporary buffer to hold the formatted string.
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args); ///< Format the string into the buffer.
	va_end(args);
	USART0_sendString(buffer); ///< Send the formatted string via USART0.
}