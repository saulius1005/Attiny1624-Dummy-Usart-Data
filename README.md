## Firmware Description

The purpose of this program is to send test data to the transceiver (Attiny212-USART-Light-Transceiver). The main aspect of this program is that the data format consists of a total of 18 hex characters, where the first 4 are for the elevation angle, the next 4 are for the azimuth angle, the following 3 are for the solar cell voltages, then 2 for the solar cell currents, 1 for the Y end switch status, and the last 2 are for the CRC data representation. In other words, the full data line consists of 16 hex characters or 8 bytes of data, excluding other symbols (< > \r \n).This firmware prototype will later be used for a fiber optic rotary joint and a solar tower controller.

## Wiring diagram

Attiny1624 PB2 (7 pin on SOIC14 package) used as USART TX.
