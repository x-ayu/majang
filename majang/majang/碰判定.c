#include"masd.h"
#include<stdio.h>
int Touch(SOUP* pCardGroup, SOUP *TEmporary,int *intCardNum,int intZG)
{
	Sequence(pCardGroup,NULL,0, *intCardNum);
	int intLS=0,intLS1,intLS2, intKZ;	
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
	if (intLS == 3&& intZG !=1)
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
		if (intKZ == 1)
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
			return 2;
		}

	}
		if (intLS == 2&&intZG != 1)
		{
			SOUP LSCARD1,LSCARD2, LSCARD3;
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
				*intCardNum -= 2;
				for (int i = 0; i < 13; i++)
				{
					chSort[i][0] = pCardGroup[i].inSerial + '0';
					chSort[i][1] = pCardGroup[i].chSign;
					chSort[i][2] = '\0';
				}
				chSort[13][0] = TEmporary->inSerial + '0'; chSort[13][1] = TEmporary->chSign; chSort[13][2] = '\0';
				intLS2 = ChOutput(chSort, *intCardNum, 0, 0, 0, 0, "");
				TEmporary->chSign = pCardGroup[intLS2 - 1].chSign; TEmporary->inSerial = pCardGroup[intLS2 - 1].inSerial;
				pCardGroup[intLS2 - 1].chSign = pCardGroup[*intCardNum -1].chSign; pCardGroup[intLS2 - 1].inSerial = pCardGroup[*intCardNum -1].inSerial;
				pCardGroup[*intCardNum - 1].chSign = pCardGroup[*intCardNum ].chSign; pCardGroup[*intCardNum - 1].inSerial = pCardGroup[*intCardNum ].inSerial;
				(*intCardNum )--;
			}
			return 1;
		}
		return 0;
}
int OWTouch(SOUP* pCardGroup, SOUP TEmporary)//加杠
{
	int intLS =0, intLS1, intKZ;
	int n = 1;//用于确定碰/杠位置
	char chSort[14][3];
	for (int i = 0; i < 13; i++)
	{
		chSort[i][0] = pCardGroup[i].inSerial + '0';
		chSort[i][1] = pCardGroup[i].chSign;
		chSort[i][2] = '\0';
	}
	chSort[13][0] = TEmporary.inSerial + '0'; chSort[13][1] = TEmporary.chSign; chSort[13][2] = '\0';
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
		printf("玩家可以杠牌，是否杠牌（1确认，0取消）\n");
		ChOutput(chSort, 14, 2, 1, intLS1 - 1, intLS1 + 1,"");
		for (;;)
		{
			intKZ = getchar() - '0';
			if (intKZ == 1 || intKZ == 0)break;
		}
	}
		return intKZ;
}