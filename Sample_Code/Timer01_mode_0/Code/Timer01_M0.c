/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2017 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/21/2017
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E003 Timer0/1 Mode0 demo code
//***********************************************************************************************************
#include "N76E003.h"


#define TH0_INIT        						(HIBYTE(TIMER_DIV12_VALUE_1ms)) 
#define TL0_INIT        						(LOBYTE(TIMER_DIV12_VALUE_1ms))

char putchar (char c)  {
  while (!TI);
  TI = 0;
  return (SBUF = c);
}


/************************************************************************************************************
*    TIMER 0 interrupt subroutine
************************************************************************************************************/
void Timer0_ISR (void) interrupt 1          //interrupt address is 0x000B
{
	static uint16_t counter = 0;
	clr_TF0;
    TH0 = TH0_INIT;
    TL0 = TL0_INIT;    

	if (counter++ > 1000)
	{
		counter = 0;
		P11 = ~P11;															// GPIO toggle when interrupt
		P12 ^= 1;
	}
}

/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{
	static uint16_t LOG = 0;

	Set_All_GPIO_Quasi_Mode;	
    // P11_PushPull_Mode;	
    // P12_PushPull_Mode;

	InitialUART0_Timer3(115200);
	TI = 1;

	TIMER0_MODE1_ENABLE;
	clr_T0M;
    
	TH0 = TH0_INIT;
	TL0 = TL0_INIT;
	clr_TF0;

	set_TR0;                                    //Timer0 run    
	set_ET0;                                    //enable Timer0 interrupt
	
	set_EA;                                     //enable interrupts
	

	while(1)
	{
		Timer1_Delay10ms(10);	
		printf("LOG : %4d\r\n",LOG++);
	}
}
