#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include"masd.h"

int ChOutput(char Output[14][3],int intNumber, int bWay, int bMode, int intInitial, int intEnd,char *pGameSerial,SOUP Output1[13], char* pGameSeria2, SOUP Output2[13], char* pGameSeria3, SOUP Output3[13], char* pGameSeria4,char*szQI)
{
	int intInput1, intInput = 0,  intOutput = 1;
	if (bWay == 0)//向上；
	{
		for (int i = 0; i < 14; i++)
		{
			if(i==0) printf("%s    \n", Output[i]);
		}
		for (int i = 0; i < 14; i++)
		{
			if (i == 0) printf("      ");
			if (i == intNumber)printf("   ");
			if (i != 0) printf("%s    ", Output[i]);
		}
		printf("\n");
		for (;;)
		{
			for (;;)
			{
				intInput1 = _getch();
				if (intInput1 == 13) break;
				intInput = _getch();
				if (intInput1 == 224) { if ((intInput == 75) || (intInput == 77))break; }
			}
			if (intInput1 == 13)break;
			if ((intInput == 77) && intOutput == intNumber && bMode != 2)/////
				intOutput = 14;
			else if (intInput == 77 && intOutput == 14 && bMode != 2)//////
			{
				intOutput = 1;
			}
			
			else if ((intInput == 75) && intOutput == 14 && bMode != 2)/////
				intOutput = intNumber;
			else if ((intInput == 77) && intOutput < intNumber)//////
			{
				intOutput++;
			}
			
			 else if ((intInput == 75) && intOutput > 1) {//////
				intOutput--;
			}
			 else if ((intInput == 75) && intOutput == 1 && bMode != 2) {//////
				intOutput = 14 ;
			}
			system("cls");
			if (pGameSerial != NULL)
			{
				if (bMode != 2)
				{
					printf("玩家%s手牌:", pGameSeria2);
					for (int i = 0; i < 13; i++)
						printf("%d%c ", Output1[i].inSerial, Output1[i].chSign);
					printf("\n");
					printf("玩家%s手牌:", pGameSeria3);
					for (int i = 0; i < 13; i++)
						printf("%d%c ", Output2[i].inSerial, Output2[i].chSign);
					printf("\n");
					printf("玩家%s手牌:", pGameSeria4);
					for (int i = 0; i < 13; i++)
						printf("%d%c ", Output3[i].inSerial, Output3[i].chSign);
					printf("\n");
					printf("所弃的的牌：\n%s\n", szQI);
				}
				printf("玩家%s出牌\n", pGameSerial);
			}
			for (int i = 0; i <14; i++)
			{
				if (i == 13)printf("   ");
				if (i == intOutput - 1)printf("%s    ", Output[i]);
				else printf("      ");
			}
			printf("\n");
			for (int i = 0; i < 14; i++)
			{
				if (i == intNumber)printf("   ");
				if (i != intOutput - 1)printf("%s    ", Output[i]);
				else printf("      ");
			}printf("\n");
		}
}
	if (bWay == 1) {//向右
	}
	if (bMode == 1) {//指定位置向上
		for (int i = 0; i <= intEnd; i++) {
			if (i < intInitial)printf("      ");
			else printf("%s    ", Output[i]);
		}
		printf("\n");
		for (int i = 0; i < 14; i++) {
			if(i== intNumber)printf("   ");
			if (i >= intInitial && i <= intEnd)printf("      ");
			else printf("%s    ", Output[i]);
		}
	}
	return intOutput;
}
