//用于函数，结构的定义
//#pragma once
#include<stdbool.h>

//预处理
#define CuPai(A,X,T,I) { A[13] = TEMPORARCARDS; printf("玩家"#X"：%s出牌：\n",T);intPlay = Sequence(A,T,1,intCardNum);I[intPlay - 1] = A[13];}


//结构定义
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

 //函数声明
NAMES	 _Interface(void);
int ChOutput(char* [], int, int, bool, int, int,char*);//最后一个量表示玩家名称
int* AloneRandom(int, int*);
SOUP Distribute(char* Han);
int Touch(SOUP*, SOUP,int);
int Sequence(SOUP*,char*,int , int);