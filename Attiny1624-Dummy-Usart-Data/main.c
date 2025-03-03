/*
 * @file Attiny1624-Dummy-Usart-Data.c
 * @brief This file contains the main function for the Attiny1624 USART data transmission.
 *        It combines various sensor data into a 64-bit value and sends it over USART0.
 * @author Saulius
 * @date 2025-03-01
 */

#include "Settings.h"

/**
 * @brief Elevation angle (±90 degrees).
 * 
 * This value represents the elevation angle in degrees, with a theoretical range of ±90 degrees.
 */
uint16_t a = 90; ///< Elevation angle (±90 degrees)

/**
 * @brief Azimuth angle (maximum 35999).
 * 
 * This value represents the azimuth angle, with a theoretical maximum of 35999.
 */
uint16_t b = 35999; ///< Azimuth angle (maximum 35999)

/**
 * @brief Voltage (maximum theoretical ±250V).
 * 
 * This value represents the voltage, with a maximum theoretical value of around ±250V.
 */
uint16_t c = 2515; ///< Voltage (maximum theoretical ±250V)

/**
 * @brief Current (maximum 10A).
 * 
 * This value represents the current, with a theoretical maximum of 10A.
 */
uint8_t d = 101; ///< Current (maximum 10A)

/**
 * @brief End switch status.
 * 
 * This value represents the Y-axis end switch, where values can be 0, 1, 2, or 3.
 */
uint8_t e = 1; ///< End switch status (0, 1, 2, 3)

/**
 * @brief Combined 64-bit variable.
 * 
 * This variable combines all of the data (`a`, `b`, `c`, `d`, `e`) into a single 64-bit value for transmission.
 */
uint64_t combined = 0;

/**
 * @brief Main function.
 * 
 * This is the main entry point of the program. It initializes the system clock, GPIO pins, and USART0 for communication.
 * It then combines the sensor data into a 64-bit value and sends it over USART0 in a formatted string.
 * The data is sent at regular intervals with a delay of 100ms between transmissions.
 *
 * @return This function does not return. It runs indefinitely in a while loop.
 */
int main(void)
{
    CLOCK_INHF_clock_init(); ///< Initialize system clock.
    GPIO_init(); ///< Initialize GPIO pins for USART0 communication.
    USART0_init(); ///< Initialize USART0 for SPI communication.

    // Combine all data into a single 64-bit value for transmission
    combined = ((uint64_t)a << 40) | ((uint64_t)b << 24) | ((uint32_t)c << 12) | ((uint16_t)d << 4) | e;

    while (1) 
    {
        // Send the combined data over USART0 in a formatted string
        USART0_printf("<%04x%04x%03x%02x%x%02x>\r\n", 
                        (uint16_t)a,           ///< Elevation angle (4 digits)
                        (uint16_t)b,           ///< Azimuth angle (4 digits)
                        (uint16_t)c,           ///< Voltage (3 digits)
                        (uint8_t)d,            ///< Current (2 digits)
                        (uint8_t)e,            ///< End switch status (1 digit)
                        (uint8_t)crc8_cdma2000(combined)); ///< CRC value (1 byte)

        _delay_ms(100); ///< Wait 100ms before sending the next data packet.
    }
}
