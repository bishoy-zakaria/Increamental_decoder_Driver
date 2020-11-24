/*
 * ICU.c
 *
 * Created: 11/10/2020 7:43:38 PM
 * Author : BISHOY
 */ 

#include "Timer.h"
#include "Timer_Cfg.h"
#include "LCD.h"
#define F_CPU 16000000
#include <util/delay.h>

extern volatile uint8  ICU_Counter;
extern volatile uint32 C1;
extern volatile uint32 C2;
extern volatile uint32 C3;
extern volatile uint8  Decoder_Counter;

int main(void)
{
	uint32 resolution=0;
	uint32 angel=0;
	uint32 TOTAL=0;
	uint32 Frequency=0;
	uint32 Velocity =0;
	LCD_Init();
	timer1_init();
	ICU_Init ();
	timer1_start();
    while (1) 
    {
		
			resolution = (360/sluts_num);
			angel = Decoder_Counter*resolution;
			
			TOTAL=C3-C1;
			Frequency=16000000 /(1 * TOTAL);
			
			Velocity = (Frequency *60) / (sluts_num);
			
			LCD_WriteString("Angel:");
			LCD_WriteInteger(angel);
			LCD_GoTo(1, 0);
			LCD_WriteString("velocity:");
			LCD_WriteInteger(Velocity);
			_delay_ms(500);
			LCD_Clear();
			SET_BIT(TIMSK,5);
			SET_BIT(TIMSK,2);
		
    }
	
}

