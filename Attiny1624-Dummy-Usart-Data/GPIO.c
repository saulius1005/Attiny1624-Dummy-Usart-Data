/**
 * @file GPIO.c
 * @brief GPIO initialization for ATTiny212.
 * 
 * This file contains the function for initializing the General Purpose Input/Output (GPIO) pins 
 * for USART0 communication on the ATTiny212 microcontroller. The necessary pins are configured 
 * for data transmission.
 * 
 * @author Saulius
 * @date 2025-03-01
 */

#include "Settings.h"

/**
 * @brief Initializes GPIO pins for USART0 communication.
 * 
 * This function configures the necessary GPIO pins for USART0 communication:
 * - Configures the default routing for USART0.
 * - Sets PB2 as the transmission (TX) pin for data sending.
 * - Enables the pull-up resistor on PB2.
 */
void GPIO_init(){
    PORTMUX.USARTROUTEA = PORTMUX_USART0_DEFAULT_gc; ///< Set USART0 to default pins for communication.

    PORTB.DIRSET = PIN2_bm; ///< Set PB2 as TX for data transmission.
    PORTB.PIN2CTRL = PORT_PULLUPEN_bm; ///< Enable pull-up resistor for PB2 (USART0 TX pin).
}
