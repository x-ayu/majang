#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"masd.h"

int ChOutput(char* Output[],int intNumber, _Bool bWay, _Bool bMode, int intInitial, int intEnd)
{
	int intInput1, intInput = 0,  intOutput = 1;

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
				intInput1 = _getch();
				if (intInput1 == 13) break;
				intInput = _getch();
				if (intInput1 == 224) { if ((intInput == 75) || (intInput == 77))break; }
			}
			if (intInput1 == 13)break;
			if ((intInput == 77) && intOutput < intNumber)
			{
				intOutput++;
			}
			else if ((intInput == 75) && intOutput > 1) {
				intOutput--;
			}
			system("cls");
			for (int i = 0; i < intNumber; i++)
			{
				if (i == intOutput - 1)printf("%s    ", Output[i]);
				else printf("      ");
			}
			printf("\n");
			for (int i = 0; i < intNumber; i++)
			{
				if (i != intOutput - 1)printf("%s    ", Output[i]);
				else printf("      ");
			}printf("\n");
		}
	}
	if (bWay == 1) {//向右
		fprintf(stderr, "功能暂未实现，尽情期待");
		goto L_Err;
	}

	if (bMode == 1) {//指定位置向上
		for (int i = 0; i <= intEnd; i++) {
			(i < intInitial)? printf("      "): printf("%s    ", Output[i]);	
		}
		printf("\n");
		for (int i = 0; i <= intEnd; i++) {
			(i >= intInitial && i <= intEnd) ? printf("      ") : printf("%s    ", Output[i]);
		}
	}

L_Err:
	return intOutput;
}
