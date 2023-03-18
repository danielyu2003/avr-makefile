#include "delay.h"

void delay(volatile long int iter)
{
	for (int i = 0; i < iter; i++)
	{
		i--;
		i++;
	}
	return;
}