#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int* AloneRandom(int  number, int* Target)
{
	srand(clock());
	int num1, num2=0,num3=0;
	int * numb1;
	numb1 = (int*)malloc(sizeof(int)*number);
	if (numb1 == NULL)
	{
		exit(1);
	}
	for (size_t i = 0; i < number; i++)
	{
		*(numb1 + i) = 1;
	}
	while(1)//不能确定fg的大小，不用for
	{
		static int fg = 0;
		if (number == 0)
		{
			num1 = 1;
			number--;
		}
		else
		{
			num1 = rand() % number + 1;
			number--;
		};
		if (number == -1)break;
		for (;;) {
				num2 += numb1[num3];
				num3++;
			if (num1 == num2) {
				Target[fg] = num3 - 1;
				numb1[--num3] = 0;
				num2 = 0;
				num3 = 0;
				break;
			}
		}
		printf("%d ", Target[fg]);
		fg++;
		free(numb1);
	}
	return*Target;

}