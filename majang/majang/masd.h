//���ں������ṹ�Ķ���
//#pragma once
#include<stdbool.h>

//Ԥ����
#define CuPai(A,X,B,T,I) { A[13] = TEMPORARCARDS; printf("���"#X"��%s���ƣ�\n",T);intPlay = Sequence(A,T,1,B);TEMPORARCARDS=I[intPlay - 1] , I[intPlay - 1] = A[13]; }
#define PlayersPengDetermine1 if((intTouchReturnValue=Touch(pName1,&TEMPORARCARDS,&intCardNum1,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=1;GangRecord(szBarRecord[0], TEMPORARCARDS);intTouchReturnValue=0;continue;}else{inCcontrolPlay=2;}}
#define PlayersPengDetermine2 if((intTouchReturnValue=Touch(pName2,&TEMPORARCARDS,&intCardNum2,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=2;GangRecord(szBarRecord[1], TEMPORARCARDS);intTouchReturnValue=0;continue;}else{inCcontrolPlay=3;}}
#define PlayersPengDetermine3 if((intTouchReturnValue=Touch(pName3,&TEMPORARCARDS,&intCardNum3,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=3;GangRecord(szBarRecord[2], TEMPORARCARDS);intTouchReturnValue=0;continue;}else{inCcontrolPlay=4;}}
#define PlayersPengDetermine4 if((intTouchReturnValue=Touch(pName4,&TEMPORARCARDS,&intCardNum4,0))>0){if(intTouchReturnValue==2){inCcontrolPlay=4;GangRecord(szBarRecord[3], TEMPORARCARDS);intTouchReturnValue=0;continue;}else{inCcontrolPlay=5;}}
//�ṹ����
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

 //��������
NAMES	 _Interface(void);
int ChOutput(char* [], int, int, bool, int, int,char*);//���һ������ʾ�������
int* AloneRandom(int, int*);
SOUP Distribute(char* Han);
int Touch(SOUP*, SOUP*,int*,int);
int Sequence(SOUP*,char*,int , int);
int OWTouch(SOUP* pCardGroup, SOUP TEmporary);
void GangRecord(char*, SOUP);