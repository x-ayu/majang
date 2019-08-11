#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int* AloneRandom(int  number, int* Target)
{
	int num1, num2=0,num3=0;
	int * numb1;
	numb1 = (int*)malloc(sizeof(int)*number);
	if (numb1 == NULL)
	{
		exit(1);
	}
	for (size_t i = 0; i < number-1; i++)
	{
		*(Target + i) = 1;
	}
	srand(clock());
	while (1)
	{
		static int fg = 0;
		
		srand(clock());
		if (number == 0)
		{
			num1 = 0;
			number--;
		}
		else
		{
			num1 = rand() / number + 1;
			number--;
		};
		while (1)
		{
			num2 =num2+  (*(numb1 + num3));//ÄÚ´æ·ÃÎÊ´íÎó
			num3++;
			if (num2==num1)
			{
				*(Target+fg) = num3;
				*(numb1 + num3) = 0;
				num3 = 0;
				
				puts("ssaas"); break;
			}
			if (num2 == num1)break;
		}
		fg++;
		if (number == -1)	break;
	}
	return*Target
		;
}