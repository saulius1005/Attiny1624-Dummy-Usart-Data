/**
 * @file Settings.h
 * @brief Global settings and function declarations for the project.
 * 
 * This file defines global constants, macros, and function prototypes that are 
 * used throughout the project. It includes CPU settings, baud rate calculations, 
 * and function declarations for initializing hardware peripherals and communication.
 * 
 * @author Saulius
 * @date 2024-12-04
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

/**
 * @brief CPU clock frequency in Hz.
 * 
 * This is the operating frequency of the microcontroller's clock, set to 20 MHz.
 * This value is used in various calculations, such as baud rate settings for USART communication.
 */
#define F_CPU 20000000

/**
 * @brief Macro to calculate USART baud rate in synchronous mode as Host SPI.
 * 
 * This macro calculates the baud rate setting for USART0 based on the provided baud rate.
 * It is used for dual speed mode, with the formula adjusted for the baud rate calculation.
 * 
 * @param BAUD_RATE The desired baud rate for USART communication.
 * @return The calculated USART baud rate value.
 */
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (8 * (float)BAUD_RATE)) + 0.5) //dual speed 8, normal 16

#include <avr/io.h>      /**< Include AVR I/O header for hardware access. */
#include <avr/cpufunc.h> /**< Include CPU-specific functions for operations like setting I/O. */
#include <util/delay.h>  /**< Include delay utilities for timing functions. */
#include <stdio.h>       /**< Include standard I/O library for functions like printf. */
#include <string.h>      /**< Include string library for handling string functions like strlen. */

/**
 * @brief Initializes general-purpose input/output (GPIO) settings.
 * 
 * This function configures the required GPIO pins for communication, control, or other I/O tasks.
 */
void GPIO_init();

/**
 * @brief Initializes the internal high-frequency clock.
 * 
 * This function configures and initializes the internal clock generator for the microcontroller.
 */
void CLOCK_INHF_clock_init();

/**
 * @brief Initializes USART0 for SPI communication.
 * 
 * This function sets up USART0 for communication with the specified baud rate, 
 * data format, and enables the transmitter and receiver.
 */
void USART0_init();

/**
 * @brief Sends a character via USART0.
 * 
 * This function transmits a single character via the USART0 interface. It waits for the 
 * USART transmit data register to be empty before sending the character.
 * 
 * @param c The character to be transmitted via USART0.
 */
void USART0_sendChar(char c);

/**
 * @brief Sends a string via USART0.
 * 
 * This function sends a string of characters via USART0. It calls `USART0_sendChar`
 * for each character in the string until the entire string has been transmitted.
 * 
 * @param str The string to be transmitted via USART0.
 */
void USART0_sendString(char *str);

/**
 * @brief Sends a formatted string via USART0.
 * 
 * This function sends a formatted string to USART0, similar to `printf` functionality.
 * It uses a temporary buffer to hold the formatted string and then transmits it.
 * 
 * @param format The format string used for formatting the output.
 */
void USART0_printf(const char *format, ...);

/**
 * @brief Calculates the CRC-8 CDMA2000 checksum.
 * 
 * This function calculates the CRC-8 CDMA2000 checksum for the provided data using 
 * the CDMA2000 polynomial.
 * 
 * @param data The 64-bit data to calculate the CRC checksum for.
 * @return The calculated CRC-8 checksum value.
 */
uint8_t crc8_cdma2000(uint64_t data);

#endif /* SETTINGS_H_ */
