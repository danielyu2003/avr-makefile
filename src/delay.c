#include <delay.h>

void delay(volatile long int iter)
{
	int temp = iter;
	while (temp != 0)
	{
		temp--;
	}
	return;
}