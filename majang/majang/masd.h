//用于函数，结构的定义
//#pragma once
#include<stdbool.h>
typedef struct
{
	int intMode;
	char szPlayersName1[25];
	char szPlayersName2[25];
	char szPlayersName3[25];
	char szPlayersName4[25];
} NAMES;
 typedef struct
{
    char inSerial;
	char  chSign;
} SOUP;
NAMES	 _Interface(void);
int ChOutput(char* [], int, bool, bool, int, int);
int* AloneRandom(int, int*);
 SOUP Distribute(char* Han);