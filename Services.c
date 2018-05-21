/*
 * Services.c
 *
 *  Created on: May 21, 2018
 *      Author: tiger
 */

#include "main.h"
#include "Services.h"


void read_scanf_name(char *name , int size)
{
	for(int index = 0 ; index <size-1 ; index ++)
	{
		scanf("%c", &name[index]);

		if(name[index] == END_NAME && index > 2 )
		{
			name[index] = 0;
			break;
		}
		if(name[0] == END_NAME && index < 1)
		{
			index=-1;
		}
	}
}

