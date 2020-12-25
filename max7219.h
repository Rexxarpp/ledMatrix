#ifndef __MAX_7219_H_
#define __MAX_7219_H_

typedef enum 
{
	Max7219_No_Op = 0x50,
	Max7219_Digit_0 = 0x51,
	Max7219_Digit_1 = 0x52,
	Max7219_Digit_2 = 0x53,
	Max7219_Digit_3 = 0x54,
	Max7219_Digit_4 = 0x55,
	Max7219_Digit_5 = 0x56,
	Max7219_Digit_6 = 0x57,
	Max7219_Digit_7 = 0x58,
	Max7219_Decode_Mode = 0x59,
	Max7219_Intensity = 0x5A,
	Max7219_Scan_Limit = 0x5B,
	Max7219_Shutdown = 0x5C,
	Max7219_DispTest = 0x5F,
}Max7219_addr_code;



void spiWrite(Max7219_addr_code addr, unsigned char dat);
void max7219Disp(unsigned char * buf);
void max7219Init();
void max7219Left(unsigned char * buf1, unsigned char * buf2);
#endif