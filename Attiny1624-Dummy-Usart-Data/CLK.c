/**
 * @file CLK.c
 * @brief Clock initialization functions for the ATTiny1614 microcontroller.
 * 
 * This file contains functions for configuring the clock sources of the ATTiny1614. 
 * Specifically, it includes the initialization of the internal high-frequency oscillator 
 * (OSC20M) to run at 20 MHz, and ensures proper setup for full-speed operation.
 * 
 * @author Saulius
 * @date 2025-02-27
 */

#include "Settings.h"

/**
 * @brief Initializes the internal high-frequency oscillator (OSCHF) to 20 MHz.
 * 
 * This function configures the ATTiny1614's internal oscillator to operate at 20 MHz. 
 * The configuration ensures that the clock source is set correctly, the prescaler is 
 * disabled for full-speed operation, and the system waits for the oscillator to stabilize.
 * 
 * @details
 * - Configures the clock source to use the 20 MHz internal oscillator (OSC20M).
 * - Disables the clock prescaler to achieve full-speed operation.
 * - Waits for the oscillator configuration to complete and stabilize.
 * 
 * @note For the SO14 package, enabling the clock output (CLKOUT) is not possible due to the 
 *       lack of a dedicated pin for this function.
 */
void CLOCK_INHF_clock_init() {
    /* Enable the internal oscillator with a frequency of 20 MHz. */
    ccp_write_io((uint8_t *) &CLKCTRL.MCLKCTRLA, CLKCTRL_CLKSEL_OSC20M_gc /*| CLKCTRL_CLKOUT_bm*/); 
    // For SO14, it is impossible to enable CLKOUT due to the lack of a dedicated pin.

    /* Disable the main clock prescaler for full-speed operation. */
    ccp_write_io((uint8_t *) &CLKCTRL.MCLKCTRLB, CLKCTRL_PDIV_2X_gc & ~CLKCTRL_PEN_bm);

    /* Wait for the oscillator change to complete. */
    while (CLKCTRL.MCLKSTATUS & CLKCTRL_SOSC_bm) {};
}
