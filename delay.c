#include "delay.h"

//���뼶��ʱ������unsigned char (1-127)

void delayXms(unsigned int i)		//@12.000MHz  xms<=127!!
{
	unsigned char j = 239;
	do
	{
		while (--j);
	} while (--i);
}