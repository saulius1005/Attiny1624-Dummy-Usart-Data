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
		//aaaa- elevacijos kampas, bbbb-azimuto kampas, ccc sp-átampa, dd sp-srovë, e y min + y max (0-neivienas, 1-min arba 2-max)
       // USART0_sendString("<aaaa|bbbb|ccc|dd|e>\r\n"); //~25 simboliai
		USART0_printf("<%04x%04x%03x%02x%x%02x>\r\n",(uint16_t)8999,(uint16_t)35999, (uint16_t)2591, (uint8_t)105, (uint8_t)0, (uint8_t)crc8_cdma2000(0x23278C9FA1F690)); //imituojam 89.99 elevacijos kampa, 359.99 azimuto kampa,spU 259.1V,spI 10.5A
        _delay_ms(100); ///< Wait 100ms before the next read
    }
}

