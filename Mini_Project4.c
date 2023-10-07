/*
 * Mini_Project4.c
 *
 *  Created on: Oct 12, 2022
 *      Author: georg
 */

#include "avr/io.h" /* To use the IO Ports Registers */
#include "lcd.h"
#include "ultrasonic_sensor.h"

int main (void){
	uint16 distance=0;

	/*Enable interrupts by setting I-bit*/
	SREG |= (1<<7);

	/*Initialize Ultransonic Driver*/
	Ultrasonic_init();

	/*Initialize LCD Driver*/
	LCD_init();

	/*Display the string "Distance =   cm" only once at the second row*/
	LCD_displayString(" Distance =   cm");

	while(1)
	{
		distance = Ultrasonic_readDistance();

		// Display the Distance value every time at same position on the LCD
		LCD_moveCursor(0,11);
		if(distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			// In case the digital value is two or one digits print space in the next digit place
			LCD_displayString(" ");
		}
	}
}
