/*
* This part provide Project Description, key functions, and other project-related information
* Project     : Lab 1
* Author      : Hoang Vo	
* Date        : 28/07/2017
* Board       : Nu-LB-NUC140
* MCU         : NUC140VE3CN
* Functions   :	Controlling four 7-segment display
*/

#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"


int main(void)
{
	//System initialization
    SYS_Init();

// 7-Segments
		PC -> PMD = 0x00;
		PC -> PMD = 0x5500;
	
/*
		PC -> PMD &= ~(0x03 << 8);
		PC -> PMD |= (0x01 << 8);

		PC -> PMD &= ~(0x03 << 10);
		PC -> PMD |= 0x01 << 10;
	
		PC -> PMD &= ~(0x03 << 12);
		PC -> PMD |= 0x01 << 12;

		PC -> PMD &= ~(0x03 << 14);
		PC -> PMD |= 0x01 << 14;
	
		PE -> PMD &= ~(0x03 << 0);
		PE -> PMD |= 0x01 << 0;

		PE -> PMD &= ~(0x03 << 2);
		PE -> PMD |= 0x01 << 2;
		
		PE -> PMD &= ~(0x03 << 4);
		PE -> PMD |= 0x01 << 4;
		
		PE -> PMD &= ~(0x03 << 6);
		PE -> PMD |= 0x01 << 6;

		PE -> PMD &= ~(0x03 << 8);
		PE -> PMD |= 0x01 << 8;

		PE -> PMD &= ~(0x03 << 10);
		PE -> PMD |= 0x01 << 10;
		
		PE -> PMD &= ~(0x03 << 12);
		PE -> PMD |= 0x01 << 12;
		
		PE -> PMD &= ~(0x03 << 14);
		PE -> PMD |= 0x01 << 14;
*/	
	
// Buzzer
		PB -> PMD &= ~(0x03 << 22);
		PB -> PMD |= (0x01 << 22);
		
// INT
		PB -> PMD &= ~(0x03 << 30);
		PB -> PMD |= (0x00 << 30);
		
    while(1)
		{
			
//											0			1			2			3			4			5			6			7			8			9			A			B			C			D			E			F
			char status[] = {0x7D, 0x11, 0xF8, 0xB9, 0x95, 0xAD, 0xED, 0x19, 0xFD, 0xBD, 0xDD, 0xE5, 0x6C, 0xF1, 0xEC, 0xCC, 0x00};
			
			
/*			
			if (!(PB->PIN & (1<<15)))
			{
				PB -> DOUT &= ~(1<<11);
				CLK_SysTickDelay(1000000);
				PB -> DOUT |= (1<<11);
				CLK_SysTickDelay(1000000);
			}
*/		

			PE -> DOUT = ~status[8];
			
/*
//	U14		
			PC -> DOUT &= ~(1<<7);
			PC -> DOUT &= ~(1<<6);
			PC -> DOUT &= ~(1<<5);
			
			PC -> DOUT |= (1<<4);
			PE -> DOUT = ~status[0];
			
			CLK_SysTickDelay(1000);

//  U15			
			PC -> DOUT &= ~(1<<4);
			
			PC -> DOUT |= (1<<5);
			PE -> DOUT = ~status[1];
			
			CLK_SysTickDelay(1000);

//	U16			
			PC -> DOUT &= ~(1<<5);
			
			PC -> DOUT |= (1<<6);
			PE -> DOUT = ~status[2];
			
			CLK_SysTickDelay(1000);
			
//	U17
			PC -> DOUT &= ~(1<<6);
			
			PC -> DOUT |= (1<<7);
			PE -> DOUT = ~status[3];
		
			CLK_SysTickDelay(1000);
*/

    }
}
