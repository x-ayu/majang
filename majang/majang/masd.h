//用于函数，结构的定义
//#pragma once
#include<stdbool.h>
struct NAMES
{
	int intMode;
	char szPlayersName1[25];
	char szPlayersName2[25];
	char szPlayersName3[25];
	char szPlayersName4[25];
};
struct SOUP
{
	char inSerial;
	char  chSign;
};
struct NAMES	 _Interface(void);
int ChOutput(char* [], int, bool, bool, int, int);
int* AloneRandom(int, int*);
struct SOUP Distribute(char* Han);