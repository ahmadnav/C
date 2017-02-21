#ifndef SYSTEM_H
#define SYSTEM_H
#include "types.h"

/* Read from port */
uint8 inportb (uint16 _port)
{
	uint8 rv;
	//Modify rv get value from port and return it via rv
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port)); 
	return rv;
}

/* Write to port */
void outportb (uint16 _port, uint8 _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data)); 
}


#endif
