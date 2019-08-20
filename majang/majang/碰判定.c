#include"masd.h"
#include<stdio.h>
int Touch(SOUP* pCardGroup, SOUP *TEmporary,int *intCardNum)
{
	Sequence(pCardGroup,NULL,0, *intCardNum);
	int intLS=0,intLS1,intLS2, intKZ=-1;	
	int n = 1;//用于确定碰/杠位置
	char chSort[14][3];
	for (int i = 0; i < 13; i++)
	{
		chSort[i][0] = pCardGroup[i].inSerial+'0';
		chSort[i][1] = pCardGroup[i].chSign;
		chSort[i][2] = '\0';
	}
	chSort[13][0] = TEmporary->inSerial+'0'; chSort[13][1] = TEmporary->chSign; chSort[13][2] = '\0';
	for (int i = 0; i < *intCardNum; i++)
	{
		if (pCardGroup[i].chSign == TEmporary->chSign&& pCardGroup[i].inSerial==TEmporary->inSerial)
			intLS++; 
		if(n!=0)
		{
			if( intLS==1)
			{
				n = 0;
				intLS1 = i + 1;
			}

		}

	}
	if (intLS == 3)
	{
		SOUP LSCARD1, LSCARD2, LSCARD3;
		printf("玩家可以杠/碰牌，是否杠牌（1确认碰，0取消碰）\n");
		ChOutput(chSort, *intCardNum, 2, 1, intLS1 - 1, intLS1+1,"");
		for (;;)
		{
			intKZ = getchar() - '0';
			if (intKZ == 1 || intKZ == 0)break;
		}
		if (intKZ == 0)
		{
			intLS= 2;
		}
		if (intKZ == 1)//接下来几段用于交换碰/杠牌的位置和减少手牌数目
		{
			LSCARD1.chSign = pCardGroup[*intCardNum - 2].chSign; LSCARD1.inSerial = pCardGroup[*intCardNum - 2].inSerial;
			LSCARD2.chSign = pCardGroup[*intCardNum - 1].chSign; LSCARD2.inSerial = pCardGroup[*intCardNum - 1].inSerial;
			LSCARD3.chSign = pCardGroup[*intCardNum - 3].chSign; LSCARD3.inSerial = pCardGroup[*intCardNum - 3].inSerial;

			pCardGroup[*intCardNum - 1].inSerial = pCardGroup[intLS1].inSerial; pCardGroup[*intCardNum - 1].chSign = pCardGroup[intLS1].chSign;
			pCardGroup[*intCardNum - 2].inSerial = pCardGroup[intLS1 - 1].inSerial; pCardGroup[*intCardNum - 2].chSign = pCardGroup[intLS1 - 1].chSign;
			pCardGroup[*intCardNum - 3].inSerial = pCardGroup[intLS1 +1].inSerial; pCardGroup[*intCardNum - 3].chSign = pCardGroup[intLS1 +1].chSign;

			pCardGroup[intLS1].chSign = LSCARD1.chSign; pCardGroup[intLS1].inSerial = LSCARD2.inSerial;
			pCardGroup[intLS1 - 1].chSign = LSCARD2.chSign; pCardGroup[intLS1 - 1].inSerial = LSCARD1.inSerial;
			pCardGroup[intLS1 +1].chSign = LSCARD3.chSign; pCardGroup[intLS1 +1].inSerial = LSCARD3.inSerial;
			*intCardNum -= 3;
			Sequence(pCardGroup, NULL, 0, *intCardNum);
			return 2;
		}

	}
		if (intLS == 2)
		{
			SOUP LSCARD1,LSCARD2;
			printf("玩家可以碰牌，是否碰牌（1确认碰，0取消碰）\n");
			ChOutput(chSort, *intCardNum,2,1, intLS1-1, intLS1,"");
			for (;;)
			{
				intKZ = getchar() - '0';
				if (intKZ == 1 || intKZ == 0)break;
			}
			if (intKZ == 1)
			{
				LSCARD1.chSign = pCardGroup[*intCardNum - 2].chSign; LSCARD1.inSerial = pCardGroup[*intCardNum - 2].inSerial;
				LSCARD2.chSign = pCardGroup[*intCardNum - 1].chSign; LSCARD2.inSerial = pCardGroup[*intCardNum - 1].inSerial;

				pCardGroup[*intCardNum - 1].inSerial = pCardGroup[intLS1].inSerial; pCardGroup[*intCardNum - 1].chSign = pCardGroup[intLS1].chSign;
				pCardGroup[*intCardNum - 2].inSerial = pCardGroup[intLS1 - 1].inSerial; pCardGroup[*intCardNum - 2].chSign = pCardGroup[intLS1 - 1].chSign;

				pCardGroup[intLS1].chSign = LSCARD1.chSign; pCardGroup[intLS1].inSerial = LSCARD2.inSerial;
				pCardGroup[intLS1 - 1].chSign = LSCARD2.chSign; pCardGroup[intLS1 - 1].inSerial = LSCARD1.inSerial;
				*intCardNum -= 3;
				Sequence(pCardGroup, NULL, 0, *intCardNum+1);
				for (int i = 0; i < 13; i++)
				{
					chSort[i][0] = pCardGroup[i].inSerial + '0';
					chSort[i][1] = pCardGroup[i].chSign;
					chSort[i][2] = '\0';
				}
				chSort[13][0] = TEmporary->inSerial + '0'; chSort[13][1] = TEmporary->chSign; chSort[13][2] = '\0';
				intLS2 = ChOutput(chSort, *intCardNum+1, 0, 2, 0, 0, "");
				TEmporary->chSign = pCardGroup[intLS2 - 1].chSign; TEmporary->inSerial = pCardGroup[intLS2 - 1].inSerial;
				pCardGroup[intLS2 - 1].chSign = pCardGroup[*intCardNum ].chSign; pCardGroup[intLS2 - 1].inSerial = pCardGroup[*intCardNum ].inSerial;
				pCardGroup[*intCardNum].chSign = pCardGroup[*intCardNum+1 ].chSign; pCardGroup[*intCardNum ].inSerial = pCardGroup[*intCardNum +1].inSerial;
				Sequence(pCardGroup, NULL, 0, *intCardNum);
				system("cls");
			}
			return 1;
		}
		return 0;
}




