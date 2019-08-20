#include"masd.h"
#include<stdlib.h>
#include<stdio.h>

#define SURENU(X) if (X % 3 == 0)X = 0;else if (X % 3 == 2)X = 1;else X = 2;
#define QUHU {printf("玩家可以和牌,是否和牌？（摁Enter确定并结束游戏，其他键取消）\n");getchar();for (int i = 0; i < 13; i++)printf("%d%c ", pName0[i].inSerial, pName[i].chSign);\
printf("%d%c\n", TEMPORARCARDS.inSerial, TEMPORARCARDS.chSign);if (getchar() == 10)exit(1);}
int HuPai(char *, int );

void HUDetermine(SOUP* pName, int intCardNum, SOUP TEMPORARCARDS)
{
	char chaLSName[14];
	SOUP pName0[14];
	int intWNum=0, intTNum=0, intLNum=0, intENum=0, intWENum=0, intSNum=0, intNNum=0, intZNum=0, intKNum=0, intFNum=0;//记录每种牌的出现次数，并作为判定胡牌的数据
	int intWNum0 = 0, intTNum0 = 0;
	for (int i = 0; i < intCardNum; i++)
		{
			pName0[i] = pName[i];
		}
	pName0[intCardNum] = TEMPORARCARDS;
	Sequence(pName0, NULL, 0, ++intCardNum);
	for (int i = 0; i < intCardNum; i++)
	{
		chaLSName[i] = pName0[i].inSerial;
	}
	for (int i = 0; i < intCardNum; i++)
	{
		if (pName0[i].chSign == 'W' && chaLSName[i] != 0)
		{
			intWNum++; 
		}
		 if (pName0[i].chSign == 'T')
		{
			intTNum++; 
		}
		 if (pName0[i].chSign == 'L')
		{
			intLNum++; 
		}
		 if (pName0[i].chSign == 'E')
		{
			intENum++; 
		}
		 if (pName0[i].chSign == 'W' && chaLSName[i]== 0)
		{
			intWENum++; 
		}
		 if (pName0[i].chSign == 'S')
		{
			intSNum++; 
		}
		 if (pName0[i].chSign == 'N')
		 {
			 intNNum++;
		 }
		 if (pName0[i].chSign == 'Z')
		{
			intZNum++; 
		}
		 if (pName0[i].chSign == 'K')
		{
			intKNum++; 
		}
		 if (pName0[i].chSign == 'F')
		 {
			 intFNum++;
		 }
	}
	intWNum0 = HuPai(chaLSName, intWNum); 
	intTNum0 = HuPai(&chaLSName[intWNum], intTNum); 
	intLNum = HuPai(&chaLSName[intWNum+intTNum], intLNum);
		if (intCardNum == 14)//判定七对子
		{
			if (pName0[0].chSign == pName0[1].chSign && pName0[2].chSign == pName0[3].chSign && pName0[4].chSign == pName0[5].chSign && pName0[6].chSign == pName0[7].chSign && \
				pName0[8].chSign == pName0[9].chSign && pName0[10].chSign == pName0[11].chSign && pName0[12].chSign == pName0[13].chSign)
			{
				if(pName0[0].inSerial== pName0[1].inSerial&& pName0[2].inSerial== pName0[3].inSerial&& pName0[4].inSerial== pName0[5].inSerial&& pName0[6].inSerial== pName0[7].inSerial
					&& pName0[8].inSerial== pName0[9].inSerial&& pName0[10].inSerial== pName0[11].inSerial&& pName0[12].inSerial== pName0[13].inSerial)
					QUHU
			}
		}
		if (intCardNum == 14)//判定国士无双
		{
			if ((intFNum == 1 || intFNum == 2) && (intKNum == 0 || intKNum == 2) && (intKNum == 1 || intKNum == 2) && (intZNum == 1 || intZNum == 2) && (intNNum == 1 || intNNum == 2)\
				&& (intSNum == 1 || intSNum == 2) && (intENum == 1 || intENum == 2) && (intWENum == 1 || intWENum == 2))
			{
				if (intFNum + intZNum + intKNum + intNNum + intSNum + intENum + intWENum == 7)
				{
					if (pName0[0].inSerial == 1 && pName0[intWNum-1].inSerial == 9 && pName0[intWNum].inSerial == 1 && pName0[intWNum+ intTNum-1].inSerial == 9 && \
						pName0[intWNum + intTNum+ intLNum-1].inSerial == 1 && pName0[5].inSerial == 9)
						QUHU
				}
				else  if (intFNum + intZNum + intKNum + intNNum + intSNum + intENum + intWENum == 8)
				{
					if(pName0[0].inSerial==1&& pName0[1].inSerial == 9&& pName0[2].inSerial == 1&& pName0[3].inSerial == 9&& pName0[4].inSerial == 1&& pName0[5].inSerial == 9)
						QUHU
				}
			}
		}

		SURENU(intWENum)
		SURENU(intENum)
		SURENU(intNNum)
		SURENU(intSNum)
		SURENU(intZNum)
		SURENU(intKNum)
		SURENU(intFNum)
		if (intWNum0 + intTNum0 + intLNum + intENum + intWENum + intSNum + intNNum + intZNum + intKNum + intFNum == 1)
			QUHU
}

