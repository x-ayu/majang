#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"masd.h"
void FaPi(SOUP namm[13],int as)
{
	for (int i = 0;i<=12; i++)
	{
		namm[i] = Distribute(as);
	//	if (i == 13)break;
	}
}

int main(void)
{
	int as[136];
	AloneRandom(136, as);
	 NAMES  WJ;
	WJ = _Interface();
	 SOUP pName1[14];
	 SOUP pName2[14];
	 SOUP pName3[14];
	 SOUP pName4[14];
	FaPi(pName1, as); FaPi(pName2, as); FaPi(pName3, as); FaPi(pName4, as); //为每个玩家发牌
	if (WJ.intMode == 1)
	{
		int intDetermine=52, intRecordPlayer=0 ,intPlay, intCardNum1=13,intCardNum2 = 13,intCardNum = 13,intCardNum1 = 13;
		SOUP TEMPORARCARDS;
		for (;;)
		{
			if (intDetermine == 136) break;
			TEMPORARCARDS = Distribute(as);
			if (intDetermine % 4 == 0)//待修改
			{
				intCardNum =Touch(pName1,TEMPORARCARDS, intCardNum);
				CuPai(pName1, 1, WJ.szPlayersName1, pName1);
			}
			if (intDetermine % 4 == 1)
			{
				intCardNum = Touch(pName2, TEMPORARCARDS, intCardNum);
				CuPai(pName2, 2, WJ.szPlayersName2, pName2);
			}
			if (intDetermine % 4 == 2)
			{
				intCardNum = Touch(pName3, TEMPORARCARDS, intCardNum);
				CuPai(pName3, 3, WJ.szPlayersName3, pName3);
			}
			if (intDetermine % 4 == 3)
			{
				intCardNum = Touch(pName4, TEMPORARCARDS, intCardNum);
				CuPai(pName4, 4, WJ.szPlayersName4, pName4);
			}
			intDetermine++;
			system("cls");
		}
	}
	return 0;
}
