#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"masd.h"
#include <ctype.h>
int  FaPi(struct Soup namm[13],int as)
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
	struct names  WJ;
	WJ = _Interface();
	struct Soup name1[13];
	struct Soup name2[13];
	struct Soup name3[13];
	struct Soup name4[13];
	FaPi(name1,as); printf("\n");
	FaPi(name2,as); printf("\n");
	FaPi(name3,as); printf("\n");
	FaPi(name4,as); printf("\n");
}
