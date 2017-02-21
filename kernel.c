#include "include/screen.h"
kmain()
{
	/*char* vidmem =(char*)0xb8000; //Physical Memory Address Of Text Buffer.
	vidmem[0] = 'A';	
	vidmem[1] = 0x02; // Grey Color 
	vidmem[2] = 'h';
	vidmem[3] = 0x07;
	vidmem[4] = 'm';
	vidmem[5] = 0x07;
	vidmem[6] = 'a';
	vidmem[7] = 0x07;
	vidmem[8] = 'd';
	vidmem[9] = 0x07;*/
	cursorX = 0;
	cursorY = 0;
	updateCursor();
	return 0;
}
