//-------------------------------------------------------------------------------------------------------------
//This part provide Project Description, key functions, and other project-related information
//Project     :
//Author      :
//Date        : 
//Board       : Nu-LB-NUC140
//MCU         : NUC140VE3CN
//Functions   :
//
//
//-------------------------------------------------------------------------------------------------------------


#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"

#define Code 0534


int d,k,l;

int num;

int main(void)
{
	//-------------------------------------------------------------------------------------------------------------
	//System initialization
	//-------------------------------------------------------------------------------------------------------------
    SYS_Init();
	
	
	#if Code == 052 //Code 5.2
    GPIO_SetMode(PC, BIT12, GPIO_MODE_OUTPUT);//Configure PortC and its pin PC12
	  while(1){
		PC12 =0; // turn on LED
		CLK_SysTickDelay(100000); // Delay
		PC12 =1; // turn off LED
		CLK_SysTickDelay(100000); // Delay 
    }
	#endif
				
	#if Code == 0524 //Code 5.2.4
		GPIO_SetMode(PC, BIT14, GPIO_MODE_OUTPUT);//Configure PortC and its pin PC14 to OUTPUT mode
	  while(1){
		PC14 =0; // turn on LED7
		CLK_SysTickDelay(100000); // Delay
		PC14 =1; // turn off LED7
		CLK_SysTickDelay(100000); // Delay 
		}
	#endif
		
	#if Code == 0525 //Code 5.2.5
		GPIO_SetMode(PC, BIT12, GPIO_MODE_OUTPUT);//Configure PortC and its pin PC12
		GPIO_SetMode(PC, BIT13, GPIO_MODE_OUTPUT);//Configure PortC and its pin PC13
		GPIO_SetMode(PC, BIT14, GPIO_MODE_OUTPUT);//Configure PortC and its pin PC14
		GPIO_SetMode(PC, BIT15, GPIO_MODE_OUTPUT);//Configure PortC and its pin PC15
		while(1){
		PC12 =0; // turn on LED5
		CLK_SysTickDelay(100000); // Delay
		PC12 =1; // turn off LED5
		CLK_SysTickDelay(100000); // Delay 
		PC13 =0; // turn on LED6
		CLK_SysTickDelay(100000); // Delay
		PC13 =1; // turn off LED6
		CLK_SysTickDelay(100000); // Delay 
		PC14 =0; // turn on LED7
		CLK_SysTickDelay(100000); // Delay
		PC14 =1; // turn off LED7
		CLK_SysTickDelay(100000); // Delay 
		PC15 =0; // turn on LED8
		CLK_SysTickDelay(100000); // Delay
		PC15 =1; // turn off LED8
		CLK_SysTickDelay(100000); // Delay 			 
    }		
	#endif	
		
	#if Code == 053 //Code5.3
		PC->PMD &= ~(0x03)<< 24;
		PC->PMD |= (0x01) << 24;
		while(1){
		PC->DOUT ^= 1 << 12;
		CLK_SysTickDelay(100000); // Delay
		}
	#endif
		
#if Code== 0534 //Code5.3.4
		
		PC->PMD &= ~(0xFF)<< 24;
		PC->PMD |= (0x55) << 24;
// 		PC->PMD &= ~(0x03)<< 26;
// 		PC->PMD |= (0x01) << 26;
// 		PC->PMD &= ~(0x03)<< 28;
// 		PC->PMD |= (0x01) << 28;
// 		PC->PMD &= ~(0x03)<< 30;
// 		PC->PMD |= (0x01) << 30;
		while(1){
			uint32_t i;
				for(i=12;i<=15;i++){
					PC->DOUT ^= 1 << i;
					CLK_SysTickDelay(10000000); // Delay
					PC->DOUT ^= 1 << i;
				}
		}
	#endif
		
#if Code == 061 //Code 6.a
		GPIO_SetMode(PB, BIT11, GPIO_MODE_OUTPUT);//Configure PortB and its pin PB11
	  while(1){
		PB11 =0; // turn on Buzzer
		CLK_SysTickDelay(100000); // Delay
		PB11 =1; // turn off Buzzer
		CLK_SysTickDelay(100000); // Delay 
		}
#endif
		
#if Code == 062 //Code 6.b
			
		PC -> DOUT =~(0xF000);
		
		num=0;
		while(1){
			uint32_t i;
			//unsigned char numb[10]={0x7D,0x11,0xF8,0xB9,0x95,0xAD,0xED,0x19,0xFD,0xBD};
			uint16_t numb[10] = {0x82, 0xEE, 0x07, 0x46, 0x6A, 0x52, 0x12, 0xE6, 0x02, 0x42};		
					for(i=4;i<=7;i++){
						PC -> DOUT = (0xF000);
						PE -> DOUT = (numb[num]); 
						CLK_SysTickDelay(25000); // Delay 
						PC -> DOUT ^= 1<<i	;
						
						if(num>=9){
							num=0;
						}else {num++;}
						
						CLK_SysTickDelay(1000000); // Delay 
						}
			}			
#endif

			
}
