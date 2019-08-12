#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"masd.h"
#include <ctype.h>

int  FaPi(SOUP namm[13],int as)
{
	for (int i = 0;; i++)
	{
		namm[i] = Distribute(as);
		if (i == 12)break;
		printf(" %d%c", namm[i].inSerial, namm[i].chSign);
	}
}

int main(void)
{
	int as[136];
	NAMES  WJ;
	SOUP pName1[13];
	SOUP pName2[13];
	SOUP pName3[13];
	SOUP pName4[13];

	AloneRandom(136,as);
	WJ = _Interface();

	FaPi(pName1,as); printf("\n");
	FaPi(pName2,as); printf("\n");
	FaPi(pName3,as); printf("\n");
	FaPi(pName4,as); printf("\n");

	return 0;
}
