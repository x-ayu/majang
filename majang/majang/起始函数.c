#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"masd.h"
#include <ctype.h>
int  FaPi(struct SOUP namm[13],int as)
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
	AloneRandom(136,as);
	struct NAMES  WJ;
	WJ = _Interface();
	struct SOUP pName1[13];
	struct SOUP pName2[13];
	struct SOUP pName3[13];
	struct SOUP pName4[13];
	FaPi(pName1,as); printf("\n");
	FaPi(pName2,as); printf("\n");
	FaPi(pName3,as); printf("\n");
	FaPi(pName4,as); printf("\n");
}
