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
	FaPi(pName1, as); FaPi(pName2, as); FaPi(pName3, as); FaPi(pName4, as); //Ϊÿ����ҷ���
	if (WJ.intMode == 1)
	{
		int intRecordPlayer = 0, intPlay, intCardNum1 = 13, intCardNum2 = 13, intCardNum3 = 13, intCardNum4 = 13;
		int inCcontrolPlay = 1;
		char szBarRecord[4][9];
		SOUP TEMPORARCARDS;
		for (;;)
		{
			int intTouchReturnValue;
			TEMPORARCARDS = Distribute(as);
			if (inCcontrolPlay == 1)//���޸�
			{
				OWTouch(pName1, TEMPORARCARDS);
				if (Touch(pName1, &TEMPORARCARDS, &intCardNum1, 1) == 1)
				{
				TEMPORARCARDS = Distribute(as);
                }
				CuPai(pName1,1, intCardNum1, WJ.szPlayersName1, pName1);
				PlayersPengDetermine2
				PlayersPengDetermine3
				PlayersPengDetermine4

				/*if (Touch(pName2, &TEMPORARCARDS, &intCardNum2) >0)
				{
					if (Touch(pName2, &TEMPORARCARDS, &intCardNum2) == 2)
					{
						inCcontrolPlay = 2;
						continue;
					}
					else 
					{ inCcontrolPlay = 3; continue;}
				}
				//
				if (Touch(pName3, &TEMPORARCARDS, &intCardNum3) > 0)
				{
					if (Touch(pName3, &TEMPORARCARDS, &intCardNum3) == 2)
					{
						inCcontrolPlay = 3;
						continue;
					}
					else{ inCcontrolPlay = 4; continue; }
				}
				//
				if (Touch(pName4, &TEMPORARCARDS, &intCardNum4) > 0)
				{
					if (Touch(pName4, &TEMPORARCARDS, &intCardNum4) == 2)
					{
						inCcontrolPlay = 4;
						continue;
					}
					else { inCcontrolPlay = 1; continue; }
				}*/

			}
			if (inCcontrolPlay == 2)
			{
				OWTouch(pName2, TEMPORARCARDS);
				if (Touch(pName2, &TEMPORARCARDS, &intCardNum2, 1) == 1)
				{
					TEMPORARCARDS = Distribute(as);
				}
				CuPai(pName2,2, intCardNum2 , WJ.szPlayersName2, pName2);
				PlayersPengDetermine1
				PlayersPengDetermine3
				PlayersPengDetermine4
			}
			if (inCcontrolPlay == 3)
			{
				OWTouch(pName3, TEMPORARCARDS);
				if (Touch(pName3, &TEMPORARCARDS, &intCardNum3, 1) == 1)
				{
					TEMPORARCARDS = Distribute(as);
				}
				CuPai(pName3,3, intCardNum3, WJ.szPlayersName3, pName3);
				PlayersPengDetermine4
				PlayersPengDetermine1
				PlayersPengDetermine2
			}
			if (inCcontrolPlay == 4)
			{
				if (Touch(pName4, &TEMPORARCARDS, &intCardNum4, 1) == 1)
				{
					TEMPORARCARDS = Distribute(as);
				}
				OWTouch(pName4, TEMPORARCARDS);
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
