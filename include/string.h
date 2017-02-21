#ifndef STRING_H
#define STRING_H

#include "types.h"

/*Function calculates the length of the string*/
uint16 strlength(string ch)
{
	uint16 i = 0; //Initialize
	while(ch[i++]); //While i is true repeat the loop, until we encounter null character '\0' which transalates to 0 (false) than end
	return i;
}

#endif