int OWTouch(SOUP* pCardGroup, SOUP TEmporary ,int *intCardNum)//加杠
{
	int intLS =0, intLS1, intKZ=2;
	int n = 1;//用于确定碰/杠位置
	char chSort[14][3];
	for (int i = 0; i < 13; i++)
	{
		chSort[i][0] = pCardGroup[i].inSerial + '0';
		chSort[i][1] = pCardGroup[i].chSign;
		chSort[i][2] = '\0';
	}
	chSort[13][0] = TEmporary.inSerial + '0'; chSort[13][1] = TEmporary.chSign; chSort[13][2] = '\0';/////////////////////////
	for (int i = 0; i < *intCardNum - 3; i++)
	{
		if (pCardGroup[i].chSign == pCardGroup[i + 1].chSign && pCardGroup[i].chSign == pCardGroup[i + 2].chSign && pCardGroup[i].chSign == pCardGroup[i + 3].chSign && \
			pCardGroup[i].inSerial == pCardGroup[i + 1].inSerial && pCardGroup[i].inSerial == pCardGroup[i + 3].inSerial && pCardGroup[i].inSerial == pCardGroup[i + 2].inSerial)
		{
			printf("玩家可以自杠牌，是否杠牌（1确认，0取消）\n");
			ChOutput(chSort, 14, i, 1, i, i + 3, "");
			for (;;)
			{
				intKZ = getchar() - '0';
				if (intKZ == 1 || intKZ == 0)break;
			}
			if (intKZ == 1)
			{
				pCardGroup[i + 3].inSerial = pCardGroup[*intCardNum - 3].inSerial; pCardGroup[i + 3].chSign = pCardGroup[*intCardNum - 3].chSign;
				pCardGroup[i + 2].inSerial = pCardGroup[*intCardNum - 1].inSerial; pCardGroup[i + 2].chSign = pCardGroup[*intCardNum - 1].chSign;
				pCardGroup[i + 1].inSerial = pCardGroup[*intCardNum - 2].inSerial; pCardGroup[i + 1].chSign = pCardGroup[*intCardNum - 2].chSign;
				pCardGroup[*intCardNum - 1].inSerial = pCardGroup[i].inSerial; pCardGroup[*intCardNum - 1].chSign = pCardGroup[i].chSign;
				pCardGroup[*intCardNum - 2].inSerial = pCardGroup[i].inSerial; pCardGroup[*intCardNum - 2].chSign = pCardGroup[i].chSign;
				pCardGroup[*intCardNum - 3].inSerial = pCardGroup[i].inSerial; pCardGroup[*intCardNum - 3].chSign = pCardGroup[i].chSign;
				pCardGroup[i].inSerial = TEmporary.inSerial; pCardGroup[i].chSign = TEmporary.chSign; break;
			}
		}
	}
	for (int i = 0; i < 13; i++)
	{
		if (pCardGroup[i].chSign == TEmporary.chSign && pCardGroup[i].inSerial == TEmporary.inSerial)
			intLS++;
		if (n != 0)
		{
			if (intLS == 1)
			{
				n = 0;
				intLS1 = i + 1;
			}
		}
	}
	
	if (intLS == 3)
	{
		printf("玩家可以加杠牌，是否杠牌（1确认，0取消）\n");
		ChOutput(chSort, 14, 2, 1, intLS1 - 1, intLS1 + 1,"");
		for (;;)
		{
			intKZ = getchar() - '0';
			if (intKZ == 1 || intKZ == 0)break;
		}
	}
		return intKZ;
}