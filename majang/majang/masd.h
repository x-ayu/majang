//用于函数，结构的定义
//#pragma once
#include<stdbool.h>

//预处理
#define CuPai(A,X,B,T,I) { A[13] = TEMPORARCARDS; printf("玩家"#X"：%s出牌：\n",T);intPlay = Sequence(A,T,1,B);TEMPORARCARDS=I[intPlay - 1] , I[intPlay - 1] = A[13]; }
#define PlayersPengDetermine1 if((intTouchReturnValue=Touch(pName1,&TEMPORARCARDS,&intCardNum1,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=1;continue;}else{inCcontrolPlay=2;continue;}}
#define PlayersPengDetermine2 if((intTouchReturnValue=Touch(pName2,&TEMPORARCARDS,&intCardNum2,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=2;continue;}else{inCcontrolPlay=3;continue;}}
#define PlayersPengDetermine3 if((intTouchReturnValue=Touch(pName3,&TEMPORARCARDS,&intCardNum3,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=3;continue;}else{inCcontrolPlay=4;continue;}}
#define PlayersPengDetermine4 if((intTouchReturnValue=Touch(pName4,&TEMPORARCARDS,&intCardNum4,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=4;continue;}else{inCcontrolPlay=1;continue;}}
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
int Touch(SOUP*, SOUP*,int*,int);
int Sequence(SOUP*,char*,int , int);
int OWTouch(SOUP* pCardGroup, SOUP TEmporary);