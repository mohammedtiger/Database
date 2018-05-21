/*
 * Services.c
 *
 *  Created on: May 21, 2018
 *      Author: tiger
 */

#include "main.h"
#include "Services.h"

static struct termios old, new;

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

int Searhing (int *data , int *search , int size)
{
	int rc = 0;
	for (int index = 0; index < size ; index ++)
	{
		if (*data == search[index])
		{
			rc = 1;
		}
	}
	return rc;
}

