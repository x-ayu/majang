#include"masd.h"
#include<stdlib.h>
#include<stdio.h>

#define SURENU(X) if (X % 3 == 0)X = 0;else if (X % 3 == 2)X = 1;else X = 2;

int HuPai(char [], int );

void HUDetermine(SOUP* pName, int intCardNum, SOUP TEMPORARCARDS)
{
	char chaLSName[14];
	int intWNum=0, intTNum=0, intLNum=0, intENum=0, intWENum=0, intSNum=0, intNNum=0, intZNum=0, intKNum=0, intFNum=0;
	for (int i = 0; i < intCardNum; i++)
	{
		chaLSName[i]= pName[i].inSerial;
	}
	chaLSName[intCardNum]= TEMPORARCARDS.inSerial;

	for (int i = 0; i < intCardNum; i++)
	{
		if (pName[i].chSign == 'W' && chaLSName[i] != 0)
		{
			intWNum++; 
		}
		else if (pName[i].chSign == 'T')
		{
			intTNum++; 
		}
		else if (pName[i].chSign == 'L')
		{
			intLNum++; 
		}
		else if (pName[i].chSign == 'E')
		{
			intWNum++; 
		}
		else if (pName[i].chSign == 'W' && chaLSName[i]== 0)
		{
			intWENum++; 
		}
		else if (pName[i].chSign == 'S')
		{
			intSNum++; 
		}
		else if (pName[i].chSign == 'N')
		{
			intNNum++;
		}
		else if (pName[i].chSign == 'Z')
		{
			intZNum++; 
		}
		else if (pName[i].chSign == 'K')
		{
			intKNum++; 
		}
		else {
			intFNum++; 
		}
	}
	intWNum = HuPai(chaLSName, intWNum);
	intTNum = HuPai(&chaLSName[intWNum], intTNum);
	intLNum = HuPai(&chaLSName[intWNum+ intTNum], intLNum);
	/*if (intWENum % 3 == 0)intWENum = 0;
	else if (intWENum % 3 == 2)intWENum == 1;
	else intWENum == 2;*/
	SURENU(intWENum)
	SURENU(intENum)
	SURENU(intNNum)
	SURENU(intSNum)
	SURENU(intZNum)
	SURENU(intKNum)
	SURENU(intFNum)
		if (intWNum + intTNum + intLNum + intENum + intWENum + intSNum + intNNum + intZNum + intKNum + intFNum == 1)
		{
			printf("玩家可以和牌,是否和牌？（摁Enter确定并结束游戏，其他键取消）");
			getchar();
			for (int i = 0; i < intCardNum; i++)
				printf("%d%c ", pName[i].inSerial, pName[i].chSign);
			printf("%d%c\n", TEMPORARCARDS.inSerial, TEMPORARCARDS.chSign);
			if (getchar() == 10)
				exit(1);
		}
}


int HuPai(char chaLSName[14], int intTem1)
{
	int intTem12=1;
	int  intnum[9] = {0,0};
	int intTem1MIN=0, intTem1MAX=3;
	for (int i = 0; i < intTem1; i++)
	{
		printf("%dv  ", chaLSName[i]);
	}
	for (int i = 0; i < intTem1; i++)
	{
		intnum[chaLSName[i]-1]++;
	}

	for (int i = 0; i < 9; i++)
	{
		if (intnum[i] == 0&& intnum[i+1]!=0)
		{
			intTem1MIN = i+1;
			break;
		}
	}
	for (int i = 8; i >0; i--)
	{
		if (intnum[i] == 0 && intnum[i -1] != 0)
		{
			intTem1MAX = i-1;
			break;
		}
	}
	if (intTem1MAX < 2)intTem1MAX = 2;
	if (intTem1MIN>7)intTem1MIN = 7;
	while (intTem12)
	{
		intTem12 = 0;
		for (int i = intTem1MIN;  i <=intTem1MAX;i++)
		{
			if (intnum[intTem1MIN] == 1)///////
			{
				intnum[intTem1MIN] -= 1, intnum[intTem1MIN + 1] -= 1, intnum[intTem1MIN + 2] -= 1, intTem12 = 1;
				
			}
			else if (intnum[intTem1MAX] == 1)///////
			{
				intnum[intTem1MAX - 1] -= 1, intnum[intTem1MAX] -= 1, intnum[intTem1MAX - 2] -= 1, intTem12 = 1;
			}
			else if (intnum[i] == 1)//////
				intnum[i] -= 1, intnum[i + 1] -= 1, intnum[i - 1] -= 1, intTem12 = 1;
		}
		if (intTem1MAX < 2)intTem1MAX = 2;
		if (intTem1MIN > 7)intTem1MIN = 7;
	}
	for (int i = 0; i<9; i ++)
	{
		if (intnum[i] < 0)return 2;
		if (intnum[i] == 3)intnum[i] = 0;
	}
	for (int i = 0;i<7;i++)
	{
		if ((intnum[i] == 2 && intnum[i + 1] == 2) && intnum[i + 2] == 2)
			intnum[i] = 0, intnum[i + 1] = 0, intnum[i + 2] = 0;
	}
	for (int i = 0; i < 9; i++)
	{
		intTem12 += intnum[i];
	}
	if (intTem12 > 2)return 2;
	else if (intTem12 == 2) return 1;
	else return 0;
}

