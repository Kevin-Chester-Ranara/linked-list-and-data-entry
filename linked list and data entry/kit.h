#pragma once
#include <conio.h>
namespace kit
{
	void printfixed(char* str, int w);
	void print(const char* str);
	void strcopy(char* from_str, char* to_str, int maxbuffsize);
	void read(char* buffer, int maxbuffsize);
	int str2int(char* str);
	void strrev(char* str);
	void int2str(char* str, int num);
}