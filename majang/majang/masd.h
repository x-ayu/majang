//���ں������ṹ�Ķ���
//#pragma once
#include<stdbool.h>

//Ԥ����
#define CuPai(A,X,T,I) { A[13] = TEMPORARCARDS; printf("���"#X"��%s���ƣ�\n",T);intPlay = Sequence(A,T);I[intPlay - 1] = A[13];}


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
int ChOutput(char* [], int, bool, bool, int, int,char*);//���һ������ʾ�������
int* AloneRandom(int, int*);
SOUP Distribute(char* Han);
