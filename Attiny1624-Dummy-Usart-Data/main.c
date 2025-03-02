/*
 * Attiny1624-Dummy-Usart-Data.c
 *
 * Created: 2025-03-01 22:11:18
 * Author : Saulius
 */ 
#include "Settings.h"
		uint16_t a = 90, //elevacijos kampas apie 90 laipsniø +-
				 b = 35999, //azimuto kampas max 35999
				 c = 2515; //átampa max teorinë apie 250V +-
		uint8_t  d = 101, //max srove apie 10A +-
				 e = 1; //Y endswitch ámitavimui. 0,1,2,3

		uint64_t combined = 0;

int main(void)
{
    CLOCK_INHF_clock_init(); ///< Initialize system clock
    GPIO_init(); ///< Initialize GPIO pins
    USART0_init(); ///< Initialize USART0 for SPI communication

	combined = ((uint64_t)a << 40) | ((uint64_t)b << 24) | ((uint32_t)c << 12) | ((uint16_t)d << 4) | e;

    while (1) 
    {
		//aaaa- elevacijos kampas, bbbb-azimuto kampas, ccc sp-átampa, dd sp-srovë, e y min + y max (0-neivienas, 1-min arba 2-max)
       // USART0_sendString("<aaaabbbbcccdde>\r\n"); //18 simboliø
		USART0_printf("<%04x%04x%03x%02x%x%02x>\r\n", (uint16_t)a, (uint16_t)b, (uint16_t)c, (uint8_t)d, (uint8_t)e, (uint8_t)crc8_cdma2000(combined)); //imituojam 89.99 elevacijos kampa, 359.99 azimuto kampa,spU 259.1V,spI 10.5A
        _delay_ms(100); ///< Wait 100ms before the next read
    }
}

