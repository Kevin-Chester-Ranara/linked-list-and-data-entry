#include "kit.h"

void kit::printfixed(char* str, int w)
{
	int n = 0;
	for (; *str != 0; str++)
	{
		_putch(*str);
		n++;
	}
	for (; n < w; n++)
	{
		_putch(' \n');
	}

}

void kit::print(const char* str)
{
	for (; *str != 0; str++)
	{
		_putch(*str);
	}
}

void kit::strcopy(char* from_str, char* to_str, int maxbuffsize)
{
	int n = 0;
	for (; *from_str != 0 && (n + 1) < maxbuffsize; from_str++, to_str++)
	{
		*to_str = *from_str;
		n++;
	}
	*to_str = 0;
}

void kit::read(char* buffer, int maxbuffsize)
{
	const char* const pend = buffer + maxbuffsize;
	for (char c = _getch(); c != 13 && (buffer + 1) < pend; c = _getch(), buffer++)
	{
		*buffer = c;
		_putch(c);
	}
	*buffer = 0;
}

int kit::str2int(char* str)
{
	int digitplace = 1;
	int num = 0;
	for (; *str != 0; str++);
	str--;
	for (; *str >= '0' && *str <= '9'; str--)
	{
		num += (*str - '0') * digitplace;
		digitplace *= 10;
	}
	return num;
}

void kit::strrev(char* str)
{
	char* pStart = str;
	for (; *str != 0; str++);
	str--;
	for (; pStart < str; pStart++, str--)
	{
		char temp;
		temp = *pStart;
		*pStart = *str;
		*str = temp;
	}
}

void kit::int2str(char* str, int num)
{
	char* start = str;
	if (num > 0)
	{
		for (; num > 0; num /= 10, str++)
		{
			*str = '0' + num % 10;
		}
		*str = 0;
		strrev(start);
	}
	else
	{
		*str = '0';
		str++;
		*str = 0;
	}
	
}

