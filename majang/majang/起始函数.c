#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"masd.h"
void FaPi(SOUP namm[13], int as)
{
	for (int i = 0; i <= 12; i++)
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
		int intRecordPlayer = 0, intPlay, intCardNum1 = 13, intCardNum2 = 13, intCardNum3 = 13, intCardNum4 = 13;
		int inCcontrolPlay = 1;
		char szBarRecord[4][9] = {" "," "," "," "};
		SOUP TEMPORARCARDS;
		for (;;)
		{
			
			int intTouchReturnValue;
			TEMPORARCARDS = Distribute(as);
			if (inCcontrolPlay == 1)
			{
				if (Touch(pName1, &TEMPORARCARDS, &intCardNum1, 1) == 2)
				{
					GangRecord(szBarRecord[0], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
                }
				if (OWTouch(pName1, TEMPORARCARDS, &intCardNum1) == 1)
				{
					GangRecord(szBarRecord[0], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
				}
				PrintfCard2
				PrintfCard3
				PrintfCard4
				Sequence(pName1, NULL, 0, intCardNum1);
				printf("玩家%s杠的牌：%s\n", WJ.szPlayersName1, szBarRecord[0]);
				HUDetermine(pName1, intCardNum1, TEMPORARCARDS);
				CuPai(pName1,1, intCardNum1, WJ.szPlayersName1, pName1); 
				PlayersPengDetermine2
				PlayersPengDetermine3
				PlayersPengDetermine4
			}
			if (inCcontrolPlay == 2)
			{
				if (Touch(pName2, &TEMPORARCARDS, &intCardNum2, 1) == 2)
				{
					GangRecord(szBarRecord[1], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
				}
				if (OWTouch(pName2, TEMPORARCARDS, &intCardNum2) == 1)
				{
					GangRecord(szBarRecord[1], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
				}
				PrintfCard1
				PrintfCard3
				PrintfCard4
				printf("玩家%s杠的牌：%s\n",WJ.szPlayersName2 ,szBarRecord[1]);
				Sequence(pName2, NULL, 0, intCardNum2);
				HUDetermine(pName2, intCardNum2, TEMPORARCARDS);
				CuPai(pName2,2, intCardNum2 , WJ.szPlayersName2, pName2);
				PlayersPengDetermine1
				PlayersPengDetermine3
				PlayersPengDetermine4
					
			}
			if (inCcontrolPlay == 3)
			{
				if (Touch(pName3, &TEMPORARCARDS, &intCardNum3, 1) == 2)
				{
					GangRecord(szBarRecord[2], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
				}
				if (OWTouch(pName3, TEMPORARCARDS, &intCardNum3) == 1)
				{
					GangRecord(szBarRecord[2], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
				}
				PrintfCard1
				PrintfCard2
				PrintfCard4
				printf("玩家%s杠的牌：%s\n",WJ.szPlayersName3,szBarRecord[2]);
				Sequence(pName3, NULL, 0, intCardNum3);
				HUDetermine(pName3, intCardNum3, TEMPORARCARDS);
				CuPai(pName3,3, intCardNum3, WJ.szPlayersName3, pName3);
				PlayersPengDetermine4
				PlayersPengDetermine1
				PlayersPengDetermine2
					
			}
			if (inCcontrolPlay == 4)
			{
				if (Touch(pName4, &TEMPORARCARDS, &intCardNum4, 1) == 2)
				{
					GangRecord(szBarRecord[3], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
				}
				if (OWTouch(pName4, TEMPORARCARDS, &intCardNum4) == 1)
				{
					GangRecord(szBarRecord[3], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
				}
				PrintfCard1
				PrintfCard2
				PrintfCard3
				printf("玩家%s杠的牌：%s\n",WJ.szPlayersName4,szBarRecord[3]);
				Sequence(pName4, NULL, 0, intCardNum4);
				HUDetermine(pName4, intCardNum4, TEMPORARCARDS);
				CuPai(pName4,4, intCardNum4,  WJ.szPlayersName4, pName4);
				PlayersPengDetermine1
				PlayersPengDetermine2
				PlayersPengDetermine3
				
			}
			++inCcontrolPlay > 4 ? (inCcontrolPlay = 1) : (inCcontrolPlay);
			system("cls");
		}
	}
	return 0;
}
