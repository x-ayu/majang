#include<stdlib.h>
#include<stdio.h>
#include"masd.h"
int Compare(const void* p1, const void* p2)//用于qsort函数
{
	const int* p01 = (const int*)p1;
	const int* p02 = (const int*)p2;
	if (*p01 > * p02)
		return 1;
	else if (*p01 == *p02)
		return 0;
	else
		return -1;
}
int Sequence( SOUP *pName,char* pGameSerial,int NNN, int intCardNum)
{
	int (*ph)(const void* , const void* );
	ph = Compare;
	char chSort[14][3];
	int inTemporary = 0;
	int intWNum = 0, intTNum = 0, intLNum = 0;
	int szintNum[14];
	for (int i=0; i < 14; i++)
	{
		chSort[i][0] = pName[i].inSerial;
		chSort[i][1] = pName[i].chSign;
		chSort[i][2] = '\0';
	}		//28~134先按w.t.l第一次分类，不排列数字顺序
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'W'&& chSort[i][0]!=0)
			{
				intWNum++;
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++;
			}
		}
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'T')
			{
				intTNum++;
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++; 
			}
			if (inTemporary == intCardNum)break;
		}
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'L')
			{
				intLNum++;
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++;
			}
			if (inTemporary == intCardNum)break;
		}
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'E')
			{
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++;
			}
			if (inTemporary == 13)break;
		}
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'W'&& chSort[i][0] == 0)
			{
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++;
			}
			if (inTemporary == intCardNum)break;
		}
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'S')
			{
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++;
			}
			if (inTemporary == intCardNum)break;
		}
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'N')
			{
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++;
			}
			if (inTemporary == intCardNum)break;
		}
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'Z')
			{
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++;
			}
			if (inTemporary == intCardNum)break;
		}
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'K')
			{
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++;
			}
			if (inTemporary == intCardNum)break;
		}
		for (int i = 0; i < intCardNum; i++)
		{
			if (chSort[i][1] == 'F')
			{
				pName[inTemporary].inSerial = chSort[i][0];
				pName[inTemporary].chSign = chSort[i][1];
				inTemporary++;
			}
			if (inTemporary == intCardNum)break;
		}
		for (int i = 0; i < 14; i++)
		{
			chSort[i][0] = pName[i].inSerial;
			chSort[i][1] = pName[i].chSign;
		}
		for (int i = 0; i < 14; i++)
		{
			szintNum[i] = chSort[i][0];
		}
		qsort(szintNum, intWNum, sizeof(int), ph);
		qsort(&szintNum[intWNum], intTNum, sizeof(int), ph);
		qsort(&szintNum[intWNum+intTNum], intLNum, sizeof(int), ph);
		
		{
			for (int i = 0; i < 14; i++)
		{
			pName[i].inSerial = szintNum[i];
			chSort[i][0] = pName[i].inSerial + '0';
		}
		if (NNN != 0)
			ChOutput(chSort, intCardNum, 0, 0, 0, 0, pGameSerial);//确定出牌
		}
}