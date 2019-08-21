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
int inX = 0;
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
		char szBarRecord[4][9] = { " "," "," "," " }, szQIRecord[270] = "  "; char chSort[14][3]; 
		SOUP TEMPORARCARDS = {'\040',' '};
		for (;;)
		{
			
			int intTouchReturnValue;
			if (inCcontrolPlay == 1)
			{
				TEMPORARCARDS = Distribute(as);
				pName1[13] = TEMPORARCARDS;
				for (int i = 0; i < 14; i++)
				{
					chSort[i][0] = pName1[i].inSerial + '0';
					chSort[i][1] = pName1[i].chSign;
					chSort[i][2] = '\0';
				}
				if (Touch(pName1, &TEMPORARCARDS, &intCardNum1, 1, WJ.szPlayersName1, WJ.szPlayersName2, pName3, WJ.szPlayersName3, pName4, WJ.szPlayersName4, szQIRecord, chSort, szBarRecord[0]) == 2)
				{
					GangRecord(szBarRecord[0], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
                }
				if (OWTouch(pName1, TEMPORARCARDS, &intCardNum1) == 1)
				{
					GangRecord(szBarRecord[0], TEMPORARCARDS);
					TEMPORARCARDS = Distribute(as);
				}
				PrintfCard1
				PrintfCard2
				PrintfCard3
				Sequence(pName1, NULL, 0, intCardNum1);
				HUDetermine(pName1, intCardNum1, TEMPORARCARDS, WJ.szPlayersName1);
				printf("所弃的的牌：\n%s\n", szQIRecord); printf("玩家%s杠的牌：%s\n", WJ.szPlayersName1, szBarRecord[0]);
				
				CuPai(pName1,1, intCardNum1, WJ.szPlayersName1, pName2, WJ.szPlayersName2, pName3, WJ.szPlayersName3, pName4, WJ.szPlayersName4, szQIRecord, chSort, szBarRecord[0]);
				PlayersPengDetermine2
				PlayersPengDetermine3
				PlayersPengDetermine4
					QIRecord(szQIRecord, TEMPORARCARDS);
			}
			if (inCcontrolPlay == 2)
			{
				TEMPORARCARDS = Distribute(as);
				if (Touch(pName2, &TEMPORARCARDS, &intCardNum2,1 , WJ.szPlayersName2 ,  WJ.szPlayersName1, pName3, WJ.szPlayersName3, pName4, WJ.szPlayersName4, szQIRecord, chSort, szBarRecord[1]) == 2)
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
				Sequence(pName2, NULL, 0, intCardNum2); pName2[13] = TEMPORARCARDS;
				printf("所弃的的牌：\n%s\n", szQIRecord); printf("玩家%s杠的牌：%s\n", WJ.szPlayersName2, szBarRecord[1]);
				HUDetermine(pName2, intCardNum2, TEMPORARCARDS, WJ.szPlayersName2);
				for (int i = 0; i < 14; i++)
				{
					chSort[i][0] = pName2[i].inSerial + '0';
					chSort[i][1] = pName2[i].chSign;
					chSort[i][2] = '\0';
				}
				CuPai(pName2, 2, intCardNum2, WJ.szPlayersName2, pName1, WJ.szPlayersName1, pName3, WJ.szPlayersName3, pName4, WJ.szPlayersName4, szQIRecord, chSort, szBarRecord[1]);
				PlayersPengDetermine1
				PlayersPengDetermine3
				PlayersPengDetermine4
					QIRecord(szQIRecord, TEMPORARCARDS);
					
			}
			if (inCcontrolPlay == 3)
			{
				TEMPORARCARDS = Distribute(as);
				if (Touch(pName3, &TEMPORARCARDS, &intCardNum3, 1, WJ.szPlayersName3, WJ.szPlayersName1, pName2, WJ.szPlayersName2, pName4, WJ.szPlayersName4, szQIRecord, chSort, szBarRecord[2]) == 2)
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
				Sequence(pName3, NULL, 0, intCardNum3); pName3[13] = TEMPORARCARDS;
				HUDetermine(pName3, intCardNum3, TEMPORARCARDS, WJ.szPlayersName3);
				printf("所弃的的牌：\n%s\n", szQIRecord); printf("玩家%s杠的牌：%s\n", WJ.szPlayersName3, szBarRecord[2]);
				for (int i = 0; i < 14; i++)
				{
					chSort[i][0] = pName3[i].inSerial + '0';
					chSort[i][1] = pName3[i].chSign;
					chSort[i][2] = '\0';
				}
				CuPai(pName3, 3, intCardNum3, WJ.szPlayersName3, pName1, WJ.szPlayersName1, pName2, WJ.szPlayersName2, pName4, WJ.szPlayersName4, szQIRecord, chSort, szBarRecord[2]);
				PlayersPengDetermine4
				PlayersPengDetermine1
				PlayersPengDetermine2
					QIRecord(szQIRecord, TEMPORARCARDS);
					
			}
			if (inCcontrolPlay == 4)
			{
				TEMPORARCARDS = Distribute(as);
				if (Touch(pName4, &TEMPORARCARDS, &intCardNum4, 1, WJ.szPlayersName4, WJ.szPlayersName1, pName2, WJ.szPlayersName2, pName3, WJ.szPlayersName3, szQIRecord, chSort, szBarRecord[3]) == 2)
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
				Sequence(pName4, NULL, 0, intCardNum4); pName4[13] = TEMPORARCARDS;
				HUDetermine(pName4, intCardNum4, TEMPORARCARDS, WJ.szPlayersName4);
				printf("所弃的的牌：\n%s\n", szQIRecord); printf("玩家%s杠的牌：%s\n", WJ.szPlayersName4, szBarRecord[3]);
				for (int i = 0; i < 14; i++)
				{
					chSort[i][0] = pName4[i].inSerial + '0';
					chSort[i][1] = pName4[i].chSign;
					chSort[i][2] = '\0';
				}
				CuPai(pName4, 4, intCardNum4, WJ.szPlayersName4, pName1, WJ.szPlayersName1, pName2, WJ.szPlayersName2, pName3, WJ.szPlayersName3, szQIRecord, chSort, szBarRecord[3]);
				PlayersPengDetermine1
				PlayersPengDetermine2
				PlayersPengDetermine3
					QIRecord(szQIRecord, TEMPORARCARDS);
				
			}
			++inCcontrolPlay > 4 ? (inCcontrolPlay = 1) : (inCcontrolPlay);
			system("cls");
		}
	}
	return 0;
}
