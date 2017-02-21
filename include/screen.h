#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"
int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2; //Screen Width, height, screen depth 2 (each of the characters takes 2 bytes -> char and its color)


void clearLine(uint8 from, uint8 to)
{
	uint16 i = sw * from * sd;//from where to delete, sw
	string vidmem=(string)0xb8000; //string is char pointer where chhar is a byte
	/*Screen is divided into 80 columns and 25 rows, where the address of [0,0] is 0xb8000, 	increasing this address goes accross the row and onto next column after end of row*/
	for(i;i<(sw*(to+1)*sd); i++)
	{
		vidmem[i] = 0x0;
	}
	
}

void updateCursor()
{
	unsigned temp;
	
	/*CursorY represents column, where each column is screen width(screen width) wide*/
	temp = cursorY * sw + cursorX;

	outportb(0x3D4,15); /*In x86 these ports control the mouse position send the upper and 		lower bytes*/
	/*Lower BYTE*/
	outportb(0x3D5, temp & 0xFF);
	outportb(0x3D4, 14);
	/* Send the Higher Byte to vga Index Register*/
	outportb(0x3D5, (temp >> 8) & 0xFF); 
}

void clearSreen()
{
	clearLine(0,sh-1);
	cursorX = 0;
	cursorY = 0;
	updateCursor();
}

#endif

