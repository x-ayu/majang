//用于函数，结构的定义
//#pragma once
#include<stdbool.h>
struct names
{
	int Mode;
	char PlayersName1[25];
	char PlayersName2[25];
	char PlayersName3[25];
	char PlayersName4[25];
};
struct Soup
{
	char inSerial;
	char  chSign;
};
struct names	 _Interface(void);
int ChOutput(char* [], int, bool, bool, int, int);
int* AloneRandom(int, int*);
struct Soup Distribute(char* Han);