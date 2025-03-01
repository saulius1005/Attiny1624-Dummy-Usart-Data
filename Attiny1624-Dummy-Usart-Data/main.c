/*
 * Attiny1624-Dummy-Usart-Data.c
 *
 * Created: 2025-03-01 22:11:18
 * Author : Saulius
 */ 
#include "Settings.h"

int main(void)
{
    CLOCK_INHF_clock_init(); ///< Initialize system clock
    GPIO_init(); ///< Initialize GPIO pins
    USART0_init(); ///< Initialize USART0 for SPI communication

    while (1) 
    {
		//aaaa- elevacijos kampas, bbbb-azimuto kampas, ccc sp-átampa, dd sp-srovë, 0-y min, 0-y max
        USART0_sendString("<aaaa|bbbb|ccc|dd|0|0>\r\n"); //~25 simboliai
        _delay_ms(100); ///< Wait 100ms before the next read
    }
}

