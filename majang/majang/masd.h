//用于函数，结构的定义
//#pragma once
#include<stdbool.h>

//预处理
#define CuPai(A,X,B,T,I) { A[13] = TEMPORARCARDS; printf("玩家"#X"：%s出牌：\n",T);intPlay = Sequence(A,T,1,B);TEMPORARCARDS=I[intPlay - 1] , I[intPlay - 1] = A[13]; }
#define PlayersPengDetermine1 if((intTouchReturnValue=Touch(pName1,&TEMPORARCARDS,&intCardNum1,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=1;GangRecord(szBarRecord[0], TEMPORARCARDS);intTouchReturnValue=0;system("cls");continue;}else{inCcontrolPlay=2;}}
#define PlayersPengDetermine2 if((intTouchReturnValue=Touch(pName2,&TEMPORARCARDS,&intCardNum2,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=2;GangRecord(szBarRecord[1], TEMPORARCARDS);intTouchReturnValue=0;system("cls");continue;}else{inCcontrolPlay=3;}}
#define PlayersPengDetermine3 if((intTouchReturnValue=Touch(pName3,&TEMPORARCARDS,&intCardNum3,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=3;GangRecord(szBarRecord[2], TEMPORARCARDS);intTouchReturnValue=0;system("cls");continue;}else{inCcontrolPlay=4;}}
#define PlayersPengDetermine4 if((intTouchReturnValue=Touch(pName4,&TEMPORARCARDS,&intCardNum4,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=4;GangRecord(szBarRecord[3], TEMPORARCARDS);intTouchReturnValue=0;system("cls");continue;}else{inCcontrolPlay=5;}}
#define PrintfCard1 {printf("玩家%s手牌：",WJ.szPlayersName1);for(int i=0;i<13;i++){printf("%d%c ", pName1[i].inSerial, pName1[i].chSign);}printf("\n");}
#define PrintfCard2 {printf("玩家%s手牌：",WJ.szPlayersName2);for(int i=0;i<13;i++){printf("%d%c ", pName2[i].inSerial, pName2[i].chSign);}printf("\n");}
#define PrintfCard3 {printf("玩家%s手牌：",WJ.szPlayersName3);for(int i=0;i<13;i++){printf("%d%c ", pName3[i].inSerial, pName3[i].chSign);}printf("\n");}
#define PrintfCard4 {printf("玩家%s手牌：",WJ.szPlayersName4);for(int i=0;i<13;i++){printf("%d%c ", pName4[i].inSerial, pName4[i].chSign);}printf("\n");}

//结构定义
typedef struct//用于记录模式，玩家名
{
	int intMode;
	char szPlayersName1[25];
	char szPlayersName2[25];
	char szPlayersName3[25];
	char szPlayersName4[25];
} NAMES;
 typedef struct//用于储存牌
{
    char inSerial;
	char  chSign;
} SOUP;

 //函数声明
NAMES	 _Interface(void);//用于程序最开始的显示
int ChOutput(char* [], int, int, bool, int, int,char*);//用于控制输出，参数1为输出的字符串，最后一个量表示玩家名称
int* AloneRandom(int, int*);//生成一个不重复的随机数列，参数1为数目，参数2为保存数列的地址
SOUP Distribute(char* Han);//用于发牌，参数为生成的随机数列
int Touch(SOUP*, SOUP*,int*,int);//
int Sequence(SOUP*,char*,int , int);//为手牌排序，参数1为手牌地址，参数4为手牌数目，若参数3不为0则还控制出牌，参数2为出牌玩家1名
int OWTouch(SOUP* pCardGroup, SOUP TEmporary,int* intCardNum);//判定加杠，参数1为手牌地址，参数2为刚得到的牌，
void GangRecord(char*, SOUP);//用于在字符串中记录杠的牌
void HUDetermine(SOUP*,int ,SOUP);//判定是否胡牌，参数1为手牌地址，参数2为手牌数目，参数三为刚得到的牌