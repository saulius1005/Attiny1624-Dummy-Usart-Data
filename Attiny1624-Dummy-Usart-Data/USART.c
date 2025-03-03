/**
 * @file USART.c
 * @brief USART configuration and communication functions for ATTiny212.
 * 
 * This file contains functions for initializing USART0, sending data (both single characters and strings), 
 * and supporting formatted output via USART0. The baud rate is set to 500,000 bps, and double-speed operation is used.
 * 
 * @author Saulius
 * @date 2025-03-01
 */

#include "Settings.h"

/**
 * @brief Initializes USART0 for communication with a baud rate of 500,000.
 * 
 * Configures USART0 for asynchronous communication with the following settings:
 * - Baud rate of 500,000 bps.
 * - Double-speed operation for higher communication speed.
 * - Transmitter enabled.
 * - No parity, 8 data bits, and 1 stop bit.
 */
void USART0_init() {
    USART0.BAUD = (uint16_t)USART0_BAUD_RATE(500000); ///< Set baud rate to 0.5 Mbps.
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

/**
 * @brief Sends a formatted string via USART0 using `printf`-style formatting.
 * 
 * This function allows for formatted output by using the standard `vsnprintf` function
 * and sending the formatted string via USART0. It is similar to `printf` but sends
 * the result directly to the USART0 output.
 * 
 * @param format The format string, followed by the variable arguments.
 */
void USART0_printf(const char *format, ...) {
    char buffer[38]; ///< Temporary buffer to hold the formatted string.
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args); ///< Format the string into the buffer.
    va_end(args);
    USART0_sendString(buffer); ///< Send the formatted string via USART0.
}