int HuPai(char *chaLSName, int intTem1)//最终剩余2张相同牌时返回1，没有剩余牌时返回0，其余结果返回2
{
	int intTem12=1;
	int  intnum[10] = {0,0};
	int intTem1MIN=0, intTem1MAX=3;
	for (int i = 0; i < intTem1; i++)
	{
		intnum[chaLSName[i]]++;
	}

	for (int i = 1; i < 10; i++)
	{
		if (intnum[i] == 0&& intnum[i+1]!=0)
		{
			intTem1MIN = i+1;
			break;
		}
	}
	for (int i = 9; i >0; i--)
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
			if(i== intTem1MIN||i== intTem1MIN+1||i== intTem1MAX||i== intTem1MAX-1)
			{
				if (intnum[intTem1MIN] == 1)///////
					{
				intnum[intTem1MIN] -= 1, intnum[intTem1MIN + 1] -= 1, intnum[intTem1MIN + 2] -= 1, intTem12 = 1;
					}
			else if (intnum[intTem1MAX] == 1)///////
				{
					intnum[intTem1MAX - 1] -= 1, intnum[intTem1MAX] -= 1, intnum[intTem1MAX - 2] -= 1, intTem12 = 1;
				}
			else if (intnum[intTem1MIN + 1] == 1)//////
			{
				if (intnum[intTem1MIN] == 0)
				{
					intnum[intTem1MIN + 1] -= 1, intnum[intTem1MIN + 3] -= 1, intnum[intTem1MIN + 2] -= 1, intTem12 = 1;
				}
				else if (intnum[intTem1MIN + 2] == 0)return 2;
				else intnum[intTem1MIN + 1] -= 1, intnum[intTem1MIN] -= 1, intnum[intTem1MIN + 2] -= 1, intTem12 = 1;
			}
			else if (intnum[intTem1MAX - 1] == 1)//////
			{
				if (intnum[intTem1MAX] == 0)
				{
					intnum[intTem1MAX - 1] -= 1, intnum[intTem1MAX - 3] -= 1, intnum[intTem1MAX - 2] -= 1, intTem12 = 1;
				}
				else if (intnum[intTem1MAX + 2] == 0)return 2;
				else intnum[intTem1MAX - 1] -= 1, intnum[intTem1MAX] -= 1, intnum[intTem1MAX - 2] -= 1, intTem12 = 1;
			}
			}
			else if (intnum[i] == 1)//////
			{
				if (intnum[i - 1] == 0)intnum[i] -= 1, intnum[i + 1] -= 1, intnum[i + 2] -= 1;
				else if (intnum[i + 1] == 0)intnum[i] -= 1, intnum[i + 1] -= 1,  intnum[i - 2] -= 1;
				else intnum[i] -= 1, intnum[i + 1] -= 1, intnum[i + 1] -= 1 ;
			}
		}
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

