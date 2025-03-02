/**
 * @file Settings.h
 * @brief Global settings and function declarations for the project.
 * @author Saulius
 * @date 2024-12-04
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

/**
 * @brief CPU clock frequency in Hz.
 */
#define F_CPU 20000000

/**
 * @brief Macro to calculate USART baud rate in synchronous mode as Host SPI.
 * @param BAUD_RATE Desired baud rate.
 */
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (8 * (float)BAUD_RATE)) + 0.5) //dual speed 8, normal 16

#include <avr/io.h>
#include <avr/cpufunc.h>
#include <util/delay.h>
#include <stdio.h>       /**< Include standard I/O library for functions like printf. */
#include <string.h>      /**< Include string library for handling string functions like strlen. */

/**
 * @brief Initializes general-purpose input/output (GPIO) settings.
 */
void GPIO_init();

/**
 * @brief Initializes the internal high-frequency clock.
 */
void CLOCK_INHF_clock_init();


/**
 * @brief Initializes USART0 for SPI communication.
 */
void USART0_init();

/**
 * @brief Sends a character via USART0.
 * @param c Character to be transmitted.
 */
void USART0_sendChar(char c);

void USART0_sendString(char *str);

void USART0_printf(const char *format, ...);

uint8_t crc8_cdma2000(uint64_t data);

#endif /* SETTINGS_H_ */