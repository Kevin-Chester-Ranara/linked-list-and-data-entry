#include "Data.h"
#include "kit.h"
#include <iostream>
using namespace kit;

int main()
{
	bool quit = false;
	char buff[25];
	Data db;
	do
	{
		print("\n P(u)sh, P(o)p, D(i)splay or just fuckin (q)uit like you used to");
		int num = 0;
		static constexpr int maxbuffsize = 25;
		char* buffer = buff;
		//char buffer[maxbuffsize];
		char buffer2[maxbuffsize];
		char response = _getch();
		switch (response)
		{
		case 'u':
			print("\n Where do you want to push? (A)nywhere or at (T)op?");
			response = _getch();
			switch (response)
			{
			case 't':
				print("\n Enter value ");
				read(buffer, maxbuffsize);
				db.PushTop(str2int(buffer));
				break;
			case 'a':
				print("\n Enter position");
				read(buffer2, maxbuffsize);
				print("\n Enter value");
				read(buffer, maxbuffsize);
				db.PushAnywhere(str2int(buffer),str2int(buffer2));
				break;
			}
			break;
		case 'o':
			print("\n Where do you want to pop? (A)nywhere or at (T)op? \n");
			response = _getch();
			switch (response)
			{
			case 'a':
				print("\n Enter position");
				read(buffer2, maxbuffsize);
				num = db.PopAnywhere(str2int(buffer2));
				int2str(buffer2, num);
				print(buffer2);
				break;
			case 't':
				num = db.PopTop();
				int2str(buffer2, num);
				print(buffer2);
				break;
			}
			break;
		case 'i':
			if (db.Empty())
			{
				print("\n Gago EMpty oi");
			}
			else
				db.Display(buffer);
			break;
		case 'q':
			quit = true;
			break;
		}
	} while (!quit);
	Data sb = db;
	sb.Display(buff);
	return 0;
}