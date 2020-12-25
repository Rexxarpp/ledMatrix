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

void Timer0Init(void)		//10毫秒@12.000MHz
{
//	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xF0;		//设置定时初值
	TH0 = 0xD8;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	
	ET0 = 1;  //定时计数器1溢出中断允许控制位
	EA = 1;
	TR0 = 1;		//定时器0开始计时
}


void timer0_ISR(void) interrupt 1 //interrupt 1为T0中断
{
	static unsigned char a = 0;
	TL0 = 0xF0;		//设置定时初值
	TH0 = 0xD8;		//设置定时初值	

	if (++a == 10)
	{
		a= 0;
		leftShift = 1;		
	}
}
