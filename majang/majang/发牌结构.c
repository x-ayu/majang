#include"masd.h"

SOUP Distribute(int *Han)
{
	static int inX = 0;
	SOUP Sards = {0,0};
	int inY = Han[inX] / 4;
	if (inY == 0)
	{
		Sards.inSerial = 1;
		Sards.chSign = 'W';
	}
	if (inY == 1)
	{
		Sards.inSerial = 2;
		Sards.chSign = 'W';
	}
	if (inY == 2)
	{
		Sards.inSerial = 3;
		Sards.chSign = 'W';
	}
	if (inY == 3)
	{
		Sards.inSerial = 4;
		Sards.chSign = 'W';
	}
	if (inY == 4)
	{
		Sards.inSerial = 5;
		Sards.chSign = 'W';
	}
	if (inY == 5)
	{
		Sards.inSerial = 6;
		Sards.chSign = 'W';
	}
	if (inY == 6)
	{
		Sards.inSerial = 7;
		Sards.chSign = 'W';
	}
	if (inY == 7)
	{
		Sards.inSerial = 8;
		Sards.chSign = 'W';
	}
	if (inY == 8)
	{
		Sards.inSerial = 9;
		Sards.chSign = 'W';
	}
	if (inY == 9)
	{
		Sards.inSerial = 1;
		Sards.chSign = 'T';
	}
	if (inY == 10)
	{
		Sards.inSerial = 2;
		Sards.chSign = 'T';
	}
	if (inY == 11)
	{
		Sards.inSerial = 3;
		Sards.chSign = 'T';
	}
	if (inY == 12)
	{
		Sards.inSerial = 4;
		Sards.chSign = 'T';
	}
	if (inY == 13)
	{
		Sards.inSerial = 5;
		Sards.chSign = 'T';
	}
	if (inY == 14)
	{
		Sards.inSerial = 6;
		Sards.chSign = 'T';
	}
	if (inY == 15)
	{
		Sards.inSerial = 7;
		Sards.chSign = 'T';
	}
	if (inY == 16)
	{
		Sards.inSerial = 8;
		Sards.chSign = 'T';
	}
	if (inY == 17)
	{
		Sards.inSerial = 9;
		Sards.chSign = 'T';
	}
	if (inY == 18)
	{
		Sards.inSerial = 1;
		Sards.chSign = 'L';
	}
	if (inY == 19)
	{
		Sards.inSerial = 2;
		Sards.chSign = 'L';
	}
	if (inY == 20)
	{
		Sards.inSerial = 3;
		Sards.chSign = 'L';
	}
	if (inY == 21)
	{
		Sards.inSerial = 4;
		Sards.chSign = 'L';
	}
	if (inY == 22)
	{
		Sards.inSerial = 5;
		Sards.chSign = 'L';
	}
	if (inY == 23)
	{
		Sards.inSerial = 6;
		Sards.chSign = 'L';
	}
	if (inY == 24)
	{
		Sards.inSerial = 7;
		Sards.chSign = 'L';
	}
	if (inY == 25)
	{
		Sards.inSerial = 8;
		Sards.chSign = 'L';
	}
	if (inY == 26)
	{
		Sards.inSerial = 9;
		Sards.chSign = 'L';
	}
	if (inY == 27)
	{
		Sards.inSerial = 0;
		Sards.chSign = 'W';
	}
	if (inY == 28)
	{
		Sards.inSerial = 0;
		Sards.chSign = 'S';
	}
	if (inY == 29)
	{
		Sards.inSerial = 0;
		Sards.chSign = 'E';
	}
	if (inY == 30)
	{
		Sards.inSerial = 0;
		Sards.chSign ='N';
	}
	if (inY == 31)
	{
		Sards.inSerial = 0;
		Sards.chSign = 'Z';
	}
	if (inY == 32)
	{
		Sards.inSerial = 0;
		Sards.chSign = 'K';
	}
	if (inY == 33)
	{
		Sards.inSerial = 0;
		Sards.chSign = 'F';
	}
	inX++;
	return Sards;
}
