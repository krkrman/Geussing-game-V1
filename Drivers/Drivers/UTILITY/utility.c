/*
 * utility.c
 *
 * Created: 9/14/2021 2:22:15 PM
 *  Author: Karim Essam
 */ 
#include "../LIB/STD_TYPES.h"
u8 UTILITY_generateRandomNumber(u8 lower , u8 upper){
	return (rand() % (upper - lower + 1)) + lower;
}

void UTILITY_f32ToString(char* str, f32 d, u8 n)
{
	//For integer part conversion
	u16 t = 1;
	u16 temp = 1;
	u16 i = 0;
	while(t <= (int)d)
	t *= 10;
	temp = t/10;
	for(i = 0; temp > 0; i++)
	{
		u16 digit = ((u16)d)/temp;
		str[i] = digit + '0';
		d = d - (double)(digit*temp);
		temp /= 10;
	}
	if(t==1)
		str[i++] = '0';
	//Add decimal point
	if (n != 0)
		str[i++] = '.';

	//For after decimal point conversion
	for(; n > 0; n--)
	{
		d = d*10;
		str[i++] = (u8)d + '0';
		d -= (u8)d;
	}

	//Null end
	str[i] = 0;
}