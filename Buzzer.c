#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
int main(void)
{
 SYS_Init();
// PORTC
 PC -> PMD &=~(0xFF) <<24;
 PC -> PMD |= (0x01) << 24;
 PC -> PMD |= (0x01) << 26;
 PC -> PMD |= (0x01) << 28;
 PC -> PMD |= (0x01) << 30;


// PORTB
 PB-> PMD &= ~(0x03) << 22;
 PB-> PMD |= (0x01) << 22;

//PORTA
 PA -> PMD &= ~(0x7F) << 24;
 PA -> PMD |= (0x15) << 24;

	while (1) {

		if (!(PB15)) {
			PC -> DOUT &=~(0xF) << 12;
			PA -> DOUT &=~ (0x7) << 12;
			PB-> DOUT &=~ (0x1) << 11;
			PC -> DOUT &=~ (0x8) << 4;
		}
		else {
			PC -> DOUT |= (0xF) << 12;
			PA -> DOUT |= (0x7) << 12;
			PB -> DOUT |= (0x1) << 11;
			}

		}
}
