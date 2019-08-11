#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"masd.h"

int ChOutput(char* Output[],int intNumber, _Bool bWay, _Bool bMode, int intInitial, int intEnd)
{
	int Input1, Input2 = 0,  Output2 = 1;
	if (bWay == 0)//向上；
	{
		for (int i = 0; i < intNumber; i++)
		{
			if(i==0) printf("%s    \n", Output[i]);
		}
		for (int i = 0; i < intNumber; i++)
		{
			if (i == 0) printf("      ");
			if (i != 0) printf("%s    ", Output[i]);
		}
		printf("\n");
		for (;;)
		{
			for (;;)
			{
				Input1 = _getch();
				if (Input1 == 13) break;
				Input2 = _getch();
				if (Input1 == 224) { if ((Input2 == 75) || (Input2 == 77))break; }
			}
			if (Input1 == 13)break;
			if ((Input2 == 77) && Output2 < intNumber)
			{
				Output2++;
			}
			else if ((Input2 == 75) && Output2 > 1) {
				Output2--;
			}
			system("cls");
			for (int i = 0; i < intNumber; i++)
			{
				if (i == Output2 - 1)printf("%s    ", Output[i]);
				else printf("      ");
			}
			printf("\n");
			for (int i = 0; i < intNumber; i++)
			{
				if (i != Output2 - 1)printf("%s    ", Output[i]);
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
		for (int i = 0; i <= intEnd; i++) {
			if (i >= intInitial && i <= intEnd)printf("      ");
			else printf("%s    ", Output[i]);
		}
	}
	return Output2;
}
