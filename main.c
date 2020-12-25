#include "STC89C5xRC.H"
#include "max7219.h"
#include "delay.h"

extern unsigned char code dispCode[38][8];
void Timer0Init(void);
unsigned char leftShift = 0;
extern unsigned char leftCode;
	
void main()
{
	unsigned char i = 0;
	max7219Init();
	Timer0Init();
	while(1)
	{
//		max7219Disp(dispCode[1]);
//		delayXms(2000);
//		i++;
//		i %= 38;
		
		if(leftShift)
		{
			leftShift = 0;
			max7219Left(dispCode[leftCode], dispCode[leftCode+1]);
		}
	}
}

void Timer0Init(void)		//10����@12.000MHz
{
//	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xF0;		//���ö�ʱ��ֵ
	TH0 = 0xD8;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	
	ET0 = 1;  //��ʱ������1����ж��������λ
	EA = 1;
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}


void timer0_ISR(void) interrupt 1 //interrupt 1ΪT0�ж�
{
	static unsigned char a = 0;
	TL0 = 0xF0;		//���ö�ʱ��ֵ
	TH0 = 0xD8;		//���ö�ʱ��ֵ	

	if (++a == 10)
	{
		a= 0;
		leftShift = 1;		
	}
}
