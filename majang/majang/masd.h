//���ں������ṹ�Ķ���
//#pragma once
#include<stdbool.h>

//Ԥ����
#define CuPai(A,X,B,T,Q,W,E,R,Y,U,I,O) {  printf("���"#X"��%s���ƣ�\n",T);intPlay = ChOutput(O,B, 0, 0, 0, 0, T,Q,W,E,R,Y,U,I);TEMPORARCARDS=A[intPlay - 1] , A[intPlay - 1] = A[13]; }
#define PlayersPengDetermine1 if((intTouchReturnValue=Touch(pName1,&TEMPORARCARDS,&intCardNum1))>0){if(intTouchReturnValue==2){inCcontrolPlay=1;GangRecord(szBarRecord[0], TEMPORARCARDS);intTouchReturnValue=0;continue;}else{inCcontrolPlay=2;}}
#define PlayersPengDetermine2 if((intTouchReturnValue=Touch(pName2,&TEMPORARCARDS,&intCardNum2))>0){if(intTouchReturnValue==2){inCcontrolPlay=2;GangRecord(szBarRecord[1], TEMPORARCARDS);intTouchReturnValue=0;continue;}else{inCcontrolPlay=3;}}
#define PlayersPengDetermine3 if((intTouchReturnValue=Touch(pName3,&TEMPORARCARDS,&intCardNum3))>0){if(intTouchReturnValue==2){inCcontrolPlay=3;GangRecord(szBarRecord[2], TEMPORARCARDS);intTouchReturnValue=0;continue;}else{inCcontrolPlay=4;}}
#define PlayersPengDetermine4 if((intTouchReturnValue=Touch(pName4,&TEMPORARCARDS,&intCardNum4))>0){if(intTouchReturnValue==2){inCcontrolPlay=4;GangRecord(szBarRecord[3], TEMPORARCARDS);intTouchReturnValue=0;continue;}else{inCcontrolPlay=5;}}
#define PrintfCard1 {printf("���%s���ƣ�",WJ.szPlayersName1);for(int i=0;i<13;i++){printf("%d%c ", pName1[i].inSerial, pName1[i].chSign);}printf("\n");}
#define PrintfCard2 {printf("���%s���ƣ�",WJ.szPlayersName2);for(int i=0;i<13;i++){printf("%d%c ", pName2[i].inSerial, pName2[i].chSign);}printf("\n");}
#define PrintfCard3 {printf("���%s���ƣ�",WJ.szPlayersName3);for(int i=0;i<13;i++){printf("%d%c ", pName3[i].inSerial, pName3[i].chSign);}printf("\n");}
#define PrintfCard4 {printf("���%s���ƣ�",WJ.szPlayersName4);for(int i=0;i<13;i++){printf("%d%c ", pName4[i].inSerial, pName4[i].chSign);}printf("\n");}

//�ṹ����
typedef struct//���ڼ�¼ģʽ�������
{
	int intMode;
	char szPlayersName1[254];
	char szPlayersName2[254];
	char szPlayersName3[254];
	char szPlayersName4[254];
} NAMES;
 typedef struct//���ڴ�����
{
    char inSerial;
	char  chSign;
} SOUP;

 //��������
NAMES	 _Interface(void);//���ڳ����ʼ����ʾ
int ChOutput(char* [], int, int, int, int, int,char*,char*[],char*,char*[],char*,char*[],char*,char*);//���ڿ������������1Ϊ������ַ�����//���һ������ʾ�������
int* AloneRandom(int, int*);//����һ�����ظ���������У�����1Ϊ��Ŀ������2Ϊ�������еĵ�ַ
SOUP Distribute(char* Han);//���ڷ��ƣ�����Ϊ���ɵ��������
int Touch(SOUP*, SOUP*,int*);//�ж��Ƿ����ܣ�������1Ϊ���Ƶ�ַ������2Ϊ�յõ����Ƶĵ�ַ
int Sequence(SOUP*,char*,int , int);//Ϊ�������򣬲���1Ϊ���Ƶ�ַ������4Ϊ������Ŀ��������3��Ϊ0�򻹿��Ƴ��ƣ�����2Ϊ���������
int OWTouch(SOUP* pCardGroup, SOUP TEmporary,int* intCardNum);//�ж��Ӹܣ�����1Ϊ���Ƶ�ַ������2Ϊ�յõ����ƣ�
void GangRecord(char*, SOUP);//�������ַ����м�¼�ܵ���
void HUDetermine(SOUP*,int ,SOUP,char*);//�ж��Ƿ���ƣ�����1Ϊ���Ƶ�ַ������2Ϊ������Ŀ��������Ϊ�յõ�����
void QIRecord(char*, SOUP);