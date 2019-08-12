#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int* AloneRandom(int  number, int* Target)
{
	srand(clock());
	int intNum1, intNum2=0,intNum3=0;
	int * pNumb1;
	pNumb1 = (int*)malloc(sizeof(int)*number);
	if (pNumb1 == NULL)
	{
		exit(1);
	}
	for (size_t i = 0; i < number; i++)
	{
		*(pNumb1 + i) = 1;
	}
	for(int fg=0;;fg++)
	{
		if (number == 0)
		{
			intNum1 = 1;
			number--;
		}
		else
		{
			intNum1 = rand() % number + 1;
			number--;
		};
		if (number == -1)break;
		for (;;) {
				intNum2 += pNumb1[intNum3];
				intNum3++;
			if (intNum1 == intNum2) {
				Target[fg] = intNum3 - 1;
				pNumb1[--intNum3] = 0;
				intNum2 = 0;
				intNum3 = 0;
				break;
			}
		}
	}
	free(pNumb1);
	return*Target;

}