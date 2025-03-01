/*
 * GPIO.c
 *
 * Created: 2025-03-01 22:13:44
 *  Author: Saulius
 */ 
 #include "Settings.h"

/**
 * @brief Initializes GPIO pins for USART0 SPI communication with the MT6701 sensor.
 *
 * Configures:
 * - PB1 as XCK (MT6701 CLK) output.
 * - PB2 as TX for dummy data sending with pull-up enabled.
 * - PB3 as RX (MISO, MT6701 DO) with pull-up enabled.
 * - PA7 as SS (MT6701 CSN) output, initially set high.
 */
void GPIO_init(){
    PORTMUX.USARTROUTEA = PORTMUX_USART0_DEFAULT_gc; ///< Set USART0 to default pins

    PORTB.DIRSET = PIN2_bm; ///< Set PB2 as TX for dummy data sending
    PORTB.PIN2CTRL = PORT_PULLUPEN_bm; ///< Enable pull-up for PB2 (USART0 TX)

}
